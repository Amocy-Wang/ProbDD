#!/bin/bash
for i in 'clang-22382' 'clang-31259' 'gcc-66186' 'gcc-66375';
do
    echo $i
    cd /benchmarks/compilerbugs/$i
    cp /benchmarks/compilerbugs/$i/small.c.origin.c /benchmarks/compilerbugs/$i/small.c
    rm -f /benchmarks/compilerbugs/$i/workflow-chisel_ProbDD.out
    timeout 10800 /chisel_ProbDD/build/bin/chisel --skip_local_dep --skip_global_dep --skip_dce /benchmarks/compilerbugs/$i/r.sh /benchmarks/compilerbugs/$i/small.c >> /benchmarks/compilerbugs/$i/workflow-chisel_ProbDD.out
done

