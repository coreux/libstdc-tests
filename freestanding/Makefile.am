## C Library freestanding environment tests

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

AM_CPPFLAGS = $(STDC_TEST_CPPFLAGS) -I${builddir}/.. -I${srcdir}/.. $(STDC_TEST_INCLUDES)
AM_LDFLAGS = $(STDC_TEST_LDFLAGS)
DEFS = $(STDC_TEST_DEFS) -U__STDC_HOSTED__ -D__STDC_HOSTED__=0
LIBS = ../libtestlib.a $(STDC_TEST_LIBS)

check_PROGRAMS = \
	freestanding \
	c90-support \
	c90-limits-int c90-limits-short c90-limits-long c90-limits-char \
	c90-stdarg-00 \
	c90-stddef-00 \
	c95-support \
	c95-iso646-00 \
	c99-support \
	c99-limits-longlong \
	c99-stdbool-00 \
	c99-stdint-00 \
	c11-support \
	c11-stdalign-00 \
	c11-stdnoreturn-00

if STDC_ENABLE_FREESTANDING_TESTS

TESTS = $(check_PROGRAMS)

endif
