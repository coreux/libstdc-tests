## M4 fragment for performing host checks needed for the testsuite

## Copyright 2017 Mo McRoberts.
##
##  Licensed under the Apache License, Version 2.0 (the "License");
##  you may not use this file except in compliance with the License.
##  You may obtain a copy of the License at
##
##      http://www.apache.org/licenses/LICENSE-2.0
##
##  Unless required by applicable law or agreed to in writing, software
##  distributed under the License is distributed on an "AS IS" BASIS,
##  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
##  See the License for the specific language governing permissions and
##  limitations under the License.

test -z "$STDC_ENABLE_TESTS" && STDC_ENABLE_TESTS=yes
test -z "$STDC_ENABLE_C95_TESTS" && STDC_ENABLE_C95_TESTS=yes
test -z "$STDC_ENABLE_C99_TESTS" && STDC_ENABLE_C99_TESTS=yes
test -z "$STDC_ENABLE_C11_TESTS" && STDC_ENABLE_C11_TESTS=yes
test -z "$STDC_ENABLE_FREESTANDING_TESTS" && STDC_ENABLE_FREESTANDING_TESTS=yes
test -z "$STDC_ENABLE_HOSTED_TESTS" && STDC_ENABLE_HOSTED_TESTS=yes
test -z "$STDC_ENABLE_UNIX_TESTS" && STDC_ENABLE_UNIX_TESTS=yes
test -z "$STDC_TEST_CPP" && STDC_TEST_CPP='${CPP}'

AM_CONDITIONAL([STDC_ENABLE_TESTS],[test x"$STDC_ENABLE_TESTS" = x"yes"])
AM_CONDITIONAL([STDC_ENABLE_C95_TESTS],[test x"$STDC_ENABLE_C95_TESTS" = x"yes"])
AM_CONDITIONAL([STDC_ENABLE_C99_TESTS],[test x"$STDC_ENABLE_C99_TESTS" = x"yes"])
AM_CONDITIONAL([STDC_ENABLE_C11_TESTS],[test x"$STDC_ENABLE_C11_TESTS" = x"yes"])

AM_CONDITIONAL([STDC_ENABLE_FREESTANDING_TESTS],[test x"$STDC_ENABLE_FREESTANDING_TESTS" = x"yes"])
AM_CONDITIONAL([STDC_ENABLE_HOSTED_TESTS],[test x"$STDC_ENABLE_HOSTED_TESTS" = x"yes"])
AM_CONDITIONAL([STDC_ENABLE_UNIX_TESTS],[test x"$STDC_ENABLE_UNIX_TESTS" = x"yes"])

AC_SUBST([STDC_TEST_CPP])
AC_SUBST([STDC_TEST_CPPFLAGS])
AC_SUBST([STDC_TEST_DEFS])
AC_SUBST([STDC_TEST_LDFLAGS])
AC_SUBST([STDC_TEST_LIBS])
AC_SUBST([STDC_TEST_FREESTANDING_CPPFLAGS])
AC_SUBST([STDC_TEST_HOSTED_CPPFLAGS])
AC_SUBST([STDC_TEST_UNIX_CPPFLAGS])

AC_CHECK_SIZEOF([char])
AC_SUBST([stdc_tests_sizeof_char],[$ac_cv_sizeof_char])
AC_CHECK_SIZEOF([int])
AC_SUBST([stdc_tests_sizeof_int],[$ac_cv_sizeof_int])
AC_CHECK_SIZEOF([short])
AC_SUBST([stdc_tests_sizeof_short],[$ac_cv_sizeof_short])
AC_CHECK_SIZEOF([long])
AC_SUBST([stdc_tests_sizeof_long],[$ac_cv_sizeof_long])
AC_CHECK_SIZEOF([long long])
AC_SUBST([stdc_tests_sizeof_long_long],[$ac_cv_sizeof_long_long])

dnl Test the test environment itself

dnl Ensure these values are available during tests

top_builddir="${ac_top_builddir}" ; test -z "$top_builddir" && top_builddir=.
abs_top_builddir="$top_builddir"
top_srcdir="$srcdir" ; test -z "$top_srcdir" && top_srcddir=.
abs_top_srcdir="$top_srcdir"

export top_builddir
export top_srcdir

save_CPP="$CPP" ; CPP="`eval echo $STDC_TEST_CPP`"
save_CPPFLAGS="$CPPFLAGS" ; CPPFLAGS="`eval echo $STDC_TEST_CPPFLAGS $STDC_TEST_DEFS`"
save_DEFS="$DEFS" ; DEFS=""
save_LDFLAGS="$LDFLAGS" ; LDFLAGS="`eval echo $STDC_TEST_LDFLAGS`"
save_LIBS="$LIBS" ; LIBS="`eval echo $STDC_TEST_LIBS`"


CPPFLAGS="`eval echo $STDC_TEST_CPPFLAGS $STDC_TEST_DEFS $STDC_TEST_UNIX_CPPFLAGS`"
AC_MSG_CHECKING([for unistd.h in the test environment])
AC_TRY_COMPILE([#include <unistd.h>],,[
  AC_MSG_RESULT([found])
  stdc_tests_have_unistd_h=1],[
  AC_MSG_RESULT([not found])
  ])
AC_SUBST([stdc_tests_have_unistd_h])

CPP="$save_CPP"
CPPFLAGS="$save_CPPFLAGS"
DEFS="$save_DEFS"
LDFLAGS="$save_LDFLAGS"
LIBS="$save_LIBS"

AC_DEFUN([STDC_TESTS_OUTPUT],[
 AC_CONFIG_FILES($1[/Makefile])
 AC_CONFIG_FILES($1[/testdefs.h])
 AC_CONFIG_FILES($1[/lib/Makefile])
 AC_CONFIG_FILES($1[/c90/Makefile])
 AC_CONFIG_FILES($1[/c90/freestanding/Makefile])
 AC_CONFIG_FILES($1[/c90/hosted/Makefile])
 AC_CONFIG_FILES($1[/c90/unix/Makefile])
 AC_CONFIG_FILES($1[/c95/Makefile])
 AC_CONFIG_FILES($1[/c95/freestanding/Makefile])
 AC_CONFIG_FILES($1[/c95/hosted/Makefile])
 AC_CONFIG_FILES($1[/c95/unix/Makefile])
 AC_CONFIG_FILES($1[/c99/Makefile])
 AC_CONFIG_FILES($1[/c99/freestanding/Makefile])
 AC_CONFIG_FILES($1[/c99/hosted/Makefile])
 AC_CONFIG_FILES($1[/c99/unix/Makefile])
 AC_CONFIG_FILES($1[/c11/Makefile])
 AC_CONFIG_FILES($1[/c11/freestanding/Makefile])
 AC_CONFIG_FILES($1[/c11/hosted/Makefile])
 AC_CONFIG_FILES($1[/c11/unix/Makefile])
 AC_CONFIG_FILES($1[/run-cpp],[chmod +x ]$1[/run-cpp])
])
