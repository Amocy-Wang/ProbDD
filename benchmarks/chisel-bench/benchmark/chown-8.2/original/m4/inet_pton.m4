# inet_pton.m4 serial 9
dnl Copyright (C) 2006, 2008, 2009 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

AC_DEFUN([gl_INET_PTON],
[
  dnl Persuade Solaris <arpa/inet.h> to declare inet_pton.
  AC_REQUIRE([gl_USE_SYSTEM_EXTENSIONS])

  gl_REPLACE_ARPA_INET_H

  dnl Most platforms that provide inet_pton define it in libc.
  dnl Solaris 8..10 provide inet_pton in libnsl instead.
  gl_save_LIBS=$LIBS
  AC_SEARCH_LIBS([inet_pton], [nsl], [],
    [AC_REPLACE_FUNCS([inet_pton])])
  LIBS=$gl_save_LIBS
  INET_PTON_LIB=
  if test "$ac_cv_search_inet_pton" != "no" &&
     test "$ac_cv_search_inet_pton" != "none required"; then
    INET_PTON_LIB="$ac_cv_search_inet_pton"
  fi
  AC_SUBST([INET_PTON_LIB])

  gl_PREREQ_INET_PTON
])

# Prerequisites of lib/inet_pton.c.
AC_DEFUN([gl_PREREQ_INET_PTON], [
  AC_CHECK_DECLS([inet_pton],,,[#include <arpa/inet.h>])
  if test $ac_cv_have_decl_inet_pton = no; then
    HAVE_DECL_INET_PTON=0
  fi
  AC_REQUIRE([gl_SOCKET_FAMILIES])
  AC_REQUIRE([AC_C_RESTRICT])
])
