#include "LocalReduction.h"

#include <spdlog/spdlog.h>

#include "clang/Lex/Lexer.h"

#include "FileManager.h"
#include "OptionManager.h"
#include "Profiler.h"
#include "SourceManager.h"

using BinaryOperator = clang::BinaryOperator;
using BreakStmt = clang::BreakStmt;
using CallExpr = clang::CallExpr;
using ContinueStmt = clang::ContinueStmt;
using CompoundStmt = clang::CompoundStmt;
using DeclGroupRef = clang::DeclGroupRef;
using DeclStmt = clang::DeclStmt;
using FunctionDecl = clang::FunctionDecl;
using GotoStmt = clang::GotoStmt;
using IfStmt = clang::IfStmt;
using LabelStmt = clang::LabelStmt;
using ReturnStmt = clang::ReturnStmt;
using SourceRange = clang::SourceRange;
using SourceLocation = clang::SourceLocation;
using Stmt = clang::Stmt;
using UnaryOperator = clang::UnaryOperator;
using WhileStmt = clang::WhileStmt;
using VarDecl = clang::VarDecl;
using Decl = clang::Decl;
using LabelDecl = clang::LabelDecl;
using Expr = clang::Expr;
using DeclRefExpr = clang::DeclRefExpr;
using ForStmt = clang::ForStmt;
using SwitchStmt = clang::SwitchStmt;
using DoStmt = clang::DoStmt;

void LocalReduction::Initialize(clang::ASTContext &Ctx) {
  Reduction::Initialize(Ctx);
  CollectionVisitor = new LocalElementCollectionVisitor(this);
}

bool LocalReduction::HandleTopLevelDecl(DeclGroupRef D) {
  clang::SourceManager &SM = Context->getSourceManager();
  for (DeclGroupRef::iterator I = D.begin(), E = D.end(); I != E; ++I) {
    if (SourceManager::IsInHeader(SM, *I))
      continue;
    CollectionVisitor->TraverseDecl(*I);
  }
  return true;
}

void LocalReduction::HandleTranslationUnit(clang::ASTContext &Ctx) {
  for (auto const &FD : Functions) {
    spdlog::get("Logger")->info("Reduce {} at {}",
                                FD->getNameInfo().getAsString(),
                                OptionManager::InputFile);
    Queue.push(FD->getBody());

    CurrentFunction = FD;

    while (!Queue.empty()) {
      Stmt *S = Queue.front();
      Queue.pop();
      doHierarchicalDeltaDebugging(S);
    }
  }
}

DDElement LocalReduction::CastElement(Stmt *S) { return S; }

bool LocalReduction::callOracle() {
  Profiler::GetInstance()->incrementLocalReductionCounter();

  if (Reduction::callOracle()) {
    Profiler::GetInstance()->incrementSuccessfulLocalReductionCounter();
    FileManager::GetInstance()->saveTemp("local", true);
    return true;
  } else {
    FileManager::GetInstance()->saveTemp("local", false);
    return false;
  }
}

bool LocalReduction::test(DDElementVector &ToBeRemoved) {
  if(ToBeRemoved.size()==0) return true;
  const clang::SourceManager &SM = Context->getSourceManager();
  std::vector<clang::SourceRange> Ranges;
  std::vector<llvm::StringRef> Reverts;

  for (auto Element : ToBeRemoved) {
    if (Element.isNull())
      continue;

    clang::Stmt *S = Element.get<Stmt *>();
    clang::SourceLocation Start = SourceManager::GetBeginOfStmt(Context, S);
    clang::SourceLocation End = SourceManager::GetEndOfStmt(Context, S);

    if (End.isInvalid() || Start.isInvalid())
      return false;

    SourceRange Range(Start, End);
    Ranges.emplace_back(Range);
    llvm::StringRef Revert = SourceManager::GetSourceText(SM, Start, End);
    Reverts.emplace_back(Revert);
    removeSourceText(Start, End);
  }
  TheRewriter.overwriteChangedFiles();
  if (callOracle()) {
    for (auto &E : ToBeRemoved) {
      auto Children = getAllChildren(E.get<Stmt *>());
      RemovedElements.insert(Children.begin(), Children.end());
    }
    return true;
  } else {
    for (int i = 0; i < Reverts.size(); i++)
      TheRewriter.ReplaceText(Ranges[i], Reverts[i]);
    TheRewriter.overwriteChangedFiles();
    return false;
  }

  return false;
}

int LocalReduction::countReturnStmts(std::set<Stmt *> &Elements) {
  int NumReturns = 0;
  for (auto const &E : Elements)
    if (ReturnStmt *RS = llvm::dyn_cast<ReturnStmt>(E))
      NumReturns++;
  return NumReturns;
}

bool LocalReduction::noReturn(std::set<Stmt *> &FunctionStmts,
                              std::set<Stmt *> &AllRemovedStmts) {
  if (CurrentFunction->getReturnType().getTypePtr()->isVoidType())
    return false;
  int FunctionReturns = countReturnStmts(FunctionStmts);
  int RemovedReturns = countReturnStmts(AllRemovedStmts);
  if (FunctionReturns == 0 || RemovedReturns == 0)
    return false;
  if (countReturnStmts(FunctionStmts) == countReturnStmts(AllRemovedStmts))
    return true;
  return false;
}

bool LocalReduction::danglingLabel(std::set<Stmt *> &Remaining) {
  std::set<LabelStmt *> LabelDefs;
  std::set<LabelStmt *> LabelUses;

  for (auto const &S : Remaining) {
    if (!S)
      continue;
    if (GotoStmt *GS = llvm::dyn_cast<GotoStmt>(S))
      LabelUses.insert(GS->getLabel()->getStmt());
    else if (LabelStmt *LS = llvm::dyn_cast<LabelStmt>(S))
      LabelDefs.insert(LS);
  }

  return !(std::includes(LabelDefs.begin(), LabelDefs.end(), LabelUses.begin(),
                         LabelUses.end()));
}

std::vector<DeclRefExpr *> LocalReduction::getDeclRefExprs(Expr *E) {
  std::vector<DeclRefExpr *> result;
  std::vector<Stmt *> Children = getAllChildren(E);
  for (auto const &S : Children) {
    if (!S)
      continue;
    if (DeclRefExpr *DRE = llvm::dyn_cast<DeclRefExpr>(S))
      result.emplace_back(DRE);
  }
  return result;
}
void LocalReduction::addDefUse(DeclRefExpr *DRE, std::set<Decl *> &DU) {
  if (VarDecl *VD = llvm::dyn_cast<VarDecl>(DRE->getDecl())) {
    if (auto T = llvm::dyn_cast_or_null<clang::ConstantArrayType>(
            VD->getType().getTypePtr()))
      return;
    if (VD->isLocalVarDeclOrParm() || VD->isStaticLocal())
      DU.insert(DRE->getDecl());
  }
}

bool LocalReduction::brokenDependency(std::set<Stmt *> &Remaining) {
  std::set<Decl *> Defs, Uses;
  for (auto const &S : Remaining) {
    if (!S)
      continue;
    if (BinaryOperator *BO = llvm::dyn_cast<BinaryOperator>(S)) {
      if (BO->isCompoundAssignmentOp() || BO->isShiftAssignOp()) {
        for (auto C : getDeclRefExprs(BO->getLHS())) {
          addDefUse(C, Defs);
          addDefUse(C, Uses);
        }
        for (auto C : getDeclRefExprs(BO->getRHS()))
          addDefUse(C, Uses);
      } else if (BO->isAssignmentOp()) {
        for (auto C : getDeclRefExprs(BO->getLHS()))
          addDefUse(C, Defs);
        for (auto C : getDeclRefExprs(BO->getRHS()))
          addDefUse(C, Uses);
      } else {
        for (auto C : getDeclRefExprs(BO->getLHS()))
          addDefUse(C, Uses);
        for (auto C : getDeclRefExprs(BO->getRHS()))
          addDefUse(C, Uses);
      }
    } else if (UnaryOperator *UO = llvm::dyn_cast<UnaryOperator>(S)) {
      switch (UO->getOpcode()) {
      case clang::UO_PostInc:
      case clang::UO_PostDec:
      case clang::UO_PreInc:
      case clang::UO_PreDec:
        for (auto C : getDeclRefExprs(UO->getSubExpr())) {
          addDefUse(C, Defs);
          addDefUse(C, Uses);
        }
        break;
      case clang::UO_AddrOf:
        for (auto C : getDeclRefExprs(UO->getSubExpr()))
          addDefUse(C, Defs);
        break;
      case clang::UO_Plus:
      case clang::UO_Minus:
      case clang::UO_Not:
      case clang::UO_Deref:
      case clang::UO_LNot:
        for (auto C : getDeclRefExprs(UO->getSubExpr()))
          addDefUse(C, Uses);
      }
    } else if (DeclStmt *DS = llvm::dyn_cast<DeclStmt>(S)) {
      for (auto D : DS->decls())
        if (VarDecl *VD = llvm::dyn_cast<VarDecl>(D))
          if (VD->hasInit())
            Defs.insert(D);
    } else if (CallExpr *CE = llvm::dyn_cast<CallExpr>(S)) {
      for (int I = 0; I < CE->getNumArgs(); I++)
        for (auto C : getDeclRefExprs(CE->getArg(I)))
          addDefUse(C, Uses);
    } else if (ReturnStmt *RS = llvm::dyn_cast<ReturnStmt>(S)) {
      if (!CurrentFunction->getReturnType().getTypePtr()->isVoidType())
        for (auto C : getDeclRefExprs(RS->getRetValue()))
          addDefUse(C, Uses);
    }
    for (auto P : CurrentFunction->parameters())
      Defs.insert(P);
  }
  return !(std::includes(Defs.begin(), Defs.end(), Uses.begin(), Uses.end()));
}

std::set<Stmt *> LocalReduction::toSet(std::vector<Stmt *> &Vec) {
  std::set<Stmt *> S(Vec.begin(), Vec.end());
  return S;
}

std::set<Stmt *> LocalReduction::setDifference(std::set<Stmt *> &A,
                                               std::set<Stmt *> &B) {
  std::set<Stmt *> Result;
  std::set_difference(A.begin(), A.end(), B.begin(), B.end(),
                      std::inserter(Result, Result.begin()));
  return Result;
}

bool LocalReduction::isInvalidChunk(DDElementVector &Chunk) {
  if (OptionManager::SkipLocalDep)
    return false;
  std::vector<Stmt *> FunctionStmts =
      getAllChildren(CurrentFunction->getBody());
  std::vector<Stmt *> AllRemovedStmts;
  for (auto S : Chunk) {
    auto Children = getAllChildren(S.get<Stmt *>());
    AllRemovedStmts.insert(AllRemovedStmts.end(), Children.begin(),
                           Children.end());
  }
  auto TempFSet = toSet(FunctionStmts);
  auto FSet = setDifference(TempFSet, RemovedElements);
  auto ASet = toSet(AllRemovedStmts);
  auto Remaining = setDifference(FSet, ASet);

  if (noReturn(FSet, ASet))
    return true;
  if (danglingLabel(Remaining))
    return true;
  if (brokenDependency(Remaining))
    return true;
  return false;
}

void LocalReduction::doHierarchicalDeltaDebugging(Stmt *S) {
  if (S == NULL)
    return;
  clang::SourceLocation Start = SourceManager::GetBeginOfStmt(Context, S);
  const clang::SourceManager &SM = Context->getSourceManager();
  std::string Loc = Start.printToString(SM);
  if (IfStmt *IS = llvm::dyn_cast<IfStmt>(S)) {
    spdlog::get("Logger")->debug("HDD IF at " + Loc);
    reduceIf(IS);
  } else if (WhileStmt *WS = llvm::dyn_cast<WhileStmt>(S)) {
    spdlog::get("Logger")->debug("HDD WHILE at " + Loc);
    reduceWhile(WS);
  } else if (CompoundStmt *CS = llvm::dyn_cast<CompoundStmt>(S)) {
    spdlog::get("Logger")->debug("HDD Compound at " + Loc);
    reduceCompound(CS);
  } else if (LabelStmt *LS = llvm::dyn_cast<LabelStmt>(S)) {
    spdlog::get("Logger")->debug("HDD Label at " + Loc);
    reduceLabel(LS);
  } else if (ForStmt *FS = llvm::dyn_cast<ForStmt>(S)) {
    spdlog::get("Logger")->debug("HDD FOR at " + Loc);
    reduceFor(FS);
  } else if (SwitchStmt *SS = llvm::dyn_cast<SwitchStmt>(S)) {
    spdlog::get("Logger")->debug("HDD SWITCH at " + Loc);
    reduceSwitch(SS);
  } else if (DoStmt *DS = llvm::dyn_cast<DoStmt>(S)) {
    spdlog::get("Logger")->debug("HDD DO/WHILE at " + Loc);
    reduceDoWhile(DS);
  }
}

std::vector<Stmt *> LocalReduction::getBodyStatements(CompoundStmt *CS) {
  std::vector<Stmt *> Stmts;
  for (auto S : CS->body())
    if (S != NULL)
      Stmts.emplace_back(S);
  return Stmts;
}

void LocalReduction::reduceSwitch(SwitchStmt *SS) {
  const clang::SourceManager &SM = Context->getSourceManager();
  auto Body = SS->getBody();
  SourceLocation BeginSwitch = SourceManager::GetBeginOfStmt(Context, SS);
  SourceLocation EndSwitch = SourceManager::GetEndOfStmt(Context, SS);

  if (BeginSwitch.isInvalid() || EndSwitch.isInvalid()) {
    spdlog::get("Logger")->warn(
        "Invalid location:\nBeginSwitch: {}\nEndSwitch: {}",
        BeginSwitch.printToString(SM), EndSwitch.printToString(SM));
    return;
  }

  std::vector<clang::SwitchCase *> Cases;
  for (clang::SwitchCase *SC = SS->getSwitchCaseList(); SC != NULL;
       SC = SC->getNextSwitchCase()) {
    Cases.insert(Cases.begin(), SC);
  }
  for (int I = 0; I < Cases.size(); I++) {
    SourceLocation CurrLoc =
        SourceManager::GetRealLocation(Context, Cases[I]->getKeywordLoc());
    SourceLocation NextLoc;
    if (I < Cases.size() - 1) {
      NextLoc =
          SourceManager::GetRealLocation(Context, Cases[I + 1]->getKeywordLoc())
              .getLocWithOffset(-1);
    } else {
      NextLoc = EndSwitch.getLocWithOffset(-1);
    }
    llvm::StringRef Revert = SourceManager::GetSourceText(SM, CurrLoc, NextLoc);
    removeSourceText(CurrLoc, NextLoc);
    TheRewriter.overwriteChangedFiles();
    if (callOracle()) {
      auto TempChildren = getAllChildren(Cases[I]);
      RemovedElements.insert(TempChildren.begin(), TempChildren.end());
    } else {
      TheRewriter.ReplaceText(SourceRange(CurrLoc, NextLoc), Revert);
      TheRewriter.overwriteChangedFiles();
      Queue.push(Cases[I]);
    }
  }
}

void LocalReduction::reduceIf(IfStmt *IS) {
  const clang::SourceManager &SM = Context->getSourceManager();
  SourceLocation BeginIf = SourceManager::GetBeginOfStmt(Context, IS);
  SourceLocation EndIf = SourceManager::GetEndOfStmt(Context, IS);
  SourceLocation EndCond = SourceManager::GetEndOfCond(SM, IS->getCond());
  SourceLocation EndThen = SourceManager::GetEndOfStmt(Context, IS->getThen());

  if (BeginIf.isInvalid() || EndIf.isInvalid() || EndCond.isInvalid() ||
      EndThen.isInvalid()) {
    spdlog::get("Logger")->warn(
        "Invalid location:\nBeginIf: {}\nEndIf: {}\nEndCond: {}\nEndThen: {}",
        BeginIf.printToString(SM), EndIf.printToString(SM),
        EndCond.printToString(SM), EndThen.printToString(SM));
    return;
  }

  llvm::StringRef RevertIf = SourceManager::GetSourceText(SM, BeginIf, EndIf);

  if (IS->getElse()) {
    SourceLocation ElseLoc = IS->getElseLoc();
    if (ElseLoc.isInvalid())
      return;

    removeSourceText(BeginIf, EndCond);
    removeSourceText(ElseLoc, EndIf);
    TheRewriter.overwriteChangedFiles();
    if (callOracle()) {
      Queue.push(IS->getThen());
      std::vector<Stmt *> ElseVec = {IS->getCond(), IS->getElse()};
      for (auto C : ElseVec) {
        auto Children = getAllChildren(C);
        RemovedElements.insert(Children.begin(), Children.end());
      }
    } else {
      TheRewriter.ReplaceText(SourceRange(BeginIf, EndIf), RevertIf);
      removeSourceText(BeginIf, ElseLoc.getLocWithOffset(3));
      TheRewriter.overwriteChangedFiles();
      if (callOracle()) {
        Queue.push(IS->getElse());
        std::vector<Stmt *> ThenVec = {IS->getCond(), IS->getThen()};
        for (auto C : ThenVec) {
          auto Children = getAllChildren(C);
          RemovedElements.insert(Children.begin(), Children.end());
        }
      } else {
        TheRewriter.ReplaceText(SourceRange(BeginIf, EndIf), RevertIf);
        TheRewriter.overwriteChangedFiles();
        Queue.push(IS->getThen());
        Queue.push(IS->getElse());
      }
    }
  } else {
    removeSourceText(BeginIf, EndCond);
    TheRewriter.overwriteChangedFiles();
    if (callOracle()) {
      auto Children = getAllChildren(IS->getCond());
      RemovedElements.insert(Children.begin(), Children.end());
    } else {
      TheRewriter.ReplaceText(SourceRange(BeginIf, EndIf), RevertIf);
      TheRewriter.overwriteChangedFiles();
    }
    Queue.push(IS->getThen());
  }
}

void LocalReduction::reduceFor(ForStmt *FS) {
  const clang::SourceManager &SM = Context->getSourceManager();
  auto Body = FS->getBody();
  SourceLocation BeginFor = SourceManager::GetBeginOfStmt(Context, FS);
  SourceLocation EndFor = SourceManager::GetEndOfStmt(Context, FS);
  SourceLocation EndCond = FS->getRParenLoc();

  if (BeginFor.isInvalid() || EndFor.isInvalid() || EndCond.isInvalid()) {
    spdlog::get("Logger")->warn(
        "Invalid location:\nBeginFor: {}\nEndFor: {}\nEndCond: {}",
        BeginFor.printToString(SM), EndFor.printToString(SM),
        EndCond.printToString(SM));
    return;
  }

  llvm::StringRef Revert = SourceManager::GetSourceText(SM, BeginFor, EndFor);

  removeSourceText(BeginFor, EndCond);
  TheRewriter.overwriteChangedFiles();
  if (callOracle()) {
    std::vector<Stmt *> ForVec;
    if (FS->getCond())
      ForVec.emplace_back(FS->getCond());
    if (FS->getInit())
      ForVec.emplace_back(FS->getInit());
    if (FS->getInc())
      ForVec.emplace_back(FS->getInc());
    for (auto C : ForVec) {
      auto Children = getAllChildren(C);
      RemovedElements.insert(Children.begin(), Children.end());
    }
  } else {
    TheRewriter.ReplaceText(SourceRange(BeginFor, EndFor), Revert);
    TheRewriter.overwriteChangedFiles();
  }
  Queue.push(Body);
}

void LocalReduction::reduceWhile(WhileStmt *WS) {
  const clang::SourceManager &SM = Context->getSourceManager();
  auto Body = WS->getBody();
  SourceLocation BeginWhile = SourceManager::GetBeginOfStmt(Context, WS);
  SourceLocation EndWhile = SourceManager::GetEndOfStmt(Context, WS);
  SourceLocation EndCond = SourceManager::GetEndOfCond(SM, WS->getCond());

  if (BeginWhile.isInvalid() || EndWhile.isInvalid() || EndCond.isInvalid()) {
    spdlog::get("Logger")->warn("Invalid location:\nBeginWhile: {}\nEndWhile: "
                                "{}\nEndCond: {}",
                                BeginWhile.printToString(SM),
                                EndWhile.printToString(SM),
                                EndCond.printToString(SM));
    return;
  }

  llvm::StringRef Revert =
      SourceManager::GetSourceText(SM, BeginWhile, EndWhile);

  removeSourceText(BeginWhile, EndCond);
  TheRewriter.overwriteChangedFiles();
  if (callOracle()) {
    auto Children = getAllChildren(WS->getCond());
    RemovedElements.insert(Children.begin(), Children.end());
  } else {
    TheRewriter.ReplaceText(SourceRange(BeginWhile, EndWhile), Revert);
    TheRewriter.overwriteChangedFiles();
  }
  Queue.push(Body);
}

void LocalReduction::reduceDoWhile(DoStmt *DS) {
  const clang::SourceManager &SM = Context->getSourceManager();
  auto Body = DS->getBody();
  SourceLocation BeginDo = SourceManager::GetBeginOfStmt(Context, DS);
  SourceLocation EndDo = SourceManager::GetEndOfStmt(Context, DS);
  SourceLocation EndCond = SourceManager::GetEndOfCond(SM, DS->getCond());

  if (BeginDo.isInvalid() || EndDo.isInvalid() || EndCond.isInvalid()) {
    spdlog::get("Logger")->warn("Invalid location:\nBeginDo: {}\nEndDo: "
                                "{}\nEndCond: {}",
                                BeginDo.printToString(SM),
                                EndDo.printToString(SM),
                                EndCond.printToString(SM));
    return;
  }

  llvm::StringRef Revert = SourceManager::GetSourceText(SM, BeginDo, EndDo);

  removeSourceText(BeginDo, BeginDo.getLocWithOffset(1));
  removeSourceText(DS->getWhileLoc(), EndDo);
  TheRewriter.overwriteChangedFiles();
  if (callOracle()) {
    auto Children = getAllChildren(DS->getCond());
    RemovedElements.insert(Children.begin(), Children.end());
  } else {
    TheRewriter.ReplaceText(SourceRange(BeginDo, EndDo), Revert);
    TheRewriter.overwriteChangedFiles();
  }
  Queue.push(Body);
}

void LocalReduction::reduceCompound(CompoundStmt *CS) {
  auto Stmts = getBodyStatements(CS);
  filterElements(Stmts);

  DDElementVector Elements;
  if (Stmts.size() == 0)
    return;

  Elements.resize(Stmts.size());
  std::transform(Stmts.begin(), Stmts.end(), Elements.begin(), CastElement);

  DDElementSet Removed = doDeltaDebugging(Elements);
  for (auto S : Stmts) {
    if (Removed.find(S) == Removed.end())
      Queue.push(S);
  }
}

void LocalReduction::reduceLabel(LabelStmt *LS) {
  Queue.push(LS->getSubStmt());
}

void LocalReduction::filterElements(std::vector<clang::Stmt *> &Vec) {
  auto I = Vec.begin();
  while (I != Vec.end()) {
    clang::Stmt *S = *I;
    if (DeclStmt *DS = llvm::dyn_cast<DeclStmt>(S))
      Vec.erase(I);
    else if (clang::NullStmt *NS = llvm::dyn_cast<clang::NullStmt>(S))
      Vec.erase(I);
    else
      I++;
  }
}

bool LocalElementCollectionVisitor::VisitFunctionDecl(FunctionDecl *FD) {
  spdlog::get("Logger")->debug("Visit Function Decl: {}",
                               FD->getNameInfo().getAsString());
  if (FD->isThisDeclarationADefinition())
    Consumer->Functions.emplace_back(FD);
  return true;
}
