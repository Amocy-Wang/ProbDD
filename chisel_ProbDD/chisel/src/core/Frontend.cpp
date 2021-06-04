#include "Frontend.h"

#include "clang/Basic/Diagnostic.h"
#include "clang/Basic/TargetInfo.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Lex/Preprocessor.h"
#include "clang/Parse/ParseAST.h"

#include "IntegrationManager.h"

bool Frontend::Parse(std::string &InputFile, clang::ASTConsumer *R) {
  std::unique_ptr<clang::CompilerInstance> CI(new clang::CompilerInstance);
  CI->createDiagnostics();
  clang::TargetOptions &TO = CI->getTargetOpts();
  TO.Triple = llvm::sys::getDefaultTargetTriple();
  clang::CompilerInvocation &Invocation = CI->getInvocation();
  std::vector<const char *> Args =
      IntegrationManager::GetInstance()->getCC1Args(InputFile);
  clang::CompilerInvocation::CreateFromArgs(
      Invocation, &Args[0], &Args[0] + Args.size(), CI->getDiagnostics());
  clang::TargetInfo *Target = clang::TargetInfo::CreateTargetInfo(
      CI->getDiagnostics(), CI->getInvocation().TargetOpts);
  CI->setTarget(Target);

  CI->createFileManager();
  CI->createSourceManager(CI->getFileManager());
  CI->createPreprocessor(clang::TU_Complete);
  CI->createASTContext();

  CI->setASTConsumer(std::unique_ptr<clang::ASTConsumer>(R));
  clang::Preprocessor &PP = CI->getPreprocessor();
  PP.getBuiltinInfo().initializeBuiltins(PP.getIdentifierTable(),
                                         PP.getLangOpts());

  if (!CI->InitializeSourceManager(
          clang::FrontendInputFile(InputFile, clang::InputKind::C))) {
    return false;
  }

  CI->createSema(clang::TU_Complete, 0);
  clang::DiagnosticsEngine &Diag = CI->getDiagnostics();
  Diag.setSuppressAllDiagnostics(true);
  Diag.setIgnoreAllWarnings(true);

  CI->getDiagnosticClient().BeginSourceFile(CI->getLangOpts(),
                                            &CI->getPreprocessor());
  ParseAST(CI->getSema());
  CI->getDiagnosticClient().EndSourceFile();
  return true;
}

int Frontend::count(std::string &InputFile)
{
    using clang::CompilerInstance;
    using clang::TargetOptions;
    using clang::TargetInfo;
    using clang::FileEntry;
    using clang::Token;
    using clang::DiagnosticOptions;
    //using clang::TextDiagnosticPrinter;

    CompilerInstance ci;
    DiagnosticOptions diagnosticOptions;
    ci.createDiagnostics();

    std::shared_ptr<clang::TargetOptions> pto = std::make_shared<clang::TargetOptions>();
    pto->Triple = llvm::sys::getDefaultTargetTriple();
    TargetInfo *pti = TargetInfo::CreateTargetInfo(ci.getDiagnostics(), pto);
    ci.setTarget(pti);

    ci.createFileManager();
    ci.createSourceManager(ci.getFileManager());
    ci.createPreprocessor(clang::TU_Complete);

    //ci.InitializeSourceManager(
          //clang::FrontendInputFile(InputFile, clang::InputKind::C));
    const FileEntry *pFile = ci.getFileManager().getFile(InputFile);
    if(pFile==NULL)
        printf("Input File not found.In Frontend::count");
    //clang::FileID fileId=ci.getSourceManager().createFileID( pFile, clang::SourceLocation(), clang::SrcMgr::C_User);
    ci.getSourceManager().setMainFileID( ci.getSourceManager().createFileID( pFile, clang::SourceLocation(), clang::SrcMgr::C_User));
    ci.getPreprocessor().EnterMainSourceFile();
    ci.getDiagnosticClient().BeginSourceFile(ci.getLangOpts(),
                                             &ci.getPreprocessor());
    Token tok;
    int tokenCount=0;
    do {
        ci.getPreprocessor().Lex(tok);
        if( ci.getDiagnostics().hasErrorOccurred())
            break;
        tokenCount++;
        //ci.getPreprocessor().DumpToken(tok);
        //printf("\n");
    } while ( tok.isNot(clang::tok::eof));
    ci.getDiagnosticClient().EndSourceFile();
    return tokenCount;
}
