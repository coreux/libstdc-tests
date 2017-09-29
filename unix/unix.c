/* Test _POSIX_VERSION for Unix environments */

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

#include "c90-begin.h"

#ifndef TEST_WILL_SKIP

# ifndef _POSIX_VERSION
#  define _POSIX_VERSION               -1
# endif

int
main(void)
{
	if(_POSIX_VERSION == -1)
	{
		testlogf(__FILE__, TEST_SKIP, "_POSIX_VERSION is not defined by this implementation, expected _POSIX_VERSION >= 199808L\n");
		return TEST_SKIP;
	}
	TESTEXPECTGE(_POSIX_VERSION, 1999808L, "%ld");
	return TEST_PASS;
}

#endif

#include "c90-end.h"
