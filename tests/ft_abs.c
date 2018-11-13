#include "tests/tests.h"
#include <stdio.h>
#include <strings.h>
#include <limits.h>
#include <stdlib.h>

int ft_abs(int i);

typedef int (*func_t)(int);
typedef struct {
	func_t ref;
	func_t to_test;
	const char *name;
} test_data_t;

test_state_t single_test(int i, const test_data_t *data)
{
	int ref = data->ref(i);
	int ret = data->to_test(i);
	if (ret != ref) {
		dprintf(2, "[FAIL] %1$s(%2$d) -> %3$d != ft_%1$s(%2$d) -> %4$d\n",
				data->name, i, ref, ret);
		return TEST_FAIL;
	}
	return TEST_SUCCESS;
}

test_state_t run_test(const test_data_t *data) {
	test_state_t ret = TEST_SUCCESS;

	if (single_test(0, data) == TEST_FAIL)
		ret = TEST_FAIL;
	if (single_test(-1, data) == TEST_FAIL)
		ret = TEST_FAIL;
	if (single_test(1, data) == TEST_FAIL)
		ret = TEST_FAIL;
	if (single_test(546782, data) == TEST_FAIL)
		ret = TEST_FAIL;
	if (single_test(-42348934, data) == TEST_FAIL)
		ret = TEST_FAIL;
	if (single_test(INT_MAX, data) == TEST_FAIL)
		ret = TEST_FAIL;
	if (single_test(INT_MIN, data) == TEST_FAIL)
		ret = TEST_FAIL;
	return ret;
}

int main()
{
	TEST_ARR_BEGIN(test_data_t, tests, 1)
		TEST_DATA(abs)
	TEST_ARR_END

	RUN_TESTS(tests);
	return TEST_SUCCESS;
}
