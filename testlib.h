#ifndef TESTLIB_H_
# define TESTLIB_H_                    1

# define TEST_PASS                     0
# define TEST_FAIL                     1
# define TEST_SKIP                     77
# define TEST_ERR                      99

# define TESTEXPECT(var, expected, formatstr) \
	if((var) != (expected)) \
	{ \
		testlogf(__FILE__, TEST_FAIL, #var " = " formatstr ", expected " formatstr "\n", var, expected); \
		return TEST_FAIL; \
	} \
	else \
	{ \
		testlogf(__FILE__, TEST_PASS, "OK: " #var " = " formatstr "\n", var); \
	}

void testlogf(const char *file, int severity, const char *format, ...);

#endif /*!TESTLIB_H_*/
