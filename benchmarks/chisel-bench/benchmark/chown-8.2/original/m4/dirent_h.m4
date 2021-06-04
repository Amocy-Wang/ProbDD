# dirent_h.m4 serial 7
dnl Copyright (C) 2008-2009 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

dnl Written by Bruno Haible.

AC_DEFUN([gl_DIRENT_H],
[
  dnl Use AC_REQUIRE here, so that the default behavior below is expanded
  dnl once only, before all statements that occur in other macros.
  AC_REQUIRE([gl_DIRENT_H_DEFAULTS])

  dnl Execute this unconditionally, because DIRENT_H may be set by other
  dnl modules, after this code is executed.
  gl_CHECK_NEXT_HEADERS([dirent.h])
])

dnl Unconditionally enables the replacement of <dirent.h>.
AC_DEFUN([gl_REPLACE_DIRENT_H],
[
  AC_REQUIRE([gl_DIRENT_H_DEFAULTS])
  DIRENT_H='dirent.h'
])

AC_DEFUN([gl_DIRENT_MODULE_INDICATOR],
[
  dnl Use AC_REQUIRE here, so that the default settings are expanded once only.
  AC_REQUIRE([gl_DIRENT_H_DEFAULTS])
  GNULIB_[]m4_translit([$1],[abcdefghijklmnopqrstuvwxyz./-],[ABCDEFGHIJKLMNOPQRSTUVWXYZ___])=1
])

AC_DEFUN([gl_DIRENT_H_DEFAULTS],
[
  AC_REQUIRE([gl_UNISTD_H_DEFAULTS]) dnl for REPLACE_FCHDIR
  GNULIB_DIRFD=0;       AC_SUBST([GNULIB_DIRFD])
  GNULIB_FDOPENDIR=0;   AC_SUBST([GNULIB_FDOPENDIR])
  GNULIB_SCANDIR=0;     AC_SUBST([GNULIB_SCANDIR])
  GNULIB_ALPHASORT=0;   AC_SUBST([GNULIB_ALPHASORT])
  dnl Assume proper GNU behavior unless another module says otherwise.
  HAVE_DECL_DIRFD=1;    AC_SUBST([HAVE_DECL_DIRFD])
  HAVE_FDOPENDIR=1;     AC_SUBST([HAVE_FDOPENDIR])
  HAVE_SCANDIR=1;       AC_SUBST([HAVE_SCANDIR])
  HAVE_ALPHASORT=1;     AC_SUBST([HAVE_ALPHASORT])
  REPLACE_CLOSEDIR=0;   AC_SUBST([REPLACE_CLOSEDIR])
  REPLACE_FDOPENDIR=0;  AC_SUBST([REPLACE_FDOPENDIR])
  REPLACE_OPENDIR=0;    AC_SUBST([REPLACE_OPENDIR])
  DIRENT_H='';          AC_SUBST([DIRENT_H])
])
