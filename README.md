# Standard C library testsuite

## Introduction

This repository contains a set of tests designed to determine the conformance to various standards of a Standard C library (often known as `libc`), and is intended to be integrated into an [automake](https://www.gnu.org/software/automake/) project.

## Usage

Incorporate this tree into your repository, for example in a directory named `tests`, and then add something similar to the following to your `configure.ac`:-

```
AM_CONDITIONAL([STDC_ENABLE_TESTS],[true])
AM_CONDITIONAL([STDC_ENABLE_FREESTANDING_TESTS],[true])

AC_SUBST([STDC_TEST_CPP],['${CPP}'])
AC_SUBST([STDC_TEST_CPPFLAGS],['-nostdinc -I${top_builddir}/include -I${top_srcdir}/include'])
AC_SUBST([STDC_TEST_DEFS],['-DRUNNING_TESTS'])
AC_SUBST([STDC_TEST_LDFLAGS],[''])
AC_SUBST([STDC_TRST_LIBS],['${top_builddir}/libmystdlib.a'])

AC_CONFIG_FILES([
tests/Makefile
tests/freestanding/Makefile
])

AC_CONFIG_FILES([tests/run-cpp],[chmod +x t/run-cpp])
```

You should also add the following, if not already present:-

```
AC_PROG_CC
AC_PROG_CPP
AC_PROG_RANLIB
```

The conditionals `STDC_ENABLE_TESTS` and `STDC_ENABLE_FREESTANDING_TESTS` are used to determine at configuration-time whether to execute any of the tests.

The `STDC_TEST_CPP`, `STDC_TEST_CPPFLAGS`, `STDC_TEST_DEFS`, `STDC_TEST_LDFLAGS`, `STDC_TEST_LIBS` flags are used when compiling the tests themselves, and so should contain whatever parameters are needed to compile against the C library being tested.

## Copyright and licensing

This project is licensed according to the terms of the [Apache Licence, version 2.0](https://www.apache.org/licenses/LICENSE-2.0).

Copyright © 2017 Mo McRoberts.
