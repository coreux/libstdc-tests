/* Perform logging during tests */

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
	
	/* The severity (TEST_xxx constants) is not currently used */
	(void) severity;
	
	va_start(ap, format);
	fprintf(stderr, "%s: ", file);
	vfprintf(stderr, format, ap);
	va_end(ap);
}
