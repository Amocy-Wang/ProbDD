#!/bin/bash
for i in 'gcc-60116' 'gcc-71626' 'gcc-70586' 'gcc-70127' 'gcc-66375' 'gcc-66186' 'gcc-65383' 'gcc-64990' 'gcc-61917' 'gcc-61383' 'gcc-59903' 'clang-31259' 'clang-27747' 'clang-27137' 'clang-26760' 'clang-25900' 'clang-23353' 'clang-23309' 'clang-22704' 'clang-22382';
do
    echo $i
    cd /benchmarks/compilerbugs/$i
    cp /benchmarks/compilerbugs/$i/small.c.origin.c /benchmarks/compilerbugs/$i/small.c
    rm -f /benchmarks/compilerbugs/$i/chisel_activecoarsen.out
    timeout 10800 /chisel_activecoarsen/build/bin/chisel --skip_local_dep --skip_global_dep --skip_dce /benchmarks/compilerbugs/$i/r.sh /benchmarks/compilerbugs/$i/small.c >> /benchmarks/compilerbugs/$i/chisel_activecoarsen.out
done

