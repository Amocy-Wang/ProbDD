#!/bin/bash

for i in 'grep-2.19' 'mkdir-5.2.1';
do
	echo $i
	subjpath=/benchmarks/chisel-bench/benchmark/$i
	targetpath=$subjpath
	if [[ "$i" != "gzip-1.2.4" ]];then
		targetpath=$targetpath/merged
	fi
	rm -rf $targetpath
	git checkout $targetpath/*
	if [[ "$i" = "sort-8.16" ]];then
		cp $subjpath/test.sh $targetpath/
	fi
	if [[ "$i" = "tar-1.14" ]];then
		cp $subjpath/test.sh $targetpath/
	fi
	echo $targetpath
	cd $targetpath && make reduce >> $targetpath/ProbDD.out 2>&1
done
