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
