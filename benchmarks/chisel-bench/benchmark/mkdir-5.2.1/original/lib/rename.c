/* Work around the bug in some systems whereby rename fails when the source
   path has a trailing slash.  The rename functions of SunOS 4.1.1_U1 and
   mips-dec-ultrix4.4 have this bug.
   Copyright (C) 2001-2003 Free Software Foundation, Inc.

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

/* written by Volker Borchert */

#if HAVE_CONFIG_H
# include <config.h>
#endif
#undef rename

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dirname.h"
#include "xalloc.h"

/* Rename the file SRC_PATH to DST_PATH, removing any trailing
   slashes from SRC_PATH.  Needed for SunOS 4.1.1_U1.  */

int
rpl_rename (const char *src_path, const char *dst_path)
{
  char *src_temp;
  int ret_val;
  size_t s_len = strlen (src_path);

  if (s_len && src_path[s_len - 1] == '/')
    {
      src_temp = xstrdup (src_path);
      strip_trailing_slashes (src_temp);
    }
  else
    src_temp = (char *) src_path;

  ret_val = rename (src_temp, dst_path);

  if (src_temp != src_path)
    free (src_temp);

  return ret_val;
}
