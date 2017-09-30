/* Test _XOPEN_VERSION for UNIX 95 environments */

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

#define _POSIX_C_SOURCE                199009L
#define _XOPEN_SOURCE                  4

#include "c90-begin.h"

#ifndef TEST_WILL_SKIP

# ifdef TEST_HAVE_UNISTD_H
#  include <unistd.h>
# endif

# ifndef _XOPEN_VERSION
#  define _XOPEN_VERSION               -1
# endif

int
main(void)
{
	if(_XOPEN_VERSION == -1)
	{
		testlogf(__FILE__, TEST_SKIP, "_XOPEN_VERSION is not defined by this implementation, expected _XOPEN_VERSION >= 4\n");
		return TEST_SKIP;
	}
# ifndef _XOPEN_UNIX
	testlogf(__FILE__, TEST_SKIP, "_XOPEN_UNIX is not defined by this implementation\n");
	return TEST_SKIP;
# else
	TESTEXPECTGE(_XOPEN_VERSION, 4, "%ld");
	return TEST_PASS;
# endif
}

#endif

#include "c90-end.h"
