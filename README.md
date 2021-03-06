# Standard C library test-suite

## Introduction

This repository contains a set of tests designed to determine the conformance to various standards of a Standard C library (often known as `libc`), and is intended to be integrated into an [automake][1] project.

## Usage

### Prerequisites

Add the following to your `configure.ac`, if not already present:-

```
AC_PROG_CC
AC_PROG_CPP
AC_PROG_RANLIB
```

### Integration into `configure.ac`

Incorporate this tree into your project, for example in a directory named `tests`, and then add something similar to the following to your `configure.ac`:-

```
m4_include([tests/conftests.m4])
STDC_TESTS_OUTPUT([tests])
```

In the above, `tests` is the name of the directory containing this tree. If the directory was named `testsuites/libstdc-tests`, then you would specify the following instead:-

```
m4_include([testsuites/libstdc-tests/conftests.m4])
STDC_TESTS_OUTPUT([testsuites/libstdc-tests])
```
 
### Integration into `Makefile.am`

Simply add the directory containing this tree to `SUBDIRS` as you would normally.
 
### Enabling and disabling tests during configuration
 
Within `configure.ac`, the following shell variables govern which tests will be invoked:-
 
| Variable                         | Description                            |
|----------------------------------|----------------------------------------|
| `STDC_ENABLE_TESTS`              | Enables or disables all tests          |
| `STDC_ENABLE_FREESTANDING_TESTS` | Enables or disables freestanding tests |
| `STDC_ENABLE_HOSTED_TESTS`       | Enables or disables hosted tests       |
| `STDC_ENABLE_C95_TESTS`          | Enables or disables tests for >= C95   |
| `STDC_ENABLE_C99_TESTS`          | Enables or disables tests for >= C99   |
| `STDC_ENABLE_C11_TESTS`          | Enables or disables tests for C11      |

If these variables are set to a value other than `yes` prior to including `conftests.m4`, they will disable the corresponding tests.

Note that `freestanding` and `hosted` refer to the _environments which will be
tested_, not the tests themselves. If you are testing a freestanding implementation, you should set `STDC_ENABLE_HOSTED_TESTS` to `no`, and vice
versa (the hosted suite incorporates all of the freestanding tests).

By default, all tests will be built and executed (but see following section for information about compiler flags that are used).

Disabling C95 tests will also disable C99 and C11 tests (and so forth).

### Controlling the test environment

It is often desirable for tests to be compiled with different flags than those used to build the remainder of the project. For this reason, the tests in this repository are compiled using a specific set of preprocessor, compiler and linker option variables which are used in place of the usual defaults (`AM_CPPFLAGS`, `AM_LDFLAGS`, `DEFS`, `LIBS`, and so on). 

The following shell variables can be set prior to including `conftests.m4` to adjust the test compliation environment:-

| Variable             | Description                                      |
|----------------------|--------------------------------------------------|
| `STDC_TEST_CPP`      | C preprocessor to use (defaults to `$CPP`)       |
| `STDC_TEST_CPPFLAGS` | C preprocessor flags                             |
| `STDC_TEST_DEFS`     | Preprocessor definitions (`-D` and `-U` flags)   |
| `STDC_TEST_INCLUDES` | C header search path                             |
| `STDC_TEST_LDFLAGS`  | Linker flags                                     |
| `STDC_TEST_LIBS`     | Additional libraries to be linked into the tests |
| `STDC_TEST_FREESTANDING_CPPFLAGS` | C preprocessor flags only for freestanding tests |
| `STDC_TEST_HOSTED_CPPFLAGS` | C preprocessor flags only for hosted tests |
| `STDC_TEST_UNIX_CPPFLAGS` | C preprocessor flags only for Unix/POSIX tests |

`AC_SUBST()` will be invoked for each of these variables.

### Running the tests

The tests can be invoked via `make check` as normal (provided your `SUBDIRS` is set appropriately). The output produced will be similar to the following:-

```
PASS: c90-support
PASS: c90-stdarg-00
PASS: c90-limits-int
PASS: c90-limits-short
PASS: c90-limits-long
PASS: c90-limits-char
PASS: c95-support
PASS: c99-support
PASS: c11-support
============================================================================
Testsuite summary for mylibc 0.0.1
============================================================================
# TOTAL: 9
# PASS:  9
# SKIP:  0
# XFAIL: 0
# FAIL:  0
# XPASS: 0
# ERROR: 0
============================================================================
```

The `*.log` files generated by `make check` will contain the output from each of the tests. `test-suite.log` also contains the summary of all of the tests, and incorporates the logs of any that failed.

### Compilation failures

Automake-generated `Makefile`s do not _compile_ the tests until you run `make check`. Generally, a failure to compile a test should be taken as a failure, rather than necessarily a problem with the test itself. For example, if the compilation environment claims to support C11 (via `__STDC_VERSION__`), but does not support `noreturn`, then the problem lies with the environment.

Bugs in the tests are of course possible, but please check that your compilation environment is working properly before doing so--at the very least, ensure that you can compile and run your own test program using the same flags, headers and features demonstrating the expected behaviour.

## Caveats

The test suite assumes that the system provides a working `vfprintf()` and the program entry-point is `main()`. Modifications will be required if these are not the case. The tests themselves are designed to depend only upon the test support library (`libtestlib.a`), and the feature being tested.

The suite tests the _host_ system, but consisting of a set of runtime tests cannot be used in a cross-compilation environment unless the _build_ system is capable of running executables for the host.

In principle it should be possible to run the tests via tools such as [QEmu][2], but this has not yet been attempted.

## Copyright and licensing

This project is licensed according to the terms of the [Apache Licence, version 2.0](https://www.apache.org/licenses/LICENSE-2.0).

Copyright © 2017 Mo McRoberts.

[1]: https://www.gnu.org/software/automake/
[2]: https://www.qemu.org
