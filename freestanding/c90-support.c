/* Test __STDC___ for C90 */

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
	if(__STDC__ < 0)
	{
		testlogf(__FILE__, TEST_FAIL, "__STDC__ is not defined by this implementation, expected __STDC__ = 1\n");
		return TEST_FAIL;
	}
	TESTEXPECT(__STDC__, 1, "%d");
	return TEST_PASS;
}

#endif

#include "freestanding-end.h"
