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

#ifdef TEST_SKIP_C11_
int
main(int argc, char **argv)
{
	(void) argc;
	
	testlogf(argv[0], TEST_SKIP, "SKIP: a C11 compilation environment is not available (__STDC_VERSION__ = %ld)\n", (long) __STDC_VERSION__);
	return TEST_SKIP;
}
#endif
