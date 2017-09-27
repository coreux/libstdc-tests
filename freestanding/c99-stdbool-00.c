/* Test C99 boolean values */

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

#if __STDC_VERSION__ >= 199901L
# include <stdbool.h>

# ifndef true
#  define true                         -1
# endif
# ifndef false
#  define false                        -1
# endif
# ifndef __bool_true_false_are_defined
#  define __bool_true_false_are_defined -1
# endif

int
main(void)
{
	TESTEXPECT((int) true, 1, "%d");
	TESTEXPECT((int) false, 0, "%d");
	TESTEXPECT(__bool_true_false_are_defined, 1, "%d");
	return TEST_PASS;
}

#else /* C95 */
int main(void) { return TEST_SKIP; }
#endif /* C95 */
