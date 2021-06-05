#!/bin/bash

# Please run bzip2-1.0.5, gzip-1.2.4, tar-1.14 by moving to the working path of the correspongind subjects and run the command 'make reduce'
for i in 'chown-8.2' 'grep-2.19' 'mkdir-5.2.1' 'rm-8.4' 'sort-8.16' 'uniq-8.16' 'date-8.21';
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
	cd $targetpath && make reduce >> $targetpath/activecoarsen.out 2>&1
done
