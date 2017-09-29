/* Test-suite utility library */

/* Copyright 2017 Mo McRoberts.
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#include "testdefs.h"
#include "testlib.h"

#define TEST_C99_                      1

/* Because the freestanding tests are included into the hosted tree, don't
 * bother to check for a freestanding environment if we already know
 * (via TEST_HOSTED_) that we've checked for a hosted environment.
 */
#if !defined(TEST_WILL_SKIP)
# if !defined(__STDC_VERSION__) || __STDC_VERSION__ < 199901L
#  define TEST_SKIP_C99_               1
#  define TEST_WILL_SKIP               1
# endif
#endif