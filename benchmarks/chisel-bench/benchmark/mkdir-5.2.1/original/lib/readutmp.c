/* GNU's read utmp module.
   Copyright (C) 1992-2001, 2003 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation,
   Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */

/* Written by jla; revised by djm */

#include <config.h>

#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

#include "readutmp.h"
#include "unlocked-io.h"
#include "xalloc.h"

/* Copy UT->ut_name into storage obtained from malloc.  Then remove any
   trailing spaces from the copy, NUL terminate it, and return the copy.  */

char *
extract_trimmed_name (const STRUCT_UTMP *ut)
{
  char *p, *trimmed_name;

  trimmed_name = xmalloc (sizeof (UT_USER (ut)) + 1);
  strncpy (trimmed_name, UT_USER (ut), sizeof (UT_USER (ut)));
  /* Append a trailing space character.  Some systems pad names shorter than
     the maximum with spaces, others pad with NULs.  Remove any spaces.  */
  trimmed_name[sizeof (UT_USER (ut))] = ' ';
  p = strchr (trimmed_name, ' ');
  if (p != NULL)
    *p = '\0';
  return trimmed_name;
}

/* Read the utmp entries corresponding to file FILENAME into freshly-
   malloc'd storage, set *UTMP_BUF to that pointer, set *N_ENTRIES to
   the number of entries, and return zero.  If there is any error,
   return non-zero and don't modify the parameters.  */

#ifdef UTMP_NAME_FUNCTION

int
read_utmp (const char *filename, int *n_entries, STRUCT_UTMP **utmp_buf)
{
  int n_read;
  STRUCT_UTMP *u;
  STRUCT_UTMP *utmp = NULL;

  /* Ignore the return value for now.
     Solaris' utmpname returns 1 upon success -- which is contrary
     to what the GNU libc version does.  In addition, older GNU libc
     versions are actually void.   */
  UTMP_NAME_FUNCTION (filename);

  SET_UTMP_ENT ();

  n_read = 0;
  while ((u = GET_UTMP_ENT ()) != NULL)
    {
      ++n_read;
      utmp = (STRUCT_UTMP *) realloc (utmp, n_read * sizeof (STRUCT_UTMP));
      if (utmp == NULL)
	return 1;
      utmp[n_read - 1] = *u;
    }

  END_UTMP_ENT ();

  *n_entries = n_read;
  *utmp_buf = utmp;

  return 0;
}

#else

int
read_utmp (const char *filename, int *n_entries, STRUCT_UTMP **utmp_buf)
{
  FILE *utmp;
  struct stat file_stats;
  size_t n_read;
  size_t size;
  STRUCT_UTMP *buf;

  utmp = fopen (filename, "r");
  if (utmp == NULL)
    return 1;

  if (fstat (fileno (utmp), &file_stats) != 0)
    {
      int e = errno;
      fclose (utmp);
      errno = e;
      return 1;
    }
  size = file_stats.st_size;
  buf = xmalloc (size);
  n_read = fread (buf, sizeof *buf, size / sizeof *buf, utmp);
  if (ferror (utmp))
    {
      int e = errno;
      free (buf);
      fclose (utmp);
      errno = e;
      return 1;
    }
  if (fclose (utmp) != 0)
    {
      int e = errno;
      free (buf);
      errno = e;
      return 1;
    }

  *n_entries = n_read;
  *utmp_buf = buf;

  return 0;
}

#endif
