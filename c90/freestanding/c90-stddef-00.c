/* Test common definitions */

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

# include <stddef.h>

union offsetof_union {
	int m1;
	char *m2;
	long m3;
};

int
main(void)
{
	static const char teststr[] = "C90 <stddef.h> tests";
	
	ptrdiff_t ptrdiff;
	size_t size;
	wchar_t wc;
	char *np;
	const char *sp;
	
	size = sizeof(teststr);
	TESTEXPECT((long) size, 21, "%ld");
	
	np = NULL;
	TESTEXPECT((long) np, (long) 0, "%ld");
	
	sp = &(teststr[size - 5]);
	ptrdiff = sp - teststr;
	TESTEXPECT((long) ptrdiff, (long) (size - 5), "%ld");
	
	wc = 0xffff;
	TESTEXPECT((long) wc, 0xffffL, "%ld");
	
	TESTEXPECT(offsetof(union offsetof_union, m3), 0, "%d");
	
	return TEST_PASS;
}

#endif

#include "freestanding-end.h"
#include "c90-end.h"
