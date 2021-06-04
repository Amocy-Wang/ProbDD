#!/bin/bash

export BENCHMARK_NAME=mkdir-5.2.1
export BENCHMARK_DIR=$CHISEL_BENCHMARK_HOME/benchmark/$BENCHMARK_NAME/merged
export SRC=$BENCHMARK_DIR/$BENCHMARK_NAME.c
export ORIGIN_BIN=$BENCHMARK_DIR/$BENCHMARK_NAME.origin
export REDUCED_BIN=$BENCHMARK_DIR/$BENCHMARK_NAME.reduced
export TIMEOUT="-k 0.1 0.1"
export LOG=$BENCHMARK_DIR/log.txt

source $CHISEL_BENCHMARK_HOME/benchmark/test-base.sh

function clean() {
  rm -rf d1 file temp1 temp2 $LOG $REDUCED_BIN
  return 0
}

function run() {
  rm -rf d1
  { timeout $TIMEOUT $REDUCED_BIN $1 $2; } >&$LOG || exit 1
  temp1=$(ls -ald $2 2>/dev/null | cut -d ' ' -f 1,2,3,4)
  rm -rf d1 >&/dev/null
  /bin/mkdir $1 $2
  temp2=$(ls -ald $2 2>/dev/null | cut -d ' ' -f 1,2,3,4)
  rm -rf $2 >&/dev/null
  if [[ $temp1 == $temp2 ]]; then
    return 0
  else
    return 1
  fi
}

function run_error() {
  rm -rf d1 >&/dev/null
  { timeout $TIMEOUT $REDUCED_BIN $1 $2; } >&temp1 && exit 1
  rm -rf d1 >&/dev/null
  { $ORIGIN_BIN $1 $2; } >&temp2
  temp1=$(head -n 1 temp1 | cut -d ' ' -f 2,3)
  temp2=$(head -n 1 temp2 | cut -d ' ' -f 2,3)
  if [[ $temp1 == $temp2 ]]; then
    return 0
  else
    return 1
  fi
}

# Default Options: -m, -p
function desired() {
  run "" d1 || exit 1
  run_error "" d1/d2 || exit 1
  run_error "-m 123124" d1/d2 || exit 1
  run_error "-m" d1/d2 || exit 1
  run "-m 400" d1 || exit 1
  run "-m 555" d1 || exit 1
  run "-m 644" d1 || exit 1
  run "-m 610" d1 || exit 1
  run "-m 777" d1 || exit 1
  run "-p" d1/d2 || exit 1
  rm -rf d1
  run "-p" d1/d2/d3/d4 || exit 1
  rm -rf d1
  /bin/mkdir d1
  run "-p" d1 || exit 1
  rm -rf d1
  /bin/mkdir d1
  run "-p" d1/d2 || exit 1
  rm -rf d1
  return 0
}

OPT=("-m" "-p" "-v" "--help")
function undesired() {
  export srcdir=$(pwd)/../
  export PATH="$(pwd):$PATH"
  { timeout $TIMEOUT $REDUCED_BIN; } >&/dev/null
  crash $? && exit 1
  touch file
  for opt in ${OPT[@]}; do
    { timeout $TIMEOUT $REDUCED_BIN $opt file; } >&/dev/null
    crash $? && exit 1
  done
  return 0
}

function run_disaster() {
  rm -rf d1
  { timeout $TIMEOUT $REDUCED_BIN $1 $2; } >&$LOG
  grep -q -E "$3" $LOG
  if [[ $? -gt 0 ]]; then
    exit 1
  fi
  return 0
}

function desired_disaster() {
  case $1 in
  memory)
    MESSAGE="memory exhausted"
    ;;
  file) # mkdir does not cause this error
    return 0
    ;;
  *)
    return 1
    ;;
  esac
  run_disaster "-m 400" d1 "$MESSAGE" || exit 1
  run_disaster "-m 555" d1 "$MESSAGE" || exit 1
  run_disaster "-m 644" d1 "$MESSAGE" || exit 1
  run_disaster "-m 610" d1 "$MESSAGE" || exit 1
  run_disaster "-m 777" d1 "$MESSAGE" || exit 1
  rm -rf d1
  return 0
}

main
