/* Test-suite utility library */

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

#ifndef TESTLIB_H_
# define TESTLIB_H_                    1

# define TEST_PASS                     0
# define TEST_FAIL                     1
# define TEST_SKIP                     77
# define TEST_ERR                      99

# define TESTEXPECT_(var, varname, op, opname, expected, formatstr) \
	if(!((var) op (expected))) \
	{ \
		testlogf(__FILE__, TEST_FAIL, varname " = " formatstr ", expected " varname " " opname " " formatstr "\n", var, expected); \
		return TEST_FAIL; \
	} \
	else \
	{ \
		testlogf(__FILE__, TEST_PASS, "OK: " varname " = " formatstr " (expected " varname " " opname " " formatstr ")\n", var, expected); \
	}

# define TESTEXPECT(var, expected, formatstr) \
	TESTEXPECT_(var, #var, ==, "==", expected, formatstr)
# define TESTEXPECTLT(var, expected, formatstr) \
	TESTEXPECT_(var, #var, <, "<", expected, formatstr)
# define TESTEXPECTLE(var, expected, formatstr) \
	TESTEXPECT_(var, #var, <=, "<=", expected, formatstr)
# define TESTEXPECTGT(var, expected, formatstr) \
	TESTEXPECT_(var, #var, >, ">", expected, formatstr)
# define TESTEXPECTGE(var, expected, formatstr) \
	TESTEXPECT_(var, #var, >=, ">=", expected, formatstr)

void testlogf(const char *file, int severity, const char *format, ...);

#endif /*!TESTLIB_H_*/
