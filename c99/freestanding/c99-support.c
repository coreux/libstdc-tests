/* Test __STDC_VERSION__ for C99 */

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

#include "freestanding-begin.h"

#ifndef TEST_WILL_SKIP

int
main(void)
{
	if(__STDC_VERSION__ == -1)
	{
		testlogf(__FILE__, TEST_SKIP, "__STDC_VERSION__ is not defined by this implementation, expected __STDC_VERSION__ >= 199901L\n");
		return TEST_SKIP;
	}
	TESTEXPECTGE(__STDC_VERSION__, 199901L, "%ld");
	return TEST_PASS;
}

#endif

#include "freestanding-end.h"
