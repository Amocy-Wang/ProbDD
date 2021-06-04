#!/bin/bash

export BENCHMARK_NAME=gzip-1.2.4
export BENCHMARK_DIR=$CHISEL_BENCHMARK_HOME/benchmark/$BENCHMARK_NAME
export SRC=$BENCHMARK_DIR/$BENCHMARK_NAME.c
export ORIGIN_BIN=$BENCHMARK_DIR/$BENCHMARK_NAME.origin
export REDUCED_BIN=$BENCHMARK_DIR/$BENCHMARK_NAME.reduced
export TIMEOUT="-k 0.5 0.5"
export LOG=$BENCHMARK_DIR/log.txt

source $CHISEL_BENCHMARK_HOME/benchmark/test-base.sh

function clean() {
  rm -rf $LOG $REDUCED_BIN *.gz *.rb2 *.tst log* foo* bar* failures_compile failures_core
  return 0
}

function desired() {
  # -c
  $ORIGIN_BIN -c <references/sample1.ref >sample1.gz 2>/dev/null
  { timeout $TIMEOUT $REDUCED_BIN -c <references/sample1.ref >sample1.rb2; } 2>$LOG
  crash $? && exit 1
  cmp sample1.gz sample1.rb2 >&/dev/null || exit 1
  # -d
  { timeout $TIMEOUT $REDUCED_BIN -d <sample1.gz >sample1.tst; } 2>$LOG
  crash $? && exit 1
  cmp sample1.tst references/sample1.ref >&/dev/null || exit 1
  # -f
  echo "1234" >foo
  $ORIGIN_BIN -c foo >&/dev/null
  { timeout $TIMEOUT $REDUCED_BIN -f foo; } 2>$LOG
  crash $? && exit 1
  # -t (expected to return 1)
  echo "1234" >foo
  { timeout $TIMEOUT $REDUCED_BIN -t foo; } 2>$LOG
  if [[ $? -ne 1 ]]; then
    exit 1
  fi
  # -t
  { timeout $TIMEOUT $REDUCED_BIN -t sample1.gz; } 2>$LOG
  crash $? && exit 1
  return 0
}

function disired_disaster_mem() {
  # -d
  $ORIGIN_BIN -c <references/sample1.ref >sample1.gz 2>/dev/null
  { timeout $TIMEOUT $REDUCED_BIN -d <sample1.gz >sample1.tst; } 2>$LOG
  grep -q -E "$1" $LOG || exit 1
  # -t
  { timeout $TIMEOUT $REDUCED_BIN -t sample1.gz; } 2>$LOG
  grep -q -E "$1" $LOG || exit 1
  return 0
}

function disired_disaster_file() {
  # -d
  $ORIGIN_BIN -c <references/sample1.ref >sample1.gz 2>/dev/null
  { timeout $TIMEOUT $REDUCED_BIN -d <sample1.gz >sample1.tst; } 2>$LOG
  grep -q -E "$1" $LOG || exit 1
  return 0
}

OPT0=("-l" "--list")
OPT1=("--help" "-h" "-S" "--suffix" "-k")
OPT2=("--license" "-L")
OPT3=("--no-name" "--name" "--quiet" "-r" "--recursive" "--verbose" "-q" "-v"
  "-n" "-N" "-1" "-9" "--fast" "--best")
OPT4=("--version" "-V")
function undesired() {
  { timeout $TIMEOUT $REDUCED_BIN notexist 2>$LOG; }
  crash $? && exit 1

  { timeout $TIMEOUT $REDUCED_BIN 2>$LOG; }
  crash $? && exit 1

  # keeping the error message in the following cases:
  for opt in ${OPT1[@]}; do
    { timeout $TIMEOUT $REDUCED_BIN $opt; } &>$LOG
    cat $LOG | tail -n 17 &>log2
    diff -q references/side1 log2 >&/dev/null || exit 1
    rm -rf log*
  done

  for opt in ${OPT2[@]}; do
    { timeout $TIMEOUT $REDUCED_BIN $opt; } &>$LOG
    cat $LOG | tail -n 14 &>log2
    diff -q references/side2 log2 >&/dev/null || exit 1
    rm -rf log*
  done

  for opt in ${OPT3[@]}; do
    { timeout $TIMEOUT $REDUCED_BIN $opt; } 2>$LOG
    diff -q references/side3 $LOG >&/dev/null || exit 1
    rm -rf log*
  done

  for opt in ${OPT4[@]}; do
    { timeout $TIMEOUT $REDUCED_BIN $opt; } &>$LOG
    diff -q references/side4 $LOG >&/dev/null || exit 1
    rm -rf log*
  done

  echo "1234" >foo
  $ORIGIN_BIN -c <foo >foo.gz 2>/dev/null
  for opt in ${OPT0[@]}; do
    { timeout $TIMEOUT $REDUCED_BIN -d $opt <foo.gz >sample1.tst; } 2>$LOG
    { timeout $TIMEOUT $REDUCED_BIN -c $opt <references/sample1.ref >sample1.rb2; } 2>$LOG
    crash $? && exit 1
  done

  echo "1234" >bar
  $ORIGIN_BIN -c <bar >bar.gz 2>/dev/null
  for opt in ${OPT3[@]}; do
    { timeout $TIMEOUT $REDUCED_BIN -d $opt <bar.gz >sample1.tst; } 2>$LOG
    { timeout $TIMEOUT $REDUCED_BIN -c $opt <references/sample1.ref >sample1.rb2; } 2>$LOG
    crash $? && exit 1
  done
  return 0
}

function desired_disaster() {
  case $1 in
  memory)
    MESSAGE="out of memory"
    disired_disaster_mem "$MESSAGE" || exit 1
    ;;
  file)
    MESSAGE="Bad file descriptor"
    disired_disaster_file "$MESSAGE" || exit 1
    ;;
  *)
    return 1
    ;;
  esac
  return 0
}

main
