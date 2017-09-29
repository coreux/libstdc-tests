/* Test __STDC_HOSTED__ for freestanding environments */

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
#include "freestanding-begin.h"

#ifndef TEST_WILL_SKIP

int
main(void)
{
	if(__STDC_HOSTED__ < 1)
	{
		testlogf(__FILE__, TEST_FAIL, "OK: __STDC_HOSTED__ is not defined by this implementation, expected __STDC_HOSTED__ = 0\n");
		return TEST_PASS;
	}
	TESTEXPECT(__STDC_HOSTED__, 0, "%d");
	return TEST_PASS;
}

#endif

#include "freestanding-end.h"
#include "c90-end.h"
