/* A GNU-like <stdlib.h>.

   Copyright (C) 1995, 2001-2004, 2006-2010 Free Software Foundation, Inc.

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

#if __GNUC__ >= 3
@PRAGMA_SYSTEM_HEADER@
#endif

#if defined __need_malloc_and_calloc
/* Special invocation convention inside glibc header files.  */

#@INCLUDE_NEXT@ @NEXT_STDLIB_H@

#else
/* Normal invocation convention.  */

#ifndef _GL_STDLIB_H

/* The include_next requires a split double-inclusion guard.  */
#@INCLUDE_NEXT@ @NEXT_STDLIB_H@

#ifndef _GL_STDLIB_H
#define _GL_STDLIB_H

/* NetBSD 5.0 mis-defines NULL.  */
#include <stddef.h>

/* Solaris declares getloadavg() in <sys/loadavg.h>.  */
#if (@GNULIB_GETLOADAVG@ || defined GNULIB_POSIXCHECK) && @HAVE_SYS_LOADAVG_H@
# include <sys/loadavg.h>
#endif

/* OSF/1 5.1 declares 'struct random_data' in <random.h>, which is included
   from <stdlib.h> if _REENTRANT is defined.  Include it always.  */
#if @HAVE_RANDOM_H@
# include <random.h>
#endif

#if !@HAVE_STRUCT_RANDOM_DATA@ || (@GNULIB_RANDOM_R@ && !@HAVE_RANDOM_R@) \
    || defined GNULIB_POSIXCHECK
# include <stdint.h>
#endif

#if !@HAVE_STRUCT_RANDOM_DATA@
struct random_data
{
  int32_t *fptr;                /* Front pointer.  */
  int32_t *rptr;                /* Rear pointer.  */
  int32_t *state;               /* Array of state values.  */
  int rand_type;                /* Type of random number generator.  */
  int rand_deg;                 /* Degree of random number generator.  */
  int rand_sep;                 /* Distance between front and rear.  */
  int32_t *end_ptr;             /* Pointer behind state table.  */
};
#endif

#if (@GNULIB_MKSTEMP@ || @GNULIB_GETSUBOPT@ || defined GNULIB_POSIXCHECK) && ! defined __GLIBC__
/* On MacOS X 10.3, only <unistd.h> declares mkstemp.  */
/* On Cygwin 1.7.1, only <unistd.h> declares getsubopt.  */
/* But avoid namespace pollution on glibc systems.  */
# include <unistd.h>
#endif

/* The definition of GL_LINK_WARNING is copied here.  */

/* The definition of _GL_ARG_NONNULL is copied here.  */


/* Some systems do not define EXIT_*, despite otherwise supporting C89.  */
#ifndef EXIT_SUCCESS
# define EXIT_SUCCESS 0
#endif
/* Tandem/NSK and other platforms that define EXIT_FAILURE as -1 interfere
   with proper operation of xargs.  */
#ifndef EXIT_FAILURE
# define EXIT_FAILURE 1
#elif EXIT_FAILURE != 1
# undef EXIT_FAILURE
# define EXIT_FAILURE 1
#endif


#ifdef __cplusplus
extern "C" {
#endif

#if @GNULIB_ATOLL@
# if !@HAVE_ATOLL@
/* Parse a signed decimal integer.
   Returns the value of the integer.  Errors are not detected.  */
extern long long atoll (const char *string) _GL_ARG_NONNULL ((1));
# endif
#elif defined GNULIB_POSIXCHECK
# undef atoll
# define atoll(s) \
    (GL_LINK_WARNING ("atoll is unportable - " \
                      "use gnulib module atoll for portability"), \
     atoll (s))
#endif

#if @GNULIB_CALLOC_POSIX@
# if !@HAVE_CALLOC_POSIX@
#  undef calloc
#  define calloc rpl_calloc
extern void * calloc (size_t nmemb, size_t size);
# endif
#elif defined GNULIB_POSIXCHECK
# undef calloc
# define calloc(n,s) \
    (GL_LINK_WARNING ("calloc is not POSIX compliant everywhere - " \
                      "use gnulib module calloc-posix for portability"), \
     calloc (n, s))
#endif

#if @GNULIB_CANONICALIZE_FILE_NAME@
# if @REPLACE_CANONICALIZE_FILE_NAME@
#  define canonicalize_file_name rpl_canonicalize_file_name
# endif
# if !@HAVE_CANONICALIZE_FILE_NAME@ || @REPLACE_CANONICALIZE_FILE_NAME@
extern char *canonicalize_file_name (const char *name) _GL_ARG_NONNULL ((1));
# endif
#elif defined GNULIB_POSIXCHECK
# undef canonicalize_file_name
# define canonicalize_file_name(n)                        \
    (GL_LINK_WARNING ("canonicalize_file_name is unportable - " \
                      "use gnulib module canonicalize-lgpl for portability"), \
     canonicalize_file_name (n))
#endif

#if @GNULIB_GETLOADAVG@
# if !@HAVE_DECL_GETLOADAVG@
/* Store max(NELEM,3) load average numbers in LOADAVG[].
   The three numbers are the load average of the last 1 minute, the last 5
   minutes, and the last 15 minutes, respectively.
   LOADAVG is an array of NELEM numbers.  */
extern int getloadavg (double loadavg[], int nelem) _GL_ARG_NONNULL ((1));
# endif
#elif defined GNULIB_POSIXCHECK
# undef getloadavg
# define getloadavg(l,n) \
    (GL_LINK_WARNING ("getloadavg is not portable - " \
                      "use gnulib module getloadavg for portability"), \
     getloadavg (l, n))
#endif

#if @GNULIB_GETSUBOPT@
/* Assuming *OPTIONP is a comma separated list of elements of the form
   "token" or "token=value", getsubopt parses the first of these elements.
   If the first element refers to a "token" that is member of the given
   NULL-terminated array of tokens:
     - It replaces the comma with a NUL byte, updates *OPTIONP to point past
       the first option and the comma, sets *VALUEP to the value of the
       element (or NULL if it doesn't contain an "=" sign),
     - It returns the index of the "token" in the given array of tokens.
   Otherwise it returns -1, and *OPTIONP and *VALUEP are undefined.
   For more details see the POSIX:2001 specification.
   http://www.opengroup.org/susv3xsh/getsubopt.html */
# if !@HAVE_GETSUBOPT@
extern int getsubopt (char **optionp, char *const *tokens, char **valuep)
     _GL_ARG_NONNULL ((1, 2, 3));
# endif
#elif defined GNULIB_POSIXCHECK
# undef getsubopt
# define getsubopt(o,t,v) \
    (GL_LINK_WARNING ("getsubopt is unportable - " \
                      "use gnulib module getsubopt for portability"), \
     getsubopt (o, t, v))
#endif

#if @GNULIB_MALLOC_POSIX@
# if !@HAVE_MALLOC_POSIX@
#  undef malloc
#  define malloc rpl_malloc
extern void * malloc (size_t size);
# endif
#elif defined GNULIB_POSIXCHECK
# undef malloc
# define malloc(s) \
    (GL_LINK_WARNING ("malloc is not POSIX compliant everywhere - " \
                      "use gnulib module malloc-posix for portability"), \
     malloc (s))
#endif

#if @GNULIB_MKDTEMP@
# if !@HAVE_MKDTEMP@
/* Create a unique temporary directory from TEMPLATE.
   The last six characters of TEMPLATE must be "XXXXXX";
   they are replaced with a string that makes the directory name unique.
   Returns TEMPLATE, or a null pointer if it cannot get a unique name.
   The directory is created mode 700.  */
extern char * mkdtemp (char * /*template*/) _GL_ARG_NONNULL ((1));
# endif
#elif defined GNULIB_POSIXCHECK
# undef mkdtemp
# define mkdtemp(t) \
    (GL_LINK_WARNING ("mkdtemp is unportable - " \
                      "use gnulib module mkdtemp for portability"), \
     mkdtemp (t))
#endif

#if @GNULIB_MKOSTEMP@
# if !@HAVE_MKOSTEMP@
/* Create a unique temporary file from TEMPLATE.
   The last six characters of TEMPLATE must be "XXXXXX";
   they are replaced with a string that makes the file name unique.
   The flags are a bitmask, possibly including O_CLOEXEC (defined in <fcntl.h>)
   and O_TEXT, O_BINARY (defined in "binary-io.h").
   The file is then created, with the specified flags, ensuring it didn't exist
   before.
   The file is created read-write (mask at least 0600 & ~umask), but it may be
   world-readable and world-writable (mask 0666 & ~umask), depending on the
   implementation.
   Returns the open file descriptor if successful, otherwise -1 and errno
   set.  */
extern int mkostemp (char * /*template*/, int /*flags*/) _GL_ARG_NONNULL ((1));
# endif
#elif defined GNULIB_POSIXCHECK
# undef mkostemp
# define mkostemp(t,f) \
    (GL_LINK_WARNING ("mkostemp is unportable - " \
                      "use gnulib module mkostemp for portability"), \
     mkostemp (t, f))
#endif

#if @GNULIB_MKOSTEMPS@
# if !@HAVE_MKOSTEMPS@
/* Create a unique temporary file from TEMPLATE.
   The last six characters of TEMPLATE before a suffix of length
   SUFFIXLEN must be "XXXXXX";
   they are replaced with a string that makes the file name unique.
   The flags are a bitmask, possibly including O_CLOEXEC (defined in <fcntl.h>)
   and O_TEXT, O_BINARY (defined in "binary-io.h").
   The file is then created, with the specified flags, ensuring it didn't exist
   before.
   The file is created read-write (mask at least 0600 & ~umask), but it may be
   world-readable and world-writable (mask 0666 & ~umask), depending on the
   implementation.
   Returns the open file descriptor if successful, otherwise -1 and errno
   set.  */
extern int mkostemps (char * /*template*/, int /*suffixlen*/, int /*flags*/)
     _GL_ARG_NONNULL ((1));
# endif
#elif defined GNULIB_POSIXCHECK
# undef mkostemps
# define mkostemps(t,s,f)                          \
    (GL_LINK_WARNING ("mkostemps is unportable - " \
                      "use gnulib module mkostemps for portability"), \
     mkostemps (t, s, f))
#endif

#if @GNULIB_MKSTEMP@
# if @REPLACE_MKSTEMP@
/* Create a unique temporary file from TEMPLATE.
   The last six characters of TEMPLATE must be "XXXXXX";
   they are replaced with a string that makes the file name unique.
   The file is then created, ensuring it didn't exist before.
   The file is created read-write (mask at least 0600 & ~umask), but it may be
   world-readable and world-writable (mask 0666 & ~umask), depending on the
   implementation.
   Returns the open file descriptor if successful, otherwise -1 and errno
   set.  */
#  define mkstemp rpl_mkstemp
extern int mkstemp (char * /*template*/) _GL_ARG_NONNULL ((1));
# endif
#elif defined GNULIB_POSIXCHECK
# undef mkstemp
# define mkstemp(t) \
    (GL_LINK_WARNING ("mkstemp is unportable - " \
                      "use gnulib module mkstemp for portability"), \
     mkstemp (t))
#endif

#if @GNULIB_MKSTEMPS@
# if !@HAVE_MKSTEMPS@
/* Create a unique temporary file from TEMPLATE.
   The last six characters of TEMPLATE prior to a suffix of length
   SUFFIXLEN must be "XXXXXX";
   they are replaced with a string that makes the file name unique.
   The file is then created, ensuring it didn't exist before.
   The file is created read-write (mask at least 0600 & ~umask), but it may be
   world-readable and world-writable (mask 0666 & ~umask), depending on the
   implementation.
   Returns the open file descriptor if successful, otherwise -1 and errno
   set.  */
extern int mkstemps (char * /*template*/, int /*suffixlen*/)
     _GL_ARG_NONNULL ((1));
# endif
#elif defined GNULIB_POSIXCHECK
# undef mkstemps
# define mkstemps(t,s)                             \
    (GL_LINK_WARNING ("mkstemps is unportable - " \
                      "use gnulib module mkstemps for portability"), \
     mkstemps (t, s))
#endif

#if @GNULIB_PUTENV@
# if @REPLACE_PUTENV@
#  undef putenv
#  define putenv rpl_putenv
extern int putenv (char *string) _GL_ARG_NONNULL ((1));
# endif
#endif

#if @GNULIB_RANDOM_R@
# if !@HAVE_RANDOM_R@

#  ifndef RAND_MAX
#   define RAND_MAX 2147483647
#  endif

int srandom_r (unsigned int seed, struct random_data *rand_state)
     _GL_ARG_NONNULL ((2));
int initstate_r (unsigned int seed, char *buf, size_t buf_size,
                 struct random_data *rand_state)
     _GL_ARG_NONNULL ((2, 4));
int setstate_r (char *arg_state, struct random_data *rand_state)
     _GL_ARG_NONNULL ((1, 2));
int random_r (struct random_data *buf, int32_t *result)
     _GL_ARG_NONNULL ((1, 2));
# endif
#elif defined GNULIB_POSIXCHECK
# undef random_r
# define random_r(b,r)                            \
    (GL_LINK_WARNING ("random_r is unportable - " \
                      "use gnulib module random_r for portability"), \
     random_r (b,r))
# undef initstate_r
# define initstate_r(s,b,sz,r)                       \
    (GL_LINK_WARNING ("initstate_r is unportable - " \
                      "use gnulib module random_r for portability"), \
     initstate_r (s,b,sz,r))
# undef srandom_r
# define srandom_r(s,r)                            \
    (GL_LINK_WARNING ("srandom_r is unportable - " \
                      "use gnulib module random_r for portability"), \
     srandom_r (s,r))
# undef setstate_r
# define setstate_r(a,r)                                    \
    (GL_LINK_WARNING ("setstate_r is unportable - " \
                      "use gnulib module random_r for portability"), \
     setstate_r (a,r))
#endif

#if @GNULIB_REALLOC_POSIX@
# if !@HAVE_REALLOC_POSIX@
#  undef realloc
#  define realloc rpl_realloc
extern void * realloc (void *ptr, size_t size);
# endif
#elif defined GNULIB_POSIXCHECK
# undef realloc
# define realloc(p,s) \
    (GL_LINK_WARNING ("realloc is not POSIX compliant everywhere - " \
                      "use gnulib module realloc-posix for portability"), \
     realloc (p, s))
#endif

#if @GNULIB_REALPATH@
# if @REPLACE_REALPATH@
#  define realpath rpl_realpath
# endif
# if !@HAVE_REALPATH@ || @REPLACE_REALPATH@
extern char *realpath (const char *name, char *resolved) _GL_ARG_NONNULL ((1));
# endif
#elif defined GNULIB_POSIXCHECK
# undef realpath
# define realpath(n,r)                        \
    (GL_LINK_WARNING ("realpath is unportable - use gnulib module " \
                      "canonicalize or canonicalize-lgpl for portability"), \
     realpath (n, r))
#endif

#if @GNULIB_RPMATCH@
# if !@HAVE_RPMATCH@
/* Test a user response to a question.
   Return 1 if it is affirmative, 0 if it is negative, or -1 if not clear.  */
extern int rpmatch (const char *response) _GL_ARG_NONNULL ((1));
# endif
#elif defined GNULIB_POSIXCHECK
# undef rpmatch
# define rpmatch(r) \
    (GL_LINK_WARNING ("rpmatch is unportable - " \
                      "use gnulib module rpmatch for portability"), \
     rpmatch (r))
#endif

#if @GNULIB_SETENV@
# if @REPLACE_SETENV@
#  undef setenv
#  define setenv rpl_setenv
# endif
# if !@HAVE_SETENV@ || @REPLACE_SETENV@
/* Set NAME to VALUE in the environment.
   If REPLACE is nonzero, overwrite an existing value.  */
extern int setenv (const char *name, const char *value, int replace)
     _GL_ARG_NONNULL ((1));
# endif
#elif defined GNULIB_POSIXCHECK
# undef setenv
# define setenv(n,v,o)                                                  \
    (GL_LINK_WARNING ("setenv is unportable - "                         \
                      "use gnulib module setenv for portability"),      \
     setenv (n, v, o))
#endif

#if @GNULIB_STRTOD@
# if @REPLACE_STRTOD@
#  define strtod rpl_strtod
# endif
# if !@HAVE_STRTOD@ || @REPLACE_STRTOD@
 /* Parse a double from STRING, updating ENDP if appropriate.  */
extern double strtod (const char *str, char **endp) _GL_ARG_NONNULL ((1));
# endif
#elif defined GNULIB_POSIXCHECK
# undef strtod
# define strtod(s, e)                           \
    (GL_LINK_WARNING ("strtod is unportable - " \
                      "use gnulib module strtod for portability"), \
     strtod (s, e))
#endif

#if @GNULIB_STRTOLL@
# if !@HAVE_STRTOLL@
/* Parse a signed integer whose textual representation starts at STRING.
   The integer is expected to be in base BASE (2 <= BASE <= 36); if BASE == 0,
   it may be decimal or octal (with prefix "0") or hexadecimal (with prefix
   "0x").
   If ENDPTR is not NULL, the address of the first byte after the integer is
   stored in *ENDPTR.
   Upon overflow, the return value is LLONG_MAX or LLONG_MIN, and errno is set
   to ERANGE.  */
extern long long strtoll (const char *string, char **endptr, int base)
     _GL_ARG_NONNULL ((1));
# endif
#elif defined GNULIB_POSIXCHECK
# undef strtoll
# define strtoll(s,e,b) \
    (GL_LINK_WARNING ("strtoll is unportable - " \
                      "use gnulib module strtoll for portability"), \
     strtoll (s, e, b))
#endif

#if @GNULIB_STRTOULL@
# if !@HAVE_STRTOULL@
/* Parse an unsigned integer whose textual representation starts at STRING.
   The integer is expected to be in base BASE (2 <= BASE <= 36); if BASE == 0,
   it may be decimal or octal (with prefix "0") or hexadecimal (with prefix
   "0x").
   If ENDPTR is not NULL, the address of the first byte after the integer is
   stored in *ENDPTR.
   Upon overflow, the return value is ULLONG_MAX, and errno is set to
   ERANGE.  */
extern unsigned long long strtoull (const char *string, char **endptr, int base)
     _GL_ARG_NONNULL ((1));
# endif
#elif defined GNULIB_POSIXCHECK
# undef strtoull
# define strtoull(s,e,b) \
    (GL_LINK_WARNING ("strtoull is unportable - " \
                      "use gnulib module strtoull for portability"), \
     strtoull (s, e, b))
#endif

#if @GNULIB_UNSETENV@
# if @REPLACE_UNSETENV@
#  undef unsetenv
#  define unsetenv rpl_unsetenv
# endif
# if !@HAVE_UNSETENV@ || @REPLACE_UNSETENV@
/* Remove the variable NAME from the environment.  */
extern int unsetenv (const char *name) _GL_ARG_NONNULL ((1));
# endif
#elif defined GNULIB_POSIXCHECK
# undef unsetenv
# define unsetenv(n)                                                    \
    (GL_LINK_WARNING ("unsetenv is unportable - "                       \
                      "use gnulib module unsetenv for portability"),    \
     unsetenv (n))
#endif

#ifdef __cplusplus
}
#endif

#endif /* _GL_STDLIB_H */
#endif /* _GL_STDLIB_H */
#endif
