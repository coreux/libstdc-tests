## C Library C11 freestanding environment tests

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

AM_CPPFLAGS = $(STDC_TEST_CPPFLAGS) \
	-I${builddir}/../.. -I${srcdir}/../.. \
	-I${builddir}/../../lib -I${srcdir}/../../lib \
	$(STDC_TEST_INCLUDES) $(STDC_TEST_FREESTANDING_CPPFLAGS)
AM_LDFLAGS = $(STDC_TEST_LDFLAGS)
DEFS = $(STDC_TEST_DEFS) -DSTDC_TEST_PATH="c11/freestanding"
LIBS = ../../lib/libtestlib.a $(STDC_TEST_LIBS)

check_PROGRAMS = \
	c11-support \
	c11-stdalign-00 \
	c11-stdnoreturn-00
