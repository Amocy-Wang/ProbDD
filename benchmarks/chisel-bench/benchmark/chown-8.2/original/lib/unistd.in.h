/* -*- buffer-read-only: t -*- vi: set ro: */
/* DO NOT EDIT! GENERATED AUTOMATICALLY! */
#line 1
/* Substitute for and wrapper around <unistd.h>.
   Copyright (C) 2003-2009 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation,
   Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */

#ifndef _GL_UNISTD_H

#if __GNUC__ >= 3
@PRAGMA_SYSTEM_HEADER@
#endif

/* The include_next requires a split double-inclusion guard.  */
#if @HAVE_UNISTD_H@
# @INCLUDE_NEXT@ @NEXT_UNISTD_H@
#endif

#ifndef _GL_UNISTD_H
#define _GL_UNISTD_H

/* NetBSD 5.0 mis-defines NULL.  Also get size_t.  */
#include <stddef.h>

/* mingw doesn't define the SEEK_* or *_FILENO macros in <unistd.h>.  */
#if !(defined SEEK_CUR && defined SEEK_END && defined SEEK_SET)
# include <stdio.h>
#endif

/* mingw fails to declare _exit in <unistd.h>.  */
/* mingw, BeOS, Haiku declare environ in <stdlib.h>, not in <unistd.h>.  */
#include <stdlib.h>

#if ((@GNULIB_WRITE@ && @REPLACE_WRITE@ && @GNULIB_UNISTD_H_SIGPIPE@)   \
     || (@GNULIB_READLINK@ && (!@HAVE_READLINK@ || @REPLACE_READLINK@)) \
     || (@GNULIB_READLINKAT@ && !@HAVE_READLINKAT@))
/* Get ssize_t.  */
# include <sys/types.h>
#endif

/* Get getopt(), optarg, optind, opterr, optopt.  */
#if @GNULIB_UNISTD_H_GETOPT@ && !defined _GL_SYSTEM_GETOPT
# include <getopt.h>
#endif

#if @GNULIB_GETHOSTNAME@
/* Get all possible declarations of gethostname().  */
# if @UNISTD_H_HAVE_WINSOCK2_H@
#  include <winsock2.h>
#  if !defined _GL_SYS_SOCKET_H
#   undef socket
#   define socket		socket_used_without_including_sys_socket_h
#   undef connect
#   define connect		connect_used_without_including_sys_socket_h
#   undef accept
#   define accept		accept_used_without_including_sys_socket_h
#   undef bind
#   define bind			bind_used_without_including_sys_socket_h
#   undef getpeername
#   define getpeername		getpeername_used_without_including_sys_socket_h
#   undef getsockname
#   define getsockname		getsockname_used_without_including_sys_socket_h
#   undef getsockopt
#   define getsockopt		getsockopt_used_without_including_sys_socket_h
#   undef listen
#   define listen		listen_used_without_including_sys_socket_h
#   undef recv
#   define recv			recv_used_without_including_sys_socket_h
#   undef send
#   define send			send_used_without_including_sys_socket_h
#   undef recvfrom
#   define recvfrom		recvfrom_used_without_including_sys_socket_h
#   undef sendto
#   define sendto		sendto_used_without_including_sys_socket_h
#   undef setsockopt
#   define setsockopt		setsockopt_used_without_including_sys_socket_h
#   undef shutdown
#   define shutdown		shutdown_used_without_including_sys_socket_h
#  endif
#  if !defined _GL_SYS_SELECT_H
#   undef select
#   define select		select_used_without_including_sys_select_h
#  endif
# endif
#endif

/* The definition of GL_LINK_WARNING is copied here.  */


/* OS/2 EMX lacks these macros.  */
#ifndef STDIN_FILENO
# define STDIN_FILENO 0
#endif
#ifndef STDOUT_FILENO
# define STDOUT_FILENO 1
#endif
#ifndef STDERR_FILENO
# define STDERR_FILENO 2
#endif

/* Ensure *_OK macros exist.  */
#ifndef F_OK
# define F_OK 0
# define X_OK 1
# define W_OK 2
# define R_OK 4
#endif


/* Declare overridden functions.  */

#ifdef __cplusplus
extern "C" {
#endif


#if @GNULIB_CHOWN@
# if @REPLACE_CHOWN@
#  undef chown
#  define chown rpl_chown
# endif
# if !@HAVE_CHOWN@ || @REPLACE_CHOWN@
/* Change the owner of FILE to UID (if UID is not -1) and the group of FILE
   to GID (if GID is not -1).  Follow symbolic links.
   Return 0 if successful, otherwise -1 and errno set.
   See the POSIX:2001 specification
   <http://www.opengroup.org/susv3xsh/chown.html>.  */
extern int chown (const char *file, uid_t uid, gid_t gid);
# endif
#elif defined GNULIB_POSIXCHECK
# undef chown
# define chown(f,u,g) \
    (GL_LINK_WARNING ("chown fails to follow symlinks on some systems and " \
                      "doesn't treat a uid or gid of -1 on some systems - " \
                      "use gnulib module chown for portability"), \
     chown (f, u, g))
#endif


#if @GNULIB_CLOSE@
# if @REPLACE_CLOSE@
/* Automatically included by modules that need a replacement for close.  */
#  undef close
#  define close rpl_close
extern int close (int);
# endif
#elif @UNISTD_H_HAVE_WINSOCK2_H_AND_USE_SOCKETS@
# undef close
# define close close_used_without_requesting_gnulib_module_close
#elif defined GNULIB_POSIXCHECK
# undef close
# define close(f) \
    (GL_LINK_WARNING ("close does not portably work on sockets - " \
                      "use gnulib module close for portability"), \
     close (f))
#endif


#if @REPLACE_DUP@
# define dup rpl_dup
extern int dup (int);
#endif


#if @GNULIB_DUP2@
# if @REPLACE_DUP2@
#  define dup2 rpl_dup2
# endif
# if !@HAVE_DUP2@ || @REPLACE_DUP2@
/* Copy the file descriptor OLDFD into file descriptor NEWFD.  Do nothing if
   NEWFD = OLDFD, otherwise close NEWFD first if it is open.
   Return newfd if successful, otherwise -1 and errno set.
   See the POSIX:2001 specification
   <http://www.opengroup.org/susv3xsh/dup2.html>.  */
extern int dup2 (int oldfd, int newfd);
# endif
#elif defined GNULIB_POSIXCHECK
# undef dup2
# define dup2(o,n) \
    (GL_LINK_WARNING ("dup2 is unportable - " \
                      "use gnulib module dup2 for portability"), \
     dup2 (o, n))
#endif


#if @GNULIB_DUP3@
/* Copy the file descriptor OLDFD into file descriptor NEWFD, with the
   specified flags.
   The flags are a bitmask, possibly including O_CLOEXEC (defined in <fcntl.h>)
   and O_TEXT, O_BINARY (defined in "binary-io.h").
   Close NEWFD first if it is open.
   Return newfd if successful, otherwise -1 and errno set.
   See the Linux man page at
   <http://www.kernel.org/doc/man-pages/online/pages/man2/dup3.2.html>.  */
# if @HAVE_DUP3@
#  define dup3 rpl_dup3
# endif
extern int dup3 (int oldfd, int newfd, int flags);
#elif defined GNULIB_POSIXCHECK
# undef dup3
# define dup3(o,n,f) \
    (GL_LINK_WARNING ("dup3 is unportable - " \
                      "use gnulib module dup3 for portability"), \
     dup3 (o, n, f))
#endif


#if @GNULIB_ENVIRON@
# if !@HAVE_DECL_ENVIRON@
/* Set of environment variables and values.  An array of strings of the form
   "VARIABLE=VALUE", terminated with a NULL.  */
#  if defined __APPLE__ && defined __MACH__
#   include <crt_externs.h>
#   define environ (*_NSGetEnviron ())
#  else
extern char **environ;
#  endif
# endif
#elif defined GNULIB_POSIXCHECK
# undef environ
# define environ \
    (GL_LINK_WARNING ("environ is unportable - " \
                      "use gnulib module environ for portability"), \
     environ)
#endif


#if @GNULIB_EUIDACCESS@
# if !@HAVE_EUIDACCESS@
/* Like access(), except that it uses the effective user id and group id of
   the current process.  */
extern int euidaccess (const char *filename, int mode);
# endif
#elif defined GNULIB_POSIXCHECK
# undef euidaccess
# define euidaccess(f,m) \
    (GL_LINK_WARNING ("euidaccess is unportable - " \
                      "use gnulib module euidaccess for portability"), \
     euidaccess (f, m))
#endif


#if @GNULIB_FACCESSAT@
# if !@HAVE_FACCESSAT@
int faccessat (int fd, char const *file, int mode, int flag);
# endif
#elif defined GNULIB_POSIXCHECK
# undef faccessat
# define faccessat(d,n,m,f)			    \
    (GL_LINK_WARNING ("faccessat is not portable - " \
                      "use gnulib module faccessat for portability"), \
     faccessat (d, n, m, f))
#endif


#if @GNULIB_FCHDIR@
# if @REPLACE_FCHDIR@
/* Change the process' current working directory to the directory on which
   the given file descriptor is open.
   Return 0 if successful, otherwise -1 and errno set.
   See the POSIX:2001 specification
   <http://www.opengroup.org/susv3xsh/fchdir.html>.  */
extern int fchdir (int /*fd*/);

/* Gnulib internal hooks needed to maintain the fchdir metadata.  */
extern int _gl_register_fd (int fd, const char *filename);
extern void _gl_unregister_fd (int fd);
extern int _gl_register_dup (int oldfd, int newfd);
extern const char *_gl_directory_name (int fd);

# endif
#elif defined GNULIB_POSIXCHECK
# undef fchdir
# define fchdir(f) \
    (GL_LINK_WARNING ("fchdir is unportable - " \
                      "use gnulib module fchdir for portability"), \
     fchdir (f))
#endif


#if @GNULIB_FCHOWNAT@
# if @REPLACE_FCHOWNAT@
#  undef fchownat
#  define fchownat rpl_fchownat
# endif
# if !@HAVE_FCHOWNAT@ || @REPLACE_FCHOWNAT@
extern int fchownat (int fd, char const *file, uid_t owner, gid_t group, int flag);
# endif
#elif defined GNULIB_POSIXCHECK
# undef fchownat
# define fchownat(d,n,o,g,f)			    \
    (GL_LINK_WARNING ("fchownat is not portable - " \
                      "use gnulib module openat for portability"), \
     fchownat (d, n, o, g, f))
#endif


#if @GNULIB_FSYNC@
/* Synchronize changes to a file.
   Return 0 if successful, otherwise -1 and errno set.
   See POSIX:2001 specification
   <http://www.opengroup.org/susv3xsh/fsync.html>.  */
# if !@HAVE_FSYNC@
extern int fsync (int fd);
# endif
#elif defined GNULIB_POSIXCHECK
# undef fsync
# define fsync(fd) \
    (GL_LINK_WARNING ("fsync is unportable - " \
                      "use gnulib module fsync for portability"), \
     fsync (fd))
#endif


#if @GNULIB_FTRUNCATE@
# if !@HAVE_FTRUNCATE@
/* Change the size of the file to which FD is opened to become equal to LENGTH.
   Return 0 if successful, otherwise -1 and errno set.
   See the POSIX:2001 specification
   <http://www.opengroup.org/susv3xsh/ftruncate.html>.  */
extern int ftruncate (int fd, off_t length);
# endif
#elif defined GNULIB_POSIXCHECK
# undef ftruncate
# define ftruncate(f,l) \
    (GL_LINK_WARNING ("ftruncate is unportable - " \
                      "use gnulib module ftruncate for portability"), \
     ftruncate (f, l))
#endif


#if @GNULIB_GETCWD@
/* Include the headers that might declare getcwd so that they will not
   cause confusion if included after this file.  */
# include <stdlib.h>
# if @REPLACE_GETCWD@
/* Get the name of the current working directory, and put it in SIZE bytes
   of BUF.
   Return BUF if successful, or NULL if the directory couldn't be determined
   or SIZE was too small.
   See the POSIX:2001 specification
   <http://www.opengroup.org/susv3xsh/getcwd.html>.
   Additionally, the gnulib module 'getcwd' guarantees the following GNU
   extension: If BUF is NULL, an array is allocated with 'malloc'; the array
   is SIZE bytes long, unless SIZE == 0, in which case it is as big as
   necessary.  */
#  define getcwd rpl_getcwd
extern char * getcwd (char *buf, size_t size);
# endif
#elif defined GNULIB_POSIXCHECK
# undef getcwd
# define getcwd(b,s) \
    (GL_LINK_WARNING ("getcwd is unportable - " \
                      "use gnulib module getcwd for portability"), \
     getcwd (b, s))
#endif


#if @GNULIB_GETDOMAINNAME@
/* Return the NIS domain name of the machine.
   WARNING! The NIS domain name is unrelated to the fully qualified host name
            of the machine.  It is also unrelated to email addresses.
   WARNING! The NIS domain name is usually the empty string or "(none)" when
            not using NIS.

   Put up to LEN bytes of the NIS domain name into NAME.
   Null terminate it if the name is shorter than LEN.
   If the NIS domain name is longer than LEN, set errno = EINVAL and return -1.
   Return 0 if successful, otherwise set errno and return -1.  */
# if !@HAVE_GETDOMAINNAME@
extern int getdomainname(char *name, size_t len);
# endif
#elif defined GNULIB_POSIXCHECK
# undef getdomainname
# define getdomainname(n,l) \
    (GL_LINK_WARNING ("getdomainname is unportable - " \
                      "use gnulib module getdomainname for portability"), \
     getdomainname (n, l))
#endif


#if @GNULIB_GETDTABLESIZE@
# if !@HAVE_GETDTABLESIZE@
/* Return the maximum number of file descriptors in the current process.
   In POSIX, this is same as sysconf (_SC_OPEN_MAX).  */
extern int getdtablesize (void);
# endif
#elif defined GNULIB_POSIXCHECK
# undef getdtablesize
# define getdtablesize() \
    (GL_LINK_WARNING ("getdtablesize is unportable - " \
                      "use gnulib module getdtablesize for portability"), \
     getdtablesize ())
#endif


#if @GNULIB_GETGROUPS@
# if @REPLACE_GETGROUPS@
#  undef getgroups
#  define getgroups rpl_getgroups
# endif
# if !@HAVE_GETGROUPS@ || @REPLACE_GETGROUPS@
/* Return the supplemental groups that the current process belongs to.
   It is unspecified whether the effective group id is in the list.
   If N is 0, return the group count; otherwise, N describes how many
   entries are available in GROUPS.  Return -1 and set errno if N is
   not 0 and not large enough.  Fails with ENOSYS on some systems.  */
int getgroups (int n, gid_t *groups);
# endif
#elif defined GNULIB_POSIXCHECK
# undef getgroups
# define getgroups(n,g)                                                 \
    (GL_LINK_WARNING ("getgroups is unportable - "                      \
                      "use gnulib module getgroups for portability"),   \
     getgroups (n, g))
#endif


#if @GNULIB_GETHOSTNAME@
/* Return the standard host name of the machine.
   WARNING! The host name may or may not be fully qualified.

   Put up to LEN bytes of the host name into NAME.
   Null terminate it if the name is shorter than LEN.
   If the host name is longer than LEN, set errno = EINVAL and return -1.
   Return 0 if successful, otherwise set errno and return -1.  */
# if @UNISTD_H_HAVE_WINSOCK2_H@
#  undef gethostname
#  define gethostname rpl_gethostname
# endif
# if @UNISTD_H_HAVE_WINSOCK2_H@ || !@HAVE_GETHOSTNAME@
extern int gethostname(char *name, size_t len);
# endif
#elif @UNISTD_H_HAVE_WINSOCK2_H@
# undef gethostname
# define gethostname gethostname_used_without_requesting_gnulib_module_gethostname
#elif defined GNULIB_POSIXCHECK
# undef gethostname
# define gethostname(n,l) \
    (GL_LINK_WARNING ("gethostname is unportable - " \
                      "use gnulib module gethostname for portability"), \
     gethostname (n, l))
#endif


#if @GNULIB_GETLOGIN_R@
/* Copies the user's login name to NAME.
   The array pointed to by NAME has room for SIZE bytes.

   Returns 0 if successful.  Upon error, an error number is returned, or -1 in
   the case that the login name cannot be found but no specific error is
   provided (this case is hopefully rare but is left open by the POSIX spec).

   See <http://www.opengroup.org/susv3xsh/getlogin.html>.
 */
# if !@HAVE_DECL_GETLOGIN_R@
extern int getlogin_r (char *name, size_t size);
# endif
#elif defined GNULIB_POSIXCHECK
# undef getlogin_r
# define getlogin_r(n,s) \
    (GL_LINK_WARNING ("getlogin_r is unportable - " \
                      "use gnulib module getlogin_r for portability"), \
     getlogin_r (n, s))
#endif


#if @GNULIB_GETPAGESIZE@
# if @REPLACE_GETPAGESIZE@
#  define getpagesize rpl_getpagesize
extern int getpagesize (void);
# elif !@HAVE_GETPAGESIZE@
/* This is for POSIX systems.  */
#  if !defined getpagesize && defined _SC_PAGESIZE
#   if ! (defined __VMS && __VMS_VER < 70000000)
#    define getpagesize() sysconf (_SC_PAGESIZE)
#   endif
#  endif
/* This is for older VMS.  */
#  if !defined getpagesize && defined __VMS
#   ifdef __ALPHA
#    define getpagesize() 8192
#   else
#    define getpagesize() 512
#   endif
#  endif
/* This is for BeOS.  */
#  if !defined getpagesize && @HAVE_OS_H@
#   include <OS.h>
#   if defined B_PAGE_SIZE
#    define getpagesize() B_PAGE_SIZE
#   endif
#  endif
/* This is for AmigaOS4.0.  */
#  if !defined getpagesize && defined __amigaos4__
#   define getpagesize() 2048
#  endif
/* This is for older Unix systems.  */
#  if !defined getpagesize && @HAVE_SYS_PARAM_H@
#   include <sys/param.h>
#   ifdef EXEC_PAGESIZE
#    define getpagesize() EXEC_PAGESIZE
#   else
#    ifdef NBPG
#     ifndef CLSIZE
#      define CLSIZE 1
#     endif
#     define getpagesize() (NBPG * CLSIZE)
#    else
#     ifdef NBPC
#      define getpagesize() NBPC
#     endif
#    endif
#   endif
#  endif
# endif
#elif defined GNULIB_POSIXCHECK
# undef getpagesize
# define getpagesize() \
    (GL_LINK_WARNING ("getpagesize is unportable - " \
                      "use gnulib module getpagesize for portability"), \
     getpagesize ())
#endif


#if @GNULIB_GETUSERSHELL@
# if !@HAVE_GETUSERSHELL@
/* Return the next valid login shell on the system, or NULL when the end of
   the list has been reached.  */
extern char *getusershell (void);
/* Rewind to pointer that is advanced at each getusershell() call.  */
extern void setusershell (void);
/* Free the pointer that is advanced at each getusershell() call and
   associated resources.  */
extern void endusershell (void);
# endif
#elif defined GNULIB_POSIXCHECK
# undef getusershell
# define getusershell() \
    (GL_LINK_WARNING ("getusershell is unportable - " \
                      "use gnulib module getusershell for portability"), \
     getusershell ())
# undef setusershell
# define setusershell() \
    (GL_LINK_WARNING ("setusershell is unportable - " \
                      "use gnulib module getusershell for portability"), \
     setusershell ())
# undef endusershell
# define endusershell() \
    (GL_LINK_WARNING ("endusershell is unportable - " \
                      "use gnulib module getusershell for portability"), \
     endusershell ())
#endif


#if @GNULIB_LCHOWN@
# if @REPLACE_LCHOWN@
#  undef lchown
#  define lchown rpl_lchown
# endif
# if !@HAVE_LCHOWN@ || @REPLACE_LCHOWN@
/* Change the owner of FILE to UID (if UID is not -1) and the group of FILE
   to GID (if GID is not -1).  Do not follow symbolic links.
   Return 0 if successful, otherwise -1 and errno set.
   See the POSIX:2001 specification
   <http://www.opengroup.org/susv3xsh/lchown.html>.  */
extern int lchown (char const *file, uid_t owner, gid_t group);
# endif
#elif defined GNULIB_POSIXCHECK
# undef lchown
# define lchown(f,u,g) \
    (GL_LINK_WARNING ("lchown is unportable to pre-POSIX.1-2001 " \
                      "systems - use gnulib module lchown for portability"), \
     lchown (f, u, g))
#endif


#if @GNULIB_LINK@
# if @REPLACE_LINK@
#  define link rpl_link
# endif
/* Create a new hard link for an existing file.
   Return 0 if successful, otherwise -1 and errno set.
   See POSIX:2001 specification
   <http://www.opengroup.org/susv3xsh/link.html>.  */
# if !@HAVE_LINK@ || @REPLACE_LINK@
extern int link (const char *path1, const char *path2);
# endif
#elif defined GNULIB_POSIXCHECK
# undef link
# define link(path1,path2) \
    (GL_LINK_WARNING ("link is unportable - " \
                      "use gnulib module link for portability"), \
     link (path1, path2))
#endif

#if @GNULIB_LINKAT@
# if @REPLACE_LINKAT@
#  undef linkat
#  define linkat rpl_linkat
# endif
/* Create a new hard link for an existing file, relative to two
   directories.  FLAG controls whether symlinks are followed.
   Return 0 if successful, otherwise -1 and errno set.  */
# if !@HAVE_LINKAT@ || @REPLACE_LINKAT@
extern int linkat (int fd1, const char *path1, int fd2, const char *path2,
		   int flag);
# endif
#elif defined GNULIB_POSIXCHECK
# undef linkat
# define link(f1,path1,f2,path2,f)		\
    (GL_LINK_WARNING ("linkat is unportable - " \
                      "use gnulib module linkat for portability"), \
     linkat (f1, path1, f2, path2,f))
#endif

#if @GNULIB_LSEEK@
# if @REPLACE_LSEEK@
/* Set the offset of FD relative to SEEK_SET, SEEK_CUR, or SEEK_END.
   Return the new offset if successful, otherwise -1 and errno set.
   See the POSIX:2001 specification
   <http://www.opengroup.org/susv3xsh/lseek.html>.  */
#  define lseek rpl_lseek
   extern off_t lseek (int fd, off_t offset, int whence);
# endif
#elif defined GNULIB_POSIXCHECK
# undef lseek
# define lseek(f,o,w) \
    (GL_LINK_WARNING ("lseek does not fail with ESPIPE on pipes on some " \
                      "systems - use gnulib module lseek for portability"), \
     lseek (f, o, w))
#endif


#if @GNULIB_PIPE2@
/* Create a pipe, applying the given flags when opening the read-end of the
   pipe and the write-end of the pipe.
   The flags are a bitmask, possibly including O_CLOEXEC (defined in <fcntl.h>)
   and O_TEXT, O_BINARY (defined in "binary-io.h").
   Store the read-end as fd[0] and the write-end as fd[1].
   Return 0 upon success, or -1 with errno set upon failure.
   See also the Linux man page at
   <http://www.kernel.org/doc/man-pages/online/pages/man2/pipe2.2.html>.  */
# if @HAVE_PIPE2@
#  define pipe2 rpl_pipe2
# endif
extern int pipe2 (int fd[2], int flags);
#elif defined GNULIB_POSIXCHECK
# undef pipe2
# define pipe2(f,o) \
    (GL_LINK_WARNING ("pipe2 is unportable - " \
                      "use gnulib module pipe2 for portability"), \
     pipe2 (f, o))
#endif


#if @GNULIB_PREAD@
# if @REPLACE_PREAD@
#  define pread rpl_pread
# endif
/* Read at most BUFSIZE bytes from FD into BUF, starting at OFFSET.
   Return the number of bytes placed into BUF if successful, otherwise
   set errno and return -1.  0 indicates EOF.  See the POSIX:2001
   specification <http://www.opengroup.org/susv3xsh/pread.html>.  */
# if !@HAVE_PREAD@ || @REPLACE_PREAD@
  extern ssize_t pread (int fd, void *buf, size_t bufsize, off_t offset);
# endif
#elif defined GNULIB_POSIXCHECK
# undef pread
# define pread(f,b,s,o)			       \
    (GL_LINK_WARNING ("pread is unportable - " \
                      "use gnulib module pread for portability"), \
     pread (f, b, s, o))
#endif


#if @GNULIB_READLINK@
# if @REPLACE_READLINK@
#  define readlink rpl_readlink
# endif
/* Read the contents of the symbolic link FILE and place the first BUFSIZE
   bytes of it into BUF.  Return the number of bytes placed into BUF if
   successful, otherwise -1 and errno set.
   See the POSIX:2001 specification
   <http://www.opengroup.org/susv3xsh/readlink.html>.  */
# if !@HAVE_READLINK@ || @REPLACE_READLINK@
extern ssize_t readlink (const char *file, char *buf, size_t bufsize);
# endif
#elif defined GNULIB_POSIXCHECK
# undef readlink
# define readlink(f,b,s) \
    (GL_LINK_WARNING ("readlink is unportable - " \
                      "use gnulib module readlink for portability"), \
     readlink (f, b, s))
#endif


#if @GNULIB_READLINKAT@
# if !@HAVE_READLINKAT@
ssize_t readlinkat (int fd, char const *file, char *buf, size_t len);
# endif
#elif defined GNULIB_POSIXCHECK
# undef readlinkat
# define readlinkat(d,n,b,l)			     \
    (GL_LINK_WARNING ("readlinkat is not portable - " \
                      "use gnulib module symlinkat for portability"), \
     readlinkat (d, n, b, l))
#endif


#if @GNULIB_RMDIR@
# if @REPLACE_RMDIR@
#  define rmdir rpl_rmdir
/* Remove the directory DIR.  */
extern int rmdir (char const *name);
# endif
#elif defined GNULIB_POSIXCHECK
# undef rmdir
# define rmdir(n) \
    (GL_LINK_WARNING ("rmdir is unportable - " \
                      "use gnulib module rmdir for portability"), \
     rmdir (n))
#endif


#if @GNULIB_SLEEP@
# if @REPLACE_SLEEP@
#  undef sleep
#  define sleep rpl_sleep
# endif
/* Pause the execution of the current thread for N seconds.
   Returns the number of seconds left to sleep.
   See the POSIX:2001 specification
   <http://www.opengroup.org/susv3xsh/sleep.html>.  */
# if !@HAVE_SLEEP@ || @REPLACE_SLEEP@
extern unsigned int sleep (unsigned int n);
# endif
#elif defined GNULIB_POSIXCHECK
# undef sleep
# define sleep(n) \
    (GL_LINK_WARNING ("sleep is unportable - " \
                      "use gnulib module sleep for portability"), \
     sleep (n))
#endif


#if @GNULIB_SYMLINK@
# if @REPLACE_SYMLINK@
#  undef symlink
#  define symlink rpl_symlink
# endif
# if !@HAVE_SYMLINK@ || @REPLACE_SYMLINK@
int symlink (char const *contents, char const *file);
# endif
#elif defined GNULIB_POSIXCHECK
# undef symlink
# define symlink(c,n)			     \
    (GL_LINK_WARNING ("symlink is not portable - " \
                      "use gnulib module symlink for portability"), \
     symlink (c, n))
#endif


#if @GNULIB_SYMLINKAT@
# if !@HAVE_SYMLINKAT@
int symlinkat (char const *contents, int fd, char const *file);
# endif
#elif defined GNULIB_POSIXCHECK
# undef symlinkat
# define symlinkat(c,d,n)			     \
    (GL_LINK_WARNING ("symlinkat is not portable - " \
                      "use gnulib module symlinkat for portability"), \
     symlinkat (c, d, n))
#endif


#if @GNULIB_UNLINK@
# if @REPLACE_UNLINK@
#  undef unlink
#  define unlink rpl_unlink
extern int unlink (char const *file);
# endif
#elif defined GNULIB_POSIXCHECK
# undef unlink
# define unlink(n)                         \
    (GL_LINK_WARNING ("unlink is not portable - " \
                      "use gnulib module unlink for portability"), \
     unlink (n))
#endif


#if @GNULIB_UNLINKAT@
# if @REPLACE_UNLINKAT@
#  undef unlinkat
#  define unlinkat rpl_unlinkat
# endif
# if !@HAVE_UNLINKAT@ || @REPLACE_UNLINKAT@
extern int unlinkat (int fd, char const *file, int flag);
# endif
#elif defined GNULIB_POSIXCHECK
# undef unlinkat
# define unlinkat(d,n,f)                         \
    (GL_LINK_WARNING ("unlinkat is not portable - " \
                      "use gnulib module openat for portability"), \
     unlinkat (d, n, f))
#endif


#if @GNULIB_USLEEP@
# if @REPLACE_USLEEP@
#  undef usleep
#  define usleep rpl_usleep
# endif
# if !@HAVE_USLEEP@ || @REPLACE_USLEEP@
/* Pause the execution of the current thread for N microseconds.
   Returns 0 on completion, or -1 on range error.
   See the POSIX:2001 specification
   <http://www.opengroup.org/susv3xsh/sleep.html>.  */
extern int usleep (useconds_t n);
# endif
#elif defined GNULIB_POSIXCHECK
# undef usleep
# define usleep(n) \
    (GL_LINK_WARNING ("usleep is unportable - " \
                      "use gnulib module usleep for portability"), \
     usleep (n))
#endif


#if @GNULIB_WRITE@ && @REPLACE_WRITE@ && @GNULIB_UNISTD_H_SIGPIPE@
/* Write up to COUNT bytes starting at BUF to file descriptor FD.
   See the POSIX:2001 specification
   <http://www.opengroup.org/susv3xsh/write.html>.  */
# undef write
# define write rpl_write
extern ssize_t write (int fd, const void *buf, size_t count);
#endif


#ifdef __cplusplus
}
#endif


#endif /* _GL_UNISTD_H */
#endif /* _GL_UNISTD_H */
