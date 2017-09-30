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

check_LIBRARIES = libtestlib.a

libtestlib_a_SOURCES = testlib.h \
	testlog.c

dist_noinst_HEADERS = hosted-begin.h hosted-end.h \
	freestanding-begin.h freestanding-end.h \
	posix-begin.h posix-end.h \
	c90-begin.h c90-end.h \
	c95-begin.h c95-end.h \
	c99-begin.h c99-end.h \
	c11-begin.h c11-end.h
