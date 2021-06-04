# sha256.m4 serial 4
dnl Copyright (C) 2005, 2008, 2009 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

AC_DEFUN([gl_SHA256],
[
  AC_LIBOBJ([sha256])

  dnl Prerequisites of lib/sha256.c.
  AC_REQUIRE([gl_BIGENDIAN])
  AC_REQUIRE([AC_C_INLINE])
])
