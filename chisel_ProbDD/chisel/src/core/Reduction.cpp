#include "Reduction.h"

#include <algorithm>
#include <spdlog/spdlog.h>
#include <cmath>
#include <map>
#include <set>
#include <iostream>
#include <iterator>

#include "clang/Basic/SourceManager.h"
#include "llvm/Support/Program.h"

#include "OptionManager.h"
#include "Profiler.h"
#include "Report.h"

void Reduction::Initialize(clang::ASTContext &C) {
  Transformation::Initialize(C);
}

bool Reduction::callOracle() {
  testTimes=testTimes+1;
  printf("\n\ncurrent test times:%d\n\n",testTimes);
  Profiler::GetInstance()->beginOracle();
  int Status = llvm::sys::ExecuteAndWait(OptionManager::OracleFile,
                                         {OptionManager::OracleFile});
  Profiler::GetInstance()->endOracle();
  return (Status == 0);
}

DDElementSet Reduction::toSet(DDElementVector &Vec) {
  DDElementSet S(Vec.begin(), Vec.end());
  return S;
}

DDElementSet Reduction::setDifference(DDElementSet &A, DDElementSet &B) {
  DDElementSet Result;
  std::set_difference(A.begin(), A.end(), B.begin(), B.end(),
                      std::inserter(Result, Result.begin()));
  return Result;
}

DDElementVector Reduction::toVector(DDElementSet &Set) {
  DDElementVector Vec(Set.begin(), Set.end());
  return Vec;
}

std::vector<DDElementVector> Reduction::getCandidates(DDElementVector &Decls,
                                                      int ChunkSize) {
  if (Decls.size() == 1)
    return {Decls};
  std::vector<DDElementVector> Result;
  int Partitions = Decls.size() / ChunkSize;
  for (int Idx = 0; Idx < Partitions; Idx++) {
    DDElementVector Target;
    Target.insert(Target.end(), Decls.begin() + Idx * ChunkSize,
                  Decls.begin() + (Idx + 1) * ChunkSize);
    if (Target.size() > 0)
      Result.emplace_back(Target);
  }
  for (int Idx = 0; Idx < Partitions; Idx++) {
    DDElementVector Complement;
    Complement.insert(Complement.end(), Decls.begin(),
                      Decls.begin() + Idx * ChunkSize);
    Complement.insert(Complement.end(), Decls.begin() + (Idx + 1) * ChunkSize,
                      Decls.end());
    if (Complement.size() > 0)
      Result.emplace_back(Complement);
  }

  if (OptionManager::SkipLearning)
    return Result;
  else {
    arma::uvec ChunkOrder = TheModel.sortCandidates(Decls, Result);
    std::vector<DDElementVector> SortedResult;
    for (int I = 0; I < Result.size(); I++)
      if (ChunkOrder[I] != -1)
        SortedResult.emplace_back(Result[ChunkOrder[I]]);
    return SortedResult;
  }
}

// probDD
float f(float x) {
  return std::fmin(x,1);
}

bool intersect(std::vector<int>& A,std::vector<int>& B){
  int sz=A.size();
  for(int i=0;i<sz;++i){
    if(find(B.begin(),B.end(),A[i])!=B.end())
      return true;
  }
  return false;
}

std::vector<int> sort_index(std::vector<float>& p) {
  std::vector<int> idx(p.size());
  iota(idx.begin(),idx.end(),0);
  sort(idx.begin(),idx.end(),[&p](int i1, int i2) {return p[i1] < p[i2];});
  return idx;
}

std::vector<int> sample(std::vector<float>& p) {
  std::vector<int> res;
  std::vector<int> idx = sort_index(p);
  double tmp = 1;
  double last = 0;
  int k = 0;
  int i;
  for (i = 0 ; i < idx.size(); i++){
    if (p[idx[i]] < 0){ 
      k++;
      continue;
    }   
    if (p[idx[i]] > 1)  
      break;
    for ( int j = k ; j < i + 1; j ++ )
      tmp *= (1-p[idx[j]]);
    tmp *= (i - k + 1); 
    std::cout << "prob: " << p[idx[i]] << "; tmp: " << tmp << "; last: " << last << std::endl;
    if (tmp < last)
      break;
    last = tmp;
    tmp = 1;
  }
  std::cout << i << std::endl;
  std::cout << k << std::endl;
  while(--i > k - 1)  
    res.push_back(idx[i]);
  std::cout << "selected index prob:" << std::endl;
  for ( int cn = 0; cn < res.size(); cn++)
    std::cout << p[res[cn]] << ",";
  std::cout << std::endl;
  return res;
}


std::vector<int> pickProgram(std::vector<float>& p,bool restrictionToOne,float threshold) {
  float probability;
  int len=p.size();
  std::vector<int> res;

  int choose=-1;
  if(restrictionToOne){
    for(int i=len-1;i>=0;--i){
     if(fabs(p[i]+(1<<20))<5)
      continue;
      if(choose==-1){
        choose=i;
        continue;
      }
      if(p[i]>p[choose])
        choose=i;
     }
    res.push_back(choose);
  }
  else{
    for(int i=0;i<len;++i){
     if(fabs(p[i]+(1<<20))<5) 
      continue;
     if(f(p[i])>threshold)
      continue;
     probability = rand() % (RAND_MAX) / (float)(RAND_MAX);
     if (probability>f(p[i])){
        res.push_back(i);
     }
    }
  }
  return res;
}


bool checkStop(std::vector<float>& p,float threshold) {
  int len=p.size();
  for(int i=0;i<len;++i){
    if((fabs(p[i]+(1<<20))>5)&&(f(p[i])<threshold))
      return false;
  }
  std::cout << "Iteration needs to terminate" << std::endl;
  return true;
}

std::vector<int> minus(std::vector<int>& A,std::vector<int>& B){//return A-B
  int len=A.size();
  std::vector<int> ret;
  for(int i=0;i<len;++i){
    if(find(B.begin(),B.end(),A[i])==B.end())
      ret.push_back(A[i]);
  }
  return ret;
}

void Reduction::refine(bool status,std::vector<int>& index,std::vector<float>& p,float delta){
  std::vector<int> waitList;
  if(status==true){
    std::vector<std::vector<int>> cache;
    for(auto history=mp1.begin(); history!=mp1.end();){
      std::vector<int> tmp=history->first;
      if(intersect(index,tmp)){
        std::vector<int> cha=minus(tmp,index);
        int sz=cha.size();
        if(sz==1){ //can't delete
          waitList.push_back(cha[0]);
          p[cha[0]]=-(1<<20);//can't delete
        }
        else{
          cache.push_back(cha);
        }
        mp1.erase(history++);
      }
      else
        history++;
    }
    int sz=cache.size();
    for(int i=0;i<sz;++i){
      mp1[cache[i]]=false;
    }
  }
  else{
    waitList.push_back(index[0]);
  }

  //for(auto history=mp1.begin(); history!=mp1.end();){
  //    std::vector<int> tmp=history->first;
  //    if(intersect(waitList,tmp)){
  //      std::vector<int> cha=minus(tmp,waitList);
  //      int sz=cha.size();
  //      for(int i=0;i<sz;++i){
  //        if((p[cha[i]]+(1<<20))>5)
  //          p[cha[i]]=p[cha[i]]-delta;
  //      }
  //      mp1.erase(history++);
  //    }
  //    else
  //      history++;
  //  }
}
double computeRatio(std::vector<int> removed, std::vector<float> prob) {
  if (removed.size() == 0) return 1;
  for (int i =0;i<prob.size();i++) std::cout << std::setprecision(5) << prob[i] << ",";
  std::cout << std::endl;
  for (int i =0;i<removed.size();i++) std::cout << removed[i] << ",";
  std::cout << std::endl;
  double res = 0;
  double tmplog = 1;
  for (int i = 0 ; i < removed.size() ; i ++ ){
    //tmplog += log(1-prob[removed[i]]);
    if (prob[removed[i]] > 0 and prob[removed[i]] < 1)
      tmplog *= (1-prob[removed[i]]);
  }
  std::cout << std::setprecision(20) << "tmplog: " << tmplog << std::endl;
  //res = 1 / (1 - exp(tmplog));
  res = 1 / (1 - tmplog);
  std::cout << std::setprecision(20) << "res: " << res << std::endl;
  return res;
}

void printSet(std::set<int> toprint) {
  if (toprint.size()==0) {
    std::cout << "empty set" << std::endl;
    return;
  }
  copy(toprint.begin(),toprint.end(),std::ostream_iterator<int>(std::cout,","));
  std::cout << std::endl;
}

DDElementSet Reduction::doDeltaDebugging(DDElementVector &Decls) {
  mp1.clear();
  DDElementSet Removed;
  std::map< std::vector<int>, std::map< int, double > > recordDelta; 
  int len=Decls.size();
  float delta=0.1;
  float initialP=0.1;
  float threshold=0.8;
  bool restrictionToOne=false;
  
  printf("In probDD,Configure:initialP=%f,threshold=%f\n",initialP,threshold);
  std::vector<float> p(len,initialP);
  std::vector<int> index;
  DDElementVector program;
  printf("Input size:%d\n",Decls.size());

  while (true) {
    std::cout << "Iteration starts with size: " << len << std::endl;
    // select a subsequence for testing
    index=sample(p);
    program.clear();
    std::cout << "deletion size: " << index.size() << std::endl;

    for (int i: index) {
      program.push_back(Decls[i]);
    }

    bool status;
    if(mp1.find(index)!=mp1.end()){
        status=mp1[index];
    }
    else{
      if(isInvalidChunk(program)){
          status=false;
      }
      else{
          status = test(program);
      }
    }

    if (status) { // safely delete and update the model
      std::cout << "pass" << std::endl;
      auto TargetSet = toSet(program);
      Removed.insert(TargetSet.begin(), TargetSet.end());
      for(int i: index) {
          p[i]= -(1<<20);
      }
      refine(status,index,p,delta);
    }
    else { //can't delete and update the model
      std::cout << "fail" << std::endl;
      double incRatio = computeRatio(index, p);
      std::map< int, double > incdelta;
      std::cout << std::setprecision(10) << "Increase ratio: " << incRatio << std::endl;
      for (int i : index) {
        double delta = (incRatio - 1) * p[i];
        incdelta[i] = delta;
        std::cout << std::setprecision(10) << "prob = "  << p[i] << ". By theory, increase delta: " << delta << std::endl;
        p[i] += delta;
      }

      if(index.size()==1){
        p[index[0]]=-(1<<20);
      } 
      if(!OptionManager::NoCache) {
        mp1[index]=status;
      }
    }

    std::cout << "checkStop here" << std::endl;
    if (checkStop(p,threshold))
      break;
  }
  return Removed;
}

