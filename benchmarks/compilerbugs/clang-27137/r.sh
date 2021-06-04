#!/bin/bash
BADCC1=()
BADCC2=()
BADCC3=("/root/installs/llvm-3.7.0/bin/clang -O3")
MODE=("-m32")

# need to configure this part
#BADCC1=("clang -O3")  # compilation failures
#BADCC2=() # exec failures
#BADCC3=() # wrong results
#MODE=-m64

readonly GOODCC=("/root/installs/gcc-4.8.2/bin/gcc -m32 -O0")
 
readonly TIMEOUTCC=10
readonly TIMEOUTEXE=2
readonly TIMEOUTCCOMP=10
# flag to control whether to use CompCert to validate the test program.
readonly USE_COMPCERT=true
readonly CFILE=small.c
readonly CFLAG="-o t"
readonly CLANGFC="/root/installs/llvm-3.7.0/bin/clang -w -m64 -O0 -Wall -fwrapv -ftrapv -fsanitize=undefined,address"
readonly CLANG_MEM_SANITIZER="/root/installs/llvm-3.7.0/bin/clang -w -O0 -m64 -fsanitize=memory"

#################################################################################

### check for undefined behaviors first (from creduce scripts)

rm -f out*.txt

if
clang-8 -Wfatal-errors -pedantic -Wall -Wsystem-headers -O0 -c $CFILE  >out.txt 2>&1 &&\
! grep -q 'conversions than data arguments' out.txt &&\
! grep -q 'incompatible redeclaration' out.txt &&\
! grep -q 'ordered comparison between pointer' out.txt &&\
! grep -q 'eliding middle term' out.txt &&\
#! grep -q 'end of non-void function' out.txt &&\
! grep -q 'invalid in C99' out.txt &&\
! grep -q 'specifies type' out.txt &&\
! grep -q 'should return a value' out.txt &&\
#! grep -q 'uninitialized' out.txt &&\
! grep -q 'incompatible pointer to' out.txt &&\
! grep -q 'incompatible integer to' out.txt &&\
! grep -q 'type specifier missing' out.txt &&\
gcc -Wfatal-errors -Wall -Wextra -Wsystem-headers -O0 $CFILE >outa.txt 2>&1 &&\
#  ! grep -q uninitialized outa.txt &&\
! grep -q 'division by zero' outa.txt &&\
! grep -q 'without a cast' outa.txt &&\
#! grep -q 'control reaches end' outa.txt &&\
! grep -q 'return type defaults' outa.txt &&\
! grep -q 'cast from pointer to integer' outa.txt &&\
! grep -q 'useless type name in empty declaration' outa.txt &&\
! grep -q 'no semicolon at end' outa.txt &&\
! grep -q 'type defaults to' outa.txt &&\
! grep -q 'too few arguments for format' outa.txt &&\
! grep -q 'incompatible pointer' outa.txt &&\
! grep -q 'ordered comparison of pointer with integer' outa.txt &&\
! grep -q 'declaration does not declare anything' outa.txt &&\
! grep -q 'expects type' outa.txt &&\
! grep -q 'pointer from integer' outa.txt &&\
#  ! grep -q 'incompatible implicit' outa.txt &&\
! grep -q 'excess elements in struct initializer' outa.txt &&\
! grep -q 'return type of \‘main\’ is not \‘int\’' outa.txt &&\
! grep -q 'comparison between pointer and integer' outa.txt #&&\
#  frama-c -val-signed-overflow-alarms -val -stop-at-first-alarm -no-val-show-progress -machdep x86_64 -obviously-terminates -precise-unions $CFILE >out_framac.txt 2>&1 &&\
#  ! egrep -i '(user error|assert)' out_framac.txt >/dev/null 2>&1
then
  : # do nothing
else
  exit 1
fi

#
# compcert first
#
if $USE_COMPCERT ; then
  timeout -s 9 $TIMEOUTCCOMP ccomp -interp -fall $CFILE >& /dev/null
  ret=$?
  if [ $ret != 0 ] ; then
    exit 1
  fi
fi
###################################################
# clang memory sanitizer
###################################################
#readonly TEMP_EXE="temp.exe"
#timeout -s 9 $TIMEOUTCC $CLANG_MEM_SANITIZER $CFILE -o $TEMP_EXE > /dev/null
#if [[ $? != 0 ]] ; then
#  exit 1
#fi
#
#readonly MEM_SANITIZER_OUTPUT="mem-sanitizer.output"
#(timeout -s 9 $TIMEOUTEXE ./$TEMP_EXE &> $MEM_SANITIZER_OUTPUT ) &> /dev/null
#if [[ $? != 0 ]] ; then
#  exit 1
#fi
#
#if grep -q "MemorySanitizer" $MEM_SANITIZER_OUTPUT ; then
#  exit 1
#fi
#
#rm $MEM_SANITIZER_OUTPUT $TEMP_EXE



###################################################
# @ clangtkfc @ -O0 to check for undefined behavior
###################################################


#rm -f ./t ./out*.txt
#timeout -s 9 $TIMEOUTCC $CLANGFC $CFLAG $CFILE > /dev/null
#ret=$?
#
#if [ $ret != 0 ] ; then
#  exit 1
#fi
#
#(timeout -s 9 $TIMEOUTEXE ./t >out0.txt 2>&1) >&/dev/null
#ret=$?
#
#if [ $ret != 0 ] ; then
#  exit 1
#fi
#
#if grep -q "runtime error" out0.txt ; then
#  exit 1
#fi
#############################
# iterate over the good ones
#############################


#for cc in "${GOODCC[@]}" ; do
for ((i=0; i < ${#GOODCC[@]} ; ++i )) ; do
  cc=${GOODCC[$i]}
  #echo miao1
  rm -f ./t ./out1.txt
  
  #echo timeout -s 9 $TIMEOUTCC $cc $CFLAG $CFILE
  timeout -s 9 $TIMEOUTCC $cc $CFLAG $CFILE >& /dev/null
  ret=$?
  if [ $ret != 0 ] ; then
    exit 1
  fi
  #echo miao2
  # execute
  (timeout -s 9 $TIMEOUTEXE ./t >out1.txt 2>&1) >&/dev/null
  ret=$?
  if [ $ret != 0 ] ; then
    exit 1
  fi
  #echo miao3
  if [[ "$i" == 0 ]] ; then 
    mv out1.txt out0.txt
    continue
  fi
  
  # compare with reference: out0.txt
  if ! diff -q out0.txt out1.txt >/dev/null ; then
    exit 1
  fi
  #echo miao4
done

#############################
# iterate over the bad ones
#############################
#echo here
for cc in "${BADCC1[@]}" ; do
  for mode in "${MODE[@]}" ; do
    rm -f ./t ./out2.txt
    
    # compile
    (timeout -s 9 $TIMEOUTCC $cc $CFLAG $mode $CFILE >out2.txt 2>&1) >& /dev/null
    if ! grep -q 'internal compiler error' out2.txt && \
    ! grep -q 'PLEASE ATTACH THE FOLLOWING FILES TO THE BUG REPORT' out2.txt && \
    ! grep -q 'clang: error: linker command failed with exit code 1 (use -v to see invocation)' out2.txt 
    then
      exit 1
    fi
  done
done

for cc in "${BADCC2[@]}" ; do
  for mode in "${MODE[@]}" ; do
    rm -f ./t ./out2.txt
    
    # compile
    timeout -s 9 $TIMEOUTCC $cc $CFLAG $mode $CFILE >& /dev/null
    ret=$?
    if [ $ret -ne 0 ] ; then
      exit 1
    fi
    
    # execute
    (timeout -s 9 $TIMEOUTEXE ./t >out2.txt 2>&1) >&/dev/null
    ret=$?
    if [ $ret -ne 137 ] ; then
      exit 1
    fi
  done
done

for cc in "${BADCC3[@]}" ; do
  for mode in "${MODE[@]}" ; do
    rm -f ./t ./out2.txt
    
    # compile
    timeout -s 9 $TIMEOUTCC $cc $CFLAG $mode $CFILE >& /dev/null
    ret=$?
    if [ $ret != 0 ] ; then
      exit 1
    fi
    
    # execute
    (timeout -s 9 $TIMEOUTEXE ./t >out2.txt 2>&1) >&/dev/null
    ret=$?
    if [ $ret != 0 ] ; then
      exit 1
    fi
    
    # compare with reference: out0.txt
    if diff -q out0.txt out2.txt >/dev/null ; then
      exit 1
    fi
  done
done

# now we have passed everything, return 0
exit 0
