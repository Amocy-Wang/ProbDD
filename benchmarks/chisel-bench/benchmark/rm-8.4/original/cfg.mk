# Customize maint.mk                           -*- makefile -*-
# Copyright (C) 2003-2010 Free Software Foundation, Inc.

# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

# Used in maint.mk's web-manual rule
manual_title = Core GNU utilities

# Tests not to run as part of "make distcheck".
local-checks-to-skip =

# Tools used to bootstrap this package, used for "announcement".
bootstrap-tools = autoconf,automake,gnulib,bison

# Now that we have better tests, make this the default.
export VERBOSE = yes

old_NEWS_hash = beab130e9d41bf8014a0594cfe8b28d4

# Add an exemption for sc_makefile_at_at_check.
_makefile_at_at_check_exceptions = ' && !/^cu_install_program =/'

# Ensure that the list of O_ symbols used to compute O_FULLBLOCK is complete.
dd = $(srcdir)/src/dd.c
sc_dd_O_FLAGS:
	@rm -f $@.1 $@.2
	@{ echo O_FULLBLOCK; perl -nle '/^ +\| (O_\w*)$$/ and print $$1' \
	  $(dd); } | sort > $@.1
	@{ echo O_NOFOLLOW; perl -nle '/{"[a-z]+",\s*(O_\w+)},/ and print $$1' \
	  $(dd); } | sort > $@.2
	@diff -u $@.1 $@.2 || diff=1 || diff=;				\
	rm -f $@.1 $@.2;						\
	test "$$diff"							\
	  && { echo '$(ME): $(dd) has inconsistent O_ flag lists'>&2;	\
	       exit 1; } || :

# Ensure that dd's definition of LONGEST_SYMBOL stays in sync
# with the strings from the two affected variables.
dd_c = $(srcdir)/src/dd.c
sc_dd_max_sym_length:
ifneq ($(wildcard $(dd_c)),)
	@len=$$( (sed -n '/conversions\[\] =$$/,/^};/p' $(dd_c);\
		 sed -n '/flags\[\] =$$/,/^};/p' $(dd_c) )	\
		|sed -n '/"/s/^[^"]*"\([^"]*\)".*/\1/p'		\
	      | wc --max-line-length);				\
	max=$$(sed -n '/^#define LONGEST_SYMBOL /s///p' $(dd_c)	\
	      |tr -d '"' | wc --max-line-length);		\
	if test "$$len" = "$$max"; then :; else			\
	  echo 'dd.c: LONGEST_SYMBOL is not longest' 1>&2;	\
	  exit 1;						\
	fi
endif

# Many m4 macros names once began with `jm_'.
# On 2004-04-13, they were all changed to start with gl_ instead.
# Make sure that none are inadvertently reintroduced.
sc_prohibit_jm_in_m4:
	@grep -nE 'jm_[A-Z]'						\
		$$($(VC_LIST) m4 |grep '\.m4$$'; echo /dev/null) &&	\
	    { echo '$(ME): do not use jm_ in m4 macro names'		\
	      1>&2; exit 1; } || :

# Ensure that each root-requiring test is run via the "check-root" rule.
sc_root_tests:
	@if test -d tests \
	      && grep check-root tests/Makefile.am>/dev/null 2>&1; then \
	t1=sc-root.expected; t2=sc-root.actual;				\
	grep -nl '^require_root_$$'					\
	  $$($(VC_LIST) tests) |sed s,tests/,, |sort > $$t1;		\
	sed -n '/^root_tests =[	 ]*\\$$/,/[^\]$$/p'			\
	  $(srcdir)/tests/Makefile.am					\
	    | sed 's/^  *//;/^root_tests =/d'				\
	    | tr -s '\012\\' '  ' | fmt -1 | sort > $$t2;		\
	diff -u $$t1 $$t2 || diff=1 || diff=;				\
	rm -f $$t1 $$t2;						\
	test "$$diff"							\
	  && { echo 'tests/Makefile.am: missing check-root action'>&2;	\
	       exit 1; } || :;						\
	fi

# Ensure that the syntax_check_exceptions file list in Makefile.am
# stays in sync with corresponding files in the repository.
sce = syntax_check_exceptions
sc_x_sc_dist_check:
	@test "$$( ($(VC_LIST) | sed -n '/^.x-sc_/p';			\
		   sed -n '/^$(sce) =[	 ]*\\$$/,/[^\]$$/p'		\
		     $(srcdir)/Makefile.am				\
		       | sed 's/^  *//;/^$(sce) =/d'			\
		       | tr -s '\012\\' '  ' | fmt -1			\
		   ) | sort | uniq -u)"					\
	  && { echo 'Makefile.am: $(sce) mismatch' >&2; exit 1; } || :;

headers_with_interesting_macro_defs = \
  exit.h	\
  fcntl_.h	\
  fnmatch_.h	\
  intprops.h	\
  inttypes_.h	\
  lchown.h	\
  openat.h	\
  stat-macros.h	\
  stdint_.h

# Create a list of regular expressions matching the names
# of macros that are guaranteed by parts of gnulib to be defined.
.re-defmac:
	@(cd $(srcdir)/lib;						\
	  for f in $(headers_with_interesting_macro_defs); do		\
	    test -f $$f &&						\
	      sed -n '/^# *define \([^_ (][^ (]*\)[ (].*/s//\1/p' $$f;	\
	   done;							\
	 ) | sort -u							\
	   | grep -Ev 'ATTRIBUTE_NORETURN|SIZE_MAX'			\
	   | sed 's/^/^# *define /'					\
	  > $@-t
	@mv $@-t $@

# Don't define macros that we already get from gnulib header files.
sc_always_defined_macros: .re-defmac
	@if test -f $(srcdir)/src/system.h; then			\
	  trap 'rc=$$?; rm -f .re-defmac; exit $$rc' 0 1 2 3 15;	\
	  grep -f .re-defmac $$($(VC_LIST))				\
	    && { echo '$(ME): define the above via some gnulib .h file'	\
		  1>&2;  exit 1; } || :;				\
	fi

# Create a list of regular expressions matching the names
# of files included from system.h.  Exclude a couple.
.re-list:
	@sed -n '/^# *include /s///p' $(srcdir)/src/system.h \
	  | grep -Ev 'sys/(param|file)\.h' \
	  | sed 's/ .*//;;s/^["<]/^# *include [<"]/;s/\.h[">]$$/\\.h[">]/' \
	  > $@-t
	@mv $@-t $@

# Files in src/ should not include directly any of
# the headers already included via system.h.
sc_system_h_headers: .re-list
	@if test -f $(srcdir)/src/system.h; then			\
	  trap 'rc=$$?; rm -f .re-list; exit $$rc' 0 1 2 3 15;		\
	  grep -nE -f .re-list						\
	      $$($(VC_LIST_EXCEPT) | grep '^src/')			\
	    && { echo '$(ME): the above are already included via system.h'\
		  1>&2;  exit 1; } || :;				\
	fi

sc_sun_os_names:
	@grep -nEi \
	    'solaris[^[:alnum:]]*2\.(7|8|9|[1-9][0-9])|sunos[^[:alnum:]][6-9]' \
	    $$($(VC_LIST_EXCEPT)) &&					\
	  { echo '$(ME): found misuse of Sun OS version numbers' 1>&2;	\
	    exit 1; } || :

ALL_RECURSIVE_TARGETS += sc_tight_scope
sc_tight_scope:
	@$(MAKE) -C src $@

ALL_RECURSIVE_TARGETS += sc_check-AUTHORS
sc_check-AUTHORS:
	@$(MAKE) -C src $@

# Perl-based tests used to exec perl from a #!/bin/sh script.
# Now they all start with #!/usr/bin/perl and the portability
# infrastructure is in tests/Makefile.am.  Make sure no old-style
# script sneaks back in.
sc_no_exec_perl_coreutils:
	@if test -f $(srcdir)/tests/Coreutils.pm; then			\
	  grep '^exec  *\$$PERL.*MCoreutils' $$($(VC_LIST) tests) &&	\
	    { echo 1>&2 '$(ME): found anachronistic Perl-based tests';	\
	      exit 1; } || :;						\
	fi

# Don't use "readlink" or "readlinkat" directly
sc_prohibit_readlink:
	@re='\<readlink(at)? \('					\
	msg='do not use readlink(at); use via xreadlink or areadlink*'	\
	  $(_prohibit_regexp)

# Don't use address of "stat" or "lstat" functions
sc_prohibit_stat_macro_address:
	@re='\<l?stat '':|&l?stat\>'					\
	msg='stat() and lstat() may be function-like macros'		\
	  $(_prohibit_regexp)

# Ensure that date's --help output stays in sync with the info
# documentation for GNU strftime.  The only exception is %N,
# which date accepts but GNU strftime does not.
extract_char = sed 's/^[^%][^%]*%\(.\).*/\1/'
sc_strftime_check:
	@if test -f $(srcdir)/src/date.c; then				\
	  grep '^  %.  ' $(srcdir)/src/date.c | sort			\
	    | $(extract_char) > $@-src;					\
	  { echo N;							\
	    info libc date calendar format | grep '^    `%.'\'		\
	      | $(extract_char); } | sort > $@-info;			\
	  diff -u $@-src $@-info || exit 1;				\
	  rm -f $@-src $@-info;						\
	fi

# Indent only with spaces.
sc_prohibit_tab_based_indentation:
	@re='^ *	'						\
	msg='TAB in indentation; use only spaces'			\
	  $(_prohibit_regexp)

# Don't use "indent-tabs-mode: nil" anymore.  No longer needed.
sc_prohibit_emacs__indent_tabs_mode__setting:
	@re='^( *[*#] *)?indent-tabs-mode:'				\
	msg='use of emacs indent-tabs-mode: setting'			\
	  $(_prohibit_regexp)

# Ensure that each file that contains fail=1 also contains fail=0.
# Otherwise, setting file=1 in the environment would make tests fail unexpectedly.
sc_prohibit_fail_0:
	@re='\<fail=0\>'						\
	msg='fail=0 initialization'					\
	  $(_prohibit_regexp)

# Ensure that "stdio--.h" is used where appropriate.
sc_require_stdio_safer:
	@if $(VC_LIST_EXCEPT) | grep -l '\.[ch]$$' > /dev/null; then	\
	  files=$$(grep -l '\bfreopen \?(' $$($(VC_LIST_EXCEPT)		\
	      | grep '\.[ch]$$'));					\
	  test -n "$$files" && grep -LE 'include "stdio--.h"' $$files	\
	      | grep . &&						\
	  { echo '$(ME): the above files should use "stdio--.h"'	\
		1>&2; exit 1; } || :;					\
	else :;								\
	fi

# Prefer xnanosleep over other less-precise sleep methods
sc_prohibit_sleep:
	@re='\<(nano|u)?sleep \('					\
	msg='prefer xnanosleep over other sleep interfaces'		\
	  $(_prohibit_regexp)

include $(srcdir)/dist-check.mk

update-copyright-env = \
  UPDATE_COPYRIGHT_USE_INTERVALS=1 \
  UPDATE_COPYRIGHT_MAX_LINE_LENGTH=79
