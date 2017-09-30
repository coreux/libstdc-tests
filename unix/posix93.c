/* Test _POSIX_VERSION for POSIX.1-1990 environments */

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

#define _POSIX_C_SOURCE                199309L

#include "c90-begin.h"

#ifndef TEST_WILL_SKIP

# ifdef TEST_HAVE_UNISTD_H
#  include <unistd.h>
# endif

# ifndef _POSIX_VERSION
#  define _POSIX_VERSION               -1
# endif

int
main(void)
{
	if(_POSIX_VERSION == -1)
	{
		testlogf(__FILE__, TEST_SKIP, "_POSIX_VERSION is not defined by this implementation, expected _POSIX_VERSION >= 199309L\n");
		return TEST_SKIP;
	}
	TESTEXPECTGE(_POSIX_VERSION, 199309L, "%ld");
	return TEST_PASS;
}

#endif

#include "c90-end.h"
