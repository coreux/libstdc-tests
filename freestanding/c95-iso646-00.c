/* Test C95 operator names */

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

#if __STDC_VERSION__ >= 199409L
# include <iso646.h>

int
main(void)
{
	int x, y;
	
	TESTEXPECT((2 and 3), (2 && 3), "%d");
	
	x = 7;
	x and_eq 4;
	y = 7;
	y &= 4;
	TESTEXPECTS(x, y, "(x and_eq 4)", "%d");

	TESTEXPECT((126 bitand 12), (126 & 12), "%d");

	TESTEXPECT((129 bitor 15), (129 | 15), "%d");
	
	TESTEXPECT((compl 128), (~128), "%d");
	
	TESTEXPECT((not 1), (!1), "%d");
	TESTEXPECT((not 0), (!0), "%d");
	
	TESTEXPECT((1 or 0), (1 || 0), "%d");
	TESTEXPECT((0 or 2), (0 || 2), "%d");
	TESTEXPECT((1 or -1), (1 || -1), "%d");
	
	x = 200;
	x or_eq 31;
	y = 200;
	y |= 31;
	TESTEXPECTS(x, y, "(x or_eq 31)", "%d");
	
	TESTEXPECT((254 xor 12), (254 ^ 12), "%d");
	
	x = 14;
	x xor_eq 25;
	y = 14;
	y ^= 25;
	TESTEXPECTS(x, y, "(x xor_eq 25)", "%d");

	return TEST_PASS;
}

#else /* C95 */
int main(void) { return TEST_SKIP; }
#endif /* C95 */
