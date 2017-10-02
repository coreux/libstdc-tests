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
	TESTEXPECTGE(INT_MAX, 32767, "%d");
	TESTEXPECTLE(INT_MIN, -32767, "%d");
	TESTEXPECTGE(UINT_MAX, 65535U, "%u");
	TESTEXPECTGT(UINT_MAX, (unsigned) INT_MAX, "%u");
#if TEST_SIZEOF_INT == 2
	TESTEXPECT(INT_MAX, 32767, "%d");
	TESTEXPECT(INT_MIN, -32768, "%d");
	TESTEXPECT(UINT_MAX, 65535U, "%u");
#elif TEST_SIZEOF_INT == 4
	TESTEXPECT(INT_MAX, 2147483647, "%d");
	TESTEXPECT(INT_MIN, -2147483648, "%d");
	TESTEXPECT(UINT_MAX, 0xFFFFFFFFU, "%u");
#elif TEST_SIZEOF_INT == 8
	TESTEXPECT(INT_MAX, 9223372036854775807, "%d");
	TESTEXPECT(INT_MIN, -9223372036854775808, "%d");
	TESTEXPECT(UINT_MAX, 0xFFFFFFFFFFFFFFFFU, "%u");
#else
	testlogf(__FILE__, TEST_ERR, "missing test values for sizeof(int) == %d\n", TEST_SIZEOF_INT);
	return TEST_ERR;
#endif
	return TEST_PASS;
}

#endif

#include "freestanding-end.h"
#include "c90-end.h"
