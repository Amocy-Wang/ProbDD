#ifndef REDUCTION_H
#define REDUCTION_H

#include <vector>

#include "ProbabilisticModel.h"
#include "Transformation.h"

using DDElement = llvm::PointerUnion<clang::Decl *, clang::Stmt *>;
using DDElementVector = std::vector<DDElement>;
using DDElementSet = std::set<DDElement>;

/// \brief Represents a general reduction step
class Reduction : public Transformation {
public:
  Reduction() {}
  ~Reduction() {}
  void refine(bool status,std::vector<int>& index,std::vector<float>& p,float alpha);

protected:
  virtual void Initialize(clang::ASTContext &Ctx);

  DDElementSet doDeltaDebugging(std::vector<DDElement> &Decls);

  virtual bool test(DDElementVector &ToBeRemoved) = 0;
  virtual bool callOracle();
  virtual bool isInvalidChunk(DDElementVector &Chunk) = 0;

  DDElementSet toSet(DDElementVector &Vec);
  DDElementSet setDifference(DDElementSet &A, DDElementSet &B);

private:
  ProbabilisticModel TheModel;
  std::set<DDElementVector> Cache;
  DDElementVector toVector(DDElementSet &Set);

  std::vector<DDElementVector> getCandidates(DDElementVector &Decls,
                                             int ChunkSize);
  std::map<std::vector<int>,bool> mp1;
  std::map<DDElementVector,bool> mp;
};

#endif // REDUCTION_H
