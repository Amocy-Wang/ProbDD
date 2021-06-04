# fsync.m4 serial 1
dnl Copyright (C) 2008-2010 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

AC_DEFUN([gl_FUNC_FSYNC],
[
  AC_REQUIRE([gl_UNISTD_H_DEFAULTS])
  AC_CHECK_FUNCS_ONCE([fsync])
  if test $ac_cv_func_fsync = no; then
    HAVE_FSYNC=0
    AC_LIBOBJ([fsync])
    gl_PREREQ_FSYNC
  fi
])

# Prerequisites of lib/fsync.c.
AC_DEFUN([gl_PREREQ_FSYNC], [:])
