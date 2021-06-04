## Introduction

**This repo contains all the C benchmarks used in our Perses paper [1]**

Perses is a new program reduction tool. It is language agnostic, 
and leverages the knowledge in the formal syntax to guide program reduction. 
In this paper, we used 20 real-world C compiler bugs (i.e., GCC and LLVM) to demonstrate
its effectiveness and efficiency. 

We release the benchmarks for the purpose of research reproduction,
and hope they can be used for other types of research.

***Pull requests are welcome, e.g., adding new benchmark, refining the documentation.***

---

## Usage

Each benchmark has two files, **small.c** and **r.sh**. 
The script **r.sh** encodes the property that the program reducer should preserve. 
In these benchmarks, the property is that the reduced variant still triggers the same bug.   

After you run **r.sh**, the exit code of the execution indicates whether the property 
is kept:

* 0: the property is kept
* non zero: otherwise

Initially, the exit code of **r.sh** should be 0, and after the reduction, it should still be 0.

***Note: Please do not modify the test scripts if you want to reproduce the results, becaus they will also affect the final reduced results.***

---

## Prerequisite

Here is the incomplete the list of prerequisites. 

1. CompCert
2. Various versions of GCC and Clang
3. clang-trunk and gcc-trunk (It is fine to link these to the latest versions of clang and gcc)

---

## Paper

***If you decide to use the data in this repo, please directly cite the paper [1], 
but not the link of this repo. ***

[1] Perses: Syntax-Guided Program Reduction. 
Chengnian Sun, Yuanbo Li, Qirun Zhang, Tianxiao Gu, Zhendong Su
International Conference on Software Engineering
ICSE 2018, full paper, [pdf](https://chengniansun.bitbucket.io/papers/icse18.pdf)