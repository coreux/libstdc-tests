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
