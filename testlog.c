#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include <stdio.h>
#include <stdarg.h>

#include "testlib.h"

void
testlogf(const char *file, int severity, const char *format, ...)
{
	va_list ap;
	
	va_start(ap, format);
	fprintf(stderr, "%s: ", file);
	vfprintf(stderr, format, ap);
	va_end(ap);
}
