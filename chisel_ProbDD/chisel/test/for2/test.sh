#!/bin/bash

BIN=for2
SRC=$BIN.c

clang -w -o $BIN $SRC >& /dev/null || exit 1
./$BIN || exit 1
rm $BIN
