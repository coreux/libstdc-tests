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

DIST_SUBDIRS = lib freestanding hosted

EXTRA_DIST = README.md LICENSE-2.0 run-cpp.in testdefs.h.in conftests.m4

if STDC_ENABLE_TESTS

SUBDIRS = lib freestanding hosted .

noinst_SCRIPTS = run-cpp

if STDC_ENABLE_FREESTANDING_TESTS

freestanding_tests = \
	freestanding/freestanding \
	freestanding/c90-support \
	freestanding/c90-limits-int \
	freestanding/c90-limits-short \
	freestanding/c90-limits-long \
	freestanding/c90-limits-char \
	freestanding/c90-stdarg-00 \
	freestanding/c90-stddef-00 \
	freestanding/c95-support \
	freestanding/c95-iso646-00 \
	freestanding/c99-support \
	freestanding/c99-limits-longlong \
	freestanding/c99-stdbool-00 \
	freestanding/c99-stdint-00 \
	freestanding/c11-support \
	freestanding/c11-stdalign-00 \
	freestanding/c11-stdnoreturn-00

endif

if STDC_ENABLE_HOSTED_TESTS

hosted_tests = \
	hosted/hosted \
	hosted/c90-support \
	hosted/c90-limits-int \
	hosted/c90-limits-short \
	hosted/c90-limits-long \
	hosted/c90-limits-char \
	hosted/c90-stdarg-00 \
	hosted/c90-stddef-00 \
	hosted/c95-support \
	hosted/c95-iso646-00 \
	hosted/c99-support \
	hosted/c99-limits-longlong \
	hosted/c99-stdbool-00 \
	hosted/c99-stdint-00 \
	hosted/c11-support \
	hosted/c11-stdalign-00 \
	hosted/c11-stdnoreturn-00

endif

TESTS = $(freestanding_tests) $(hosted_tests)

endif
