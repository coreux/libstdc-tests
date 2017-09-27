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

#include "testlib.h"

int
main(void)
{
#ifndef __STDC__
	testlogf(__FILE__, TEST_FAIL, "__STDC_ is not defined by this implementation\n");
	return TEST_FAIL;
#else
	testlogf(__FILE__, TEST_PASS, "OK: __STDC__ is defined\n");
	return TEST_PASS;
#endif
}
