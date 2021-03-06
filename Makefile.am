## Standard C library test-suite

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

DIST_SUBDIRS = lib c90 c95 c99 c11

EXTRA_DIST = README.md LICENSE-2.0 run-cpp.in testdefs.h.in conftests.m4

if STDC_ENABLE_TESTS

SUBDIRS = lib c90 c95 c99 c11 .

noinst_SCRIPTS = run-cpp

if STDC_ENABLE_FREESTANDING_TESTS

freestanding_tests = \
	c90/freestanding/freestanding \
	c90/freestanding/c90-support \
	c90/freestanding/c90-float-00 \
	c90/freestanding/c90-limits-int \
	c90/freestanding/c90-limits-short \
	c90/freestanding/c90-limits-long \
	c90/freestanding/c90-limits-char \
	c90/freestanding/c90-stdarg-00 \
	c90/freestanding/c90-stddef-00
	
if STDC_ENABLE_C95_TESTS
freestanding_tests += \
	c95/freestanding/c95-support \
	c95/freestanding/c95-iso646-00

if STDC_ENABLE_C99_TESTS
freestanding_tests += \
	c99/freestanding/c99-support \
	c99/freestanding/c99-limits-longlong \
	c99/freestanding/c99-stdbool-00 \
	c99/freestanding/c99-stdint-00

if STDC_ENABLE_C11_TESTS
freestanding_tests += \
	c11/freestanding/c11-support \
	c11/freestanding/c11-stdalign-00 \
	c11/freestanding/c11-stdnoreturn-00

endif
endif
endif
endif

if STDC_ENABLE_HOSTED_TESTS

hosted_tests = \
	c90/hosted/hosted \
	c90/hosted/c90-support \
	c90/hosted/c90-float-00 \
	c90/hosted/c90-limits-int \
	c90/hosted/c90-limits-short \
	c90/hosted/c90-limits-long \
	c90/hosted/c90-limits-char \
	c90/hosted/c90-stdarg-00 \
	c90/hosted/c90-stddef-00

if STDC_ENABLE_C95_TESTS
hosted_tests += \
	c95/hosted/c95-support \
	c95/hosted/c95-iso646-00

if STDC_ENABLE_C99_TESTS
hosted_tests += \
	c99/hosted/c99-support \
	c99/hosted/c99-limits-longlong \
	c99/hosted/c99-stdbool-00 \
	c99/hosted/c99-stdint-00

if STDC_ENABLE_C11_TESTS
hosted_tests += \
	c11/hosted/c11-support \
	c11/hosted/c11-stdalign-00 \
	c11/hosted/c11-stdnoreturn-00

endif
endif
endif
endif

if STDC_ENABLE_UNIX_TESTS

unix_tests = \
	c90/unix/posix \
	c90/unix/posix90 \
	c90/unix/posix93 \
	c90/unix/xpg3 \
	c90/unix/xpg4

if STDC_ENABLE_C95_TESTS

unix_tests += \
	c95/unix/posix96 \
	c95/unix/unix95 \
	c95/unix/unix98

if STDC_ENABLE_C99_TESTS

unix_tests += \
	c99/unix/posix01 \
	c99/unix/posix08 \
	c99/unix/unix03

if STDC_ENABLE_C11_TESTS

unix_tests += \
	c11/unix/unixv7

endif
endif
endif
endif

TESTS = $(freestanding_tests) $(hosted_tests) $(unix_tests)

endif
