#!/bin/bash

export BENCHMARK_NAME=uniq-8.16
export BENCHMARK_DIR=$CHISEL_BENCHMARK_HOME/benchmark/$BENCHMARK_NAME/merged
export SRC=$BENCHMARK_DIR/$BENCHMARK_NAME.c
export ORIGIN_BIN=$BENCHMARK_DIR/$BENCHMARK_NAME.origin
export REDUCED_BIN=$BENCHMARK_DIR/$BENCHMARK_NAME.reduced
export TIMEOUT="-k 0.5 0.5"
export LOG=$BENCHMARK_DIR/log.txt

source $CHISEL_BENCHMARK_HOME/benchmark/test-base.sh

function clean() {
  rm -rf $LOG $REDUCED_BIN temp
  return 0
}

# $1: option
function desired_run() {
  temp1=$({ timeout $TIMEOUT $REDUCED_BIN $1 data.txt; } 2>&1 || exit 1)
  temp2=$({ $ORIGIN_BIN $1 data.txt; } 2>&1)
  diff -q <(echo $temp1) <(echo $temp2) >&/dev/null || exit 1
  temp1=$({ timeout $TIMEOUT $REDUCED_BIN $1 input; } 2>&1 || exit 1)
  temp2=$({ $ORIGIN_BIN $1 input; })
  diff -q <(echo $temp1) <(echo $temp2) >&/dev/null || exit 1
  return 0
}

function desired() {
  desired_run "" || exit 1
  desired_run "-c" || exit 1
  desired_run "-d" || exit 1
  desired_run "-u" || exit 1
  desired_run "-i" || exit 1
  desired_run "-f 5" || exit 1
  desired_run "-s 10" || exit 1
  desired_run "-w 10" || exit 1
  return 0
}

function desired_disaster_run() {
  { timeout $TIMEOUT $REDUCED_BIN $1 data.txt; } >&$LOG
  grep -E -q "$2" $LOG || exit 1
  return 0
}

function desired_disaster() {
  case $1 in
  memory)
    MESSAGE="memory exhausted"
    ;;
  file)
    MESSAGE="write error"
    ;;
  *)
    return 1
    ;;
  esac
  desired_disaster_run "" "$MESSAGE" || exit 1
  desired_disaster_run "-c" "$MESSAGE" || exit 1
  desired_disaster_run "-d" "$MESSAGE" || exit 1
  desired_disaster_run "-u" "$MESSAGE" || exit 1
  desired_disaster_run "-i" "$MESSAGE" || exit 1
  desired_disaster_run "-f 5" "$MESSAGE" || exit 1
  desired_disaster_run "-s 10" "$MESSAGE" || exit 1
  desired_disaster_run "-w 10" "$MESSAGE" || exit 1
  return 0
}

function infinite() {
  if [[ $? -eq 124 ]]; then # timeout
    return 0
  else
    return 1
  fi
}

function outputcheckerror() {
  r="$1"
  if [[ $3 == "" && -s temp ]]; then
    return 1
  fi
  if grep -E -q "$r" $LOG; then
    return 1
  fi
  return 0
}

function run() {
  printf $2 >&temp
  { timeout $TIMEOUT $REDUCED_BIN "$1" temp; } >&$LOG
  err=$?
  outputcheckerror "$3" && exit 1
  crash $err && exit 1
  return 0
}

function undesired() {
  { timeout $TIMEOUT $REDUCED_BIN; } >&$LOG
  infinite $? || exit 1
  { timeout $TIMEOUT $REDUCED_BIN notexist; } >&$LOG
  err=$?
  outputcheckerror "notexist: No such file or directory" && exit 1
  crash $err && exit 1
  { timeout $TIMEOUT $REDUCED_BIN notexist1 notexist2 notexist3; } >&$LOG
  err=$?
  outputcheckerror "extra operand" && exit 1
  crash $err && exit 1
  run '-f1' "y z\n\xa0 y z\n" "" || exit 1
  run '' '' "No such file or directory" || exit 1
  run '' "a\na\n" "No such file or directory" || exit 1
  run '' "a\na" "No such file or directory" || exit 1
  run '' "a\nb" "No such file or directory" || exit 1
  run '' "a\na\nb" "No such file or directory" || exit 1
  run '' "b\na\na\n" "No such file or directory" || exit 1
  run '' "a\nb\nc\n" "No such file or directory" || exit 1
  run '-z' "a\na\n" "" || exit 1
  run '-z' "a\na" "" || exit 1
  run '-z' "a\nb" "" || exit 1
  run '-z' "a\na\nb" "" || exit 1
  run '-dz' "a\na\n" "" || exit 1
  run '' "ö\nv\n" "No such file or directory" || exit 1
  run '-u' "a\na\n" "No such file or directory" || exit 1
  run '-u' "a\nb\n" "" || exit 1
  run '-u' "a\nb\na\n" "" || exit 1
  run '-u' "a\na\n" "" || exit 1
  run '-u' "a\na\n" "" || exit 1
  run '-d' "a\na\n" "" || exit 1
  run '-d' "a\nb\n" "" || exit 1
  run '-d' "a\nb\na\n" "" || exit 1
  run '-d' "a\na\nb\n" "" || exit 1
  run '-1' "a a\nb a\n" || exit 1
  run "-f 1" "a a\nb a\n" || exit 1
  run "-f 1" "a a\nb b\n" || exit 1
  run "-f 1" "a a a\nb a c\n" || exit 1
  run "-f 1" "b a\na a\n" || exit 1
  run "-f 2" "a a c\nb a c\n" || exit 1
  run '+1' "aaa\naaa\n" "+1: No such file or directory" || exit 1
  run '+1' "baa\naaa\n" "+1: No such file or directory" || exit 1
  run "-s 1" "aaa\naaa\n" "" || exit 1
  run "-s 2" "baa\naaa\n" "" || exit 1
  run "+1 --" "aaa\naaa\n" "+1 --: No such file or directory" || exit 1
  run "+1 --" "baa\naaa\n" "+1 --: No such file or directory" || exit 1
  run "-f 1 -s 1" "a aaa\nb ab\n" "1 -s 1: invalid number of fields to skip" || exit 1
  run "-f 1 -s 1" "a aaa\nb aaa\n" "1 -s 1: invalid number of fields to skip" || exit 1
  run "-s 1 -f 1" "a aaa\nb ab\n" "1 -f 1: invalid number of fields to skip" || exit 1
  run "-s 1 -f 1" "a aaa\nb aaa\n" "1 -s 1: invalid number of fields to skip" || exit 1
  run "-s 4" "abc\nabcd\n" || exit 1
  run "-s 0" "abc\nabcd\n" || exit 1
  run "-s 0" "abc\n" || exit 1
  run "-w 0" "abc\nabcd\n" || exit 1
  run "-w 1" "a a\nb a\n" || exit 1
  run "-w 3" "a a\nb a\n" || exit 1
  run "-w 1 -f 1" "a a a\nb a c\n" "1 -f 1: invalid number of bytes to compare" || exit 1
  run "-f 1 -w 1" "a a a\nb a c\n" "1 -w 1: invalid number of fields to skip" || exit 1
  run "-f 1 -w 4" "a a a\nb a c\n" "1 -w 4: invalid number of fields to skip" || exit 1
  run "-f 1 -w 3" "a a a\nb a c\n" "1 -w 3: invalid number of fields to skip" || exit 1
  run '' "a\0a\na\n" "No such file or directory" || exit 1
  run '' "a\ta\na a\n" "No such file or directory" || exit 1
  run "-f 1" "a\ta\na a\n" || exit 1
  run "-f 2" "a\ta a\na a a\n" || exit 1
  run "-f 1" "a\ta\na\ta\n" || exit 1
  run '-c' "a\nb\n" || exit 1
  run '-c' "a\na\n" || exit 1
  run '-D' "a\na\n" || exit 1
  run "-D -w1" "a a\na b\n" "invalid option --" || exit 1
  run "-D -c" "a a\na b\n" "invalid option --" || exit 1
  run '--all-repeated=separate' "a\na\n" "" || exit 1
  run '--all-repeated=separate' "a\na\nb\nc\nc\n" "" || exit 1
  run '--all-repeated=separate' "a\na\nb\nb\nc\n" "" || exit 1
  run '--all-repeated=prepend' "a\na\n" "" || exit 1
  run '--all-repeated=prepend' "a\na\nb\nc\nc\n" "" || exit 1
  run '--all-repeated=prepend' "a\nb\n" "" || exit 1
  run "-d -u" "a\na\n\b" || exit 1
  run "-d -u -w1111111111111111111111111111111111111111" "a\na\n\b" "invalid option --" || exit 1
  run '--zero-terminated' "a\na\nb" "invalid option --" || exit 1
  run '--zero-terminated' "a\0a\0b" "" || exit 1
  return 0
}

main
