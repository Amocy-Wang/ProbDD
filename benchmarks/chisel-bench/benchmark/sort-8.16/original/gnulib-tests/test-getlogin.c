/* Test of getting user name.
   Copyright (C) 2010-2012 Free Software Foundation, Inc.

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

/* Written by Bruno Haible <bruno@clisp.org>, 2010.  */

#include <config.h>

#include <unistd.h>

#include "signature.h"
SIGNATURE_CHECK (getlogin, char *, (void));

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "macros.h"

int
main (void)
{
  char *buf;

  /* Test value.  */
  buf = getlogin ();
  if (buf == NULL)
    {
      /* getlogin() fails when stdin is not connected to a tty.  */
      ASSERT (errno == ENOTTY
              || errno == EINVAL /* seen on Linux/SPARC */
             );
#if !defined __hpux /* On HP-UX 11.11 it fails anyway.  */
      ASSERT (! isatty (0));
#endif
      fprintf (stderr, "Skipping test: stdin is not a tty.\n");
      return 77;
    }

  /* Compare against the value from the environment.  */
#if !((defined _WIN32 || defined __WIN32__) && !defined __CYGWIN__)
  /* Unix platform */
  {
    const char *name = getenv ("LOGNAME");
    if (name == NULL || name[0] == '\0')
      name = getenv ("USER");
    if (name != NULL && name[0] != '\0')
      ASSERT (strcmp (buf, name) == 0);
  }
#endif
#if (defined _WIN32 || defined __WIN32__) && !defined __CYGWIN__
  /* Native Windows platform.
     Note: This test would fail on Cygwin in an ssh session, because sshd
     sets USERNAME=SYSTEM.  */
  {
    const char *name = getenv ("USERNAME");
    if (name != NULL && name[0] != '\0')
      ASSERT (strcmp (buf, name) == 0);
  }
#endif

  return 0;
}
