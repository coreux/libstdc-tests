/* Test the C90 constants in <limits.h> */

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

# include <limits.h>

int
main(void)
{
	/* Test against minimum-magnitude values specified in Annex E */
	TESTEXPECT(CHAR_BIT, 8, "%d")
	TESTEXPECT(SCHAR_MAX, 127, "%d");
	TESTEXPECT(SCHAR_MIN, -128, "%d");
	TESTEXPECT(UCHAR_MAX, 255, "%d");
	TESTEXPECTGE(MB_LEN_MAX, 1, "%d");
	
	if(CHAR_MAX == SCHAR_MAX)
	{
		TESTEXPECT(CHAR_MIN, -128, "%d");
		TESTEXPECT(CHAR_MAX, 127, "%d");
	}
	else
	{
		TESTEXPECT(CHAR_MIN, 0, "%d");
		TESTEXPECT(CHAR_MAX, 255, "%d");
	}
	return TEST_PASS;
}

#endif

#include "freestanding-end.h"
#include "c90-end.h"
