#!/bin/bash

if [[ `grep -c "main" simple.c` -ne 0 ]]; then
    echo "failed"
    exit 0
else
    echo "success"
    exit 1
fi
