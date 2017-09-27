/* Test the C99 constants in <limits.h> */

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
#include "testdefs.h"

#if __STDC_VERSION__ >= 199901L
# include <limits.h>

int
main(void)
{
	/* Test against specific known widths */
#if TEST_SIZEOF_LONGLONG == 8
	TESTEXPECT(LLONG_MAX, 0x7FFFFFFFFFFFFFFFLL, "%lld");
	TESTEXPECT(LLONG_MIN, (-0x7FFFFFFFFFFFFFFFLL - 1), "%lld");
	TESTEXPECT(ULLONG_MAX, 0xFFFFFFFFFFFFFFFFULL, "%llu");
#else
	testlogf(__FILE__, TEST_ERR, "missing test values for sizeof(long long) == %d\n", TEST_SIZEOF_LONGLONG);
	return TEST_ERR;
#endif
	return TEST_PASS;
}

#else /* C99 */
int main(void) { return TEST_SKIP; }
#endif /* C99 */
