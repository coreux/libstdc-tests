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
	TESTEXPECTGE(LONG_MAX, 32767L, "%ld");
	TESTEXPECTLE(LONG_MIN, -32767L, "%ld");
	TESTEXPECTGE(ULONG_MAX, 65535UL, "%lu");
	TESTEXPECTGT(ULONG_MAX, (unsigned long) LONG_MAX, "%lu");
	/* Test against specific known widths */
#if TEST_SIZEOF_LONG == 4
	TESTEXPECT(LONG_MAX, 2147483647L, "%ld");
	TESTEXPECT(LONG_MIN, -2147483648L, "%ld");
	TESTEXPECT(ULONG_MAX, 0xFFFFFFFFUL, "%lu");
#elif TEST_SIZEOF_LONG == 8
	TESTEXPECT(LONG_MAX, 0x7FFFFFFFFFFFFFFFL, "%ld");
	TESTEXPECT(LONG_MIN, (-0x7FFFFFFFFFFFFFFFL - 1), "%ld");
	TESTEXPECT(ULONG_MAX, 0xFFFFFFFFFFFFFFFFUL, "%lu");
#else
	testlogf(__FILE__, TEST_ERR, "missing test values for sizeof(long) == %d\n", TEST_SIZEOF_LONG);
	return TEST_ERR;
#endif
	return TEST_PASS;
}

#endif

#include "freestanding-end.h"
#include "c90-end.h"
