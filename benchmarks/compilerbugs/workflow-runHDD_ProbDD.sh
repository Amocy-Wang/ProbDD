#!/bin/bash
if [ ! -d "./results" ]; then
    mkdir results
fi
for i in 'clang-22382' 'clang-31259' 'gcc-65383' 'gcc-71626';
do
    target=$i
    echo $target
    cp /benchmarks/compilerbugs/$target/r.sh /benchmarks/compilerbugs
    cp /benchmarks/compilerbugs/$target/small.c.origin.c /benchmarks/compilerbugs/small.c
    timeout 10800 /hdd_ProbDD/anaconda2/bin/picireny -i small.c --test r.sh --srcml:language C --grammar C.g4 --start compilationUnit --disable-cleanup > log_hdd_$target 2>&1
    mv small.c.2021* /benchmarks/compilerbugs/results/$target-hdd
done
