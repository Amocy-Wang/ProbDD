/* -*- buffer-read-only: t -*- vi: set ro: */
/* DO NOT EDIT! GENERATED AUTOMATICALLY! */
#line 1
/*
 * Copyright (C) 2008-2009 Free Software Foundation
 * Written by Simon Josefsson
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

#include <config.h>

#include <string.h>

#include <stdio.h>
#include <stdlib.h>

#include "zerosize-ptr.h"

#define ASSERT(expr) \
  do									     \
    {									     \
      if (!(expr))							     \
	{								     \
	  fprintf (stderr, "%s:%d: assertion failed\n", __FILE__, __LINE__); \
	  fflush (stderr);						     \
	  abort ();							     \
	}								     \
    }									     \
  while (0)

int
main (void)
{
  /* Test equal / not equal distinction.  */
  ASSERT (memcmp (zerosize_ptr (), zerosize_ptr (), 0) == 0);
  ASSERT (memcmp ("foo", "foobar", 2) == 0);
  ASSERT (memcmp ("foo", "foobar", 3) == 0);
  ASSERT (memcmp ("foo", "foobar", 4) != 0);
  ASSERT (memcmp ("foo", "bar", 1) != 0);
  ASSERT (memcmp ("foo", "bar", 3) != 0);

  /* Test less / equal / greater distinction.  */
  ASSERT (memcmp ("foo", "moo", 4) < 0);
  ASSERT (memcmp ("moo", "foo", 4) > 0);
  ASSERT (memcmp ("oomph", "oops", 3) < 0);
  ASSERT (memcmp ("oops", "oomph", 3) > 0);
  ASSERT (memcmp ("foo", "foobar", 4) < 0);
  ASSERT (memcmp ("foobar", "foo", 4) > 0);

  /* Some old versions of memcmp were not 8-bit clean.  */
  ASSERT (memcmp ("\100", "\201", 1) < 0);
  ASSERT (memcmp ("\201", "\100", 1) > 0);
  ASSERT (memcmp ("\200", "\201", 1) < 0);
  ASSERT (memcmp ("\201", "\200", 1) > 0);

  /* The Next x86 OpenStep bug shows up only when comparing 16 bytes
     or more and with at least one buffer not starting on a 4-byte boundary.
     William Lewis provided this test program.   */
  {
    char foo[21];
    char bar[21];
    int i;
    for (i = 0; i < 4; i++)
      {
	char *a = foo + i;
	char *b = bar + i;
	strcpy (a, "--------01111111");
	strcpy (b, "--------10000000");
	ASSERT (memcmp (a, b, 16) < 0);
      }
  }

  return 0;
}
