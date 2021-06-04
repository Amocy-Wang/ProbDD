/* xstrtoimax.c -- A more useful interface to strtoimax.
   Copyright (C) 2001, 2003 Free Software Foundation, Inc.

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

/* Cloned by Jim Meyering. */

#if HAVE_CONFIG_H
# include <config.h>
#endif

#if HAVE_INTTYPES_H
# include <inttypes.h>
#elif HAVE_STDINT_H
# include <stdint.h>
#endif

#define __strtol strtoimax
#define __strtol_t intmax_t
#define __xstrtol xstrtoimax
#ifdef INTMAX_MAX
# define STRTOL_T_MINIMUM INTMAX_MIN
# define STRTOL_T_MAXIMUM INTMAX_MAX
#endif
#include "xstrtol.c"
