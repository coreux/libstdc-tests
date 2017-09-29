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

# define TESTEXPECTSTR(var, varname, expr, exprstr, formatstr) \
	if(!(expr)) \
	{ \
		testlogf(__FILE__, TEST_FAIL, "%s = " formatstr ", expected %s\n", varname, var, exprstr); \
		return TEST_FAIL; \
	} \
	else \
	{ \
		testlogf(__FILE__, TEST_PASS, "OK: %s = " formatstr ", expected %s\n", varname, var, exprstr); \
	}

# define TESTEXPECTSTRVAL(var, varname, expr, exprstr, expectval, formatstr) \
	if(!(expr)) \
	{ \
		testlogf(__FILE__, TEST_FAIL, "%s = " formatstr ", expected %s = " formatstr "\n", varname, var, exprstr, expectval); \
		return TEST_FAIL; \
	} \
	else \
	{ \
		testlogf(__FILE__, TEST_PASS, "OK: %s = " formatstr ", expected %s = " formatstr "\n", varname, var, exprstr, expectval); \
	}


# define TESTEXPECTE(var, expr, formatstr) \
	TESTEXPECTSTR(var, #var, expr, #expr, formatstr)

# define TESTEXPECTVAL(var, expr, expectval, formatstr) \
	TESTEXPECTSTRVAL(var, #var, expr, #expr, expectval, formatstr)

# define TESTEXPECT(var, expected, formatstr) \
	TESTEXPECTSTRVAL(var, #var, var == expected, #var " == " #expected, expected, formatstr)

# define TESTEXPECTS(var, expected, exprstr, formatstr) \
	TESTEXPECTSTRVAL(var, #var, var == expected, exprstr, expected, formatstr)

# define TESTEXPECTLT(var, expected, formatstr) \
	TESTEXPECTVAL(var, var < expected, expected, formatstr)

# define TESTEXPECTLE(var, expected, formatstr) \
	TESTEXPECTVAL(var, var <= expected, expected, formatstr)

# define TESTEXPECTGT(var, expected, formatstr) \
	TESTEXPECTVAL(var, var > expected, expected, formatstr)

# define TESTEXPECTGE(var, expected, formatstr) \
	TESTEXPECTVAL(var, var >= expected, expected, formatstr)

void testlogf(const char *file, int severity, const char *format, ...);

#endif /*!TESTLIB_H_*/
