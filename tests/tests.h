#ifndef TESTS_H
#define TESTS_H

#include <stdint.h>

typedef uint8_t test_state_t;

#define TEST_SUCCESS 0x0
#define	TEST_FAIL 0x1

#define TEST_ARR_BEGIN(type, id, c)	static size_t id ## _size = c;			\
								static __const type id [c] = {

#define TEST_ARR_END };

#define TEST_DATA(FUNC) {FUNC, ft_ ## FUNC, #FUNC}


#define RUN_TESTS(id) 	for (size_t s = 0; s < id ## _size; ++s) {	\
							if (run_test(&id[s]) == TEST_FAIL)		\
								return (TEST_FAIL);					\
						}
#endif
