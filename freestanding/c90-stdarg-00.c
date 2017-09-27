/* Test va_arg() */

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

#include <stdarg.h>

#include "testlib.h"

struct stdarg_test_struct
{
	int i;
	unsigned u;
	const char *s;
};

static void
t_stdarg00(struct stdarg_test_struct *dest, ...)
{
	va_list ap;
	
	va_start(ap, dest);
	
	dest->i = va_arg(ap, int);
	dest->u = va_arg(ap, unsigned);
	dest->s = va_arg(ap, const char *);
}

int
main(void)
{
	struct stdarg_test_struct t;
	const char *teststr = "test";

	t.i = 0;
	t.u = 0;
	t.s = 0;
	t_stdarg00(&t, 1234, -1, teststr);

	TESTEXPECT(t.i, 1234, "%d");
	TESTEXPECT(t.u, (unsigned) -1, "%u");
	TESTEXPECT(t.s, teststr, "%p");

	return TEST_PASS;
}
