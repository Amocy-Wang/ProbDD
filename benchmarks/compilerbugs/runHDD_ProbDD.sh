#!/bin/bash
if [ ! -d "./results" ]; then
    mkdir results
fi
for i in 'gcc-60116' 'gcc-71626' 'gcc-70586' 'gcc-70127' 'gcc-66375' 'gcc-66186' 'gcc-65383' 'gcc-64990' 'gcc-61917' 'gcc-61383' 'gcc-59903' 'clang-31259' 'clang-27747' 'clang-27137' 'clang-26760' 'clang-25900' 'clang-23353' 'clang-23309' 'clang-22704' 'clang-22382';
do
    target=$i
    echo $target
    cp /benchmarks/compilerbugs/$target/r.sh /benchmarks/compilerbugs
    cp /benchmarks/compilerbugs/$target/small.c.origin.c /benchmarks/compilerbugs/small.c
    timeout 10800 /hdd_ProbDD/anaconda2/bin/picireny -i small.c --test r.sh --srcml:language C --grammar C.g4 --start compilationUnit --disable-cleanup > log_hdd_$target 2>&1
    mv small.c.2021* /benchmarks/compilerbugs/results/$target-hdd
done
