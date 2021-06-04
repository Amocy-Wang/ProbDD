#!/bin/bash

export BENCHMARK_NAME=tar-1.14
export BENCHMARK_DIR=$CHISEL_BENCHMARK_HOME/benchmark/$BENCHMARK_NAME/merged
export SRC=$BENCHMARK_DIR/$BENCHMARK_NAME.c
export ORIGIN_BIN=$BENCHMARK_DIR/$BENCHMARK_NAME.origin
export REDUCED_BIN=$BENCHMARK_DIR/$BENCHMARK_NAME.reduced
export TIMEOUT="-k 2 2"
export LOG=$BENCHMARK_DIR/log.txt

source $CHISEL_BENCHMARK_HOME/benchmark/test-base.sh

TIMEOUT_LOW="timeout -k 0.4 0.4"

function clean() {
  chmod 777 -Rf f* b*
  rm -rf $BIN f* b*
  find . -not -path "./optional*" -not -path "./afl_crash*" \
    -not -path "./reducer-out*" \
    -not -path "./chisel-out*" \
    -not -path "./lib*" \
    -not -path "./tar-1.14.c.chisel.c" \
    -not -path "./tar-1.14.c.reduced.c" \
    -not -path "./*bin*" \
    -not -path "./status*" \
    -not -path "./*json" \
    -not -path "./tests*" -not -path "./tar*" \
    -not -path "./test*" \
    -not -path "./afl_input*" -not -path "./Makefile" -not -path "./setenv" \
    -not -path "./.config" -delete >&/dev/null
  return 0
}

function desired() {
  if [[ $1 == "-fsanitize=leak" ]]; then # ignore leak sanitizer
    return 0
  fi
  cp $REDUCED_BIN tar
  for file in $(ls tests/tar*); do
    { timeout $TIMEOUT sh -e $file; } >&$LOG || exit 1
    rm -rf f* b*
  done
  return 0
}

function desired_disaster() {
  case $1 in
  memory)
    MESSAGE="exiting now|option|memory exhausted"
    ;;
  file)
    MESSAGE="option|exiting now|Error in writing to standard output"
    ;;
  *)
    return 1
    ;;
  esac
  cp $REDUCED_BIN tar
  for file in $(ls tests/tar*); do
    { timeout $TIMEOUT sh -e $file; } >&$LOG
    rm -rf f* b*
    grep -q -E "$MESSAGE" $LOG || exit 1
  done
  return 0
}

OPT=("" "-R" "-w" "-j" "-T" "--null" "--exclude" "-o" "-Z" "--ungzip" "--no-wildcards"
  "--wildcards-match-slash" "--gzip" "--wildcards" "--files-from" "--backup"
  "--utc" "--index-file" "--totals" "--checkpoint"
  "--suffix" "--after-date" "--newer-mtime" "-N" "--strip-path" "-K" "--one-file-system" "-l"
  "-P" "-W" "--no-wildcards-match-slash" "--no-ignore-case" "--ignore-case" "--exclude-from"
  "--anchored" "--no-anchored" "--directory" "--label" "--use-compress-program" "-V" "--pax-option" "--posix"
  "--portability" "--old-archive" "-B" "--format" "--read-full-records" "-i" "--record-size" "-b"
  "--volno-file" "--new-volume-script" "-F" "-L"
  "-M" "--rsh-command" "--no-same-permissions" "--force-local" "--rmt-command"
  "--modification-time" "--same-owner" "--no-same-owner" "--numeric-owner" "-p" "-g"
  "--ignore-failed-read" "--occurrence" "--owner" "--group" "--mode" "--atime-preserve" "-m"
  "--remove-files" "-k" "--keep-newer-files" "--overwrite"
  "--no-overwrite-dir" "-U" "--recursive-unlink" "-S" "-O" "-G"
  "-A" "-u" "-r")
function undesired() {
  { timeout $TIMEOUT_LOW $REDUCED_BIN; } >&$LOG
  crash $? && exit 1

  { timeout $TIMEOUT_LOW $REDUCED_BIN notexist; } >&$LOG
  crash $? && exit 1

  { timeout $TIMEOUT_LOW $REDUCED_BIN --help; } >&$LOG
  crash $? && exit 1

  { timeout $TIMEOUT_LOW $REDUCED_BIN --version; } >&$LOG
  crash $? && exit 1

  for opt in ${OPT[@]}; do
    { timeout $TIMEOUT_LOW $REDUCED_BIN $opt; } >&$LOG
    crash $? && exit 1
  done

  for c in $(find afl_crash -type f); do
    { timeout $TIMEOUT_LOW $REDUCED_BIN $(cat $c); } >&$LOG
    crash $? && exit 1
  done
  return 0
}

main
