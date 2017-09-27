/* Test __STDC_VERSION__ for C95 */

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

#include "testlib.h"

int
main(void)
{
#ifndef __STDC_VERSION__
	testlogf(__FILE__, TEST_FAIL, "__STDC_VERSION__ is not defined by this implementation\n");
	return TEST_FAIL;
#else
	TESTEXPECTGE(__STDC_VERSION__, 199409L, "%ld");
	return TEST_PASS;
#endif
}
