/* Invoke dup, but avoid some glitches.

   Copyright (C) 2001, 2004, 2005, 2006, 2009 Free Software
   Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* Written by Paul Eggert.  */

#include <config.h>

#include "unistd-safer.h"

#include <fcntl.h>
#include <unistd.h>

/* Like dup, but do not return STDIN_FILENO, STDOUT_FILENO, or
   STDERR_FILENO.  */

int
dup_safer (int fd)
{
#if defined F_DUPFD && !REPLACE_FCHDIR
  return fcntl (fd, F_DUPFD, STDERR_FILENO + 1);
#else
  /* fd_safer calls us back, but eventually the recursion unwinds and
     does the right thing.  */
  return fd_safer (dup (fd));
#endif
}

#if GNULIB_CLOEXEC

# include "cloexec.h"

# ifndef O_CLOEXEC
#  define O_CLOEXEC 0
# endif

/* Like dup, but do not return STDIN_FILENO, STDOUT_FILENO, or
   STDERR_FILENO.  If FLAG contains O_CLOEXEC, behave like
   fcntl(F_DUPFD_CLOEXEC) rather than fcntl(F_DUPFD).  */

int
dup_safer_flag (int fd, int flag)
{
  if (flag & O_CLOEXEC)
    {
# if defined F_DUPFD_CLOEXEC && !REPLACE_FCHDIR
      return fcntl (fd, F_DUPFD_CLOEXEC, STDERR_FILENO + 1);
# else
      /* fd_safer_flag calls us back, but eventually the recursion
         unwinds and does the right thing.  */
      fd = dup_cloexec (fd);
      return fd_safer_flag (fd, flag);
# endif
    }
  return dup_safer (fd);
}

#endif
