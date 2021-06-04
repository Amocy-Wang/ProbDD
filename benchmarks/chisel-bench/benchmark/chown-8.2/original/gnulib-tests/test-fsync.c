/* -*- buffer-read-only: t -*- vi: set ro: */
/* DO NOT EDIT! GENERATED AUTOMATICALLY! */
#line 1
/* Test of fsync() function.
   Copyright (C) 2008, 2009 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

#include <config.h>

#include <errno.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define ASSERT(expr) \
  do                                                                         \
    {                                                                        \
      if (!(expr))                                                           \
        {                                                                    \
          fprintf (stderr, "%s:%d: assertion failed\n", __FILE__, __LINE__); \
          fflush (stderr);                                                   \
          abort ();                                                          \
        }                                                                    \
    }                                                                        \
  while (0)

int
main (void)
{
  int fd;
  const char *file = "test-fsync.txt";

  if (fsync (0) != 0)
    ASSERT (errno == EINVAL);
  fd = open (file, O_WRONLY|O_CREAT|O_TRUNC, 0644);
  ASSERT (0 <= fd);
  ASSERT (write (fd, "hello", 5) == 5);
  ASSERT (fsync (fd) == 0);
  ASSERT (close (fd) == 0);
  ASSERT (unlink (file) == 0);

  return 0;
}
