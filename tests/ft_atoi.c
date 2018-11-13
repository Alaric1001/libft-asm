
#include "tests/tests.h"
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <limits.h>

int ft_atoi(char const *s);

typedef int (*func_t)(char const *s);
typedef struct {
	func_t ref;
	func_t to_test;
	const char *name;
} test_data_t;

test_state_t single_test(const char *s, const test_data_t *data) {
	int ret = data->to_test(s);
	int ref = data->ref(s);
	if (ret != ref) {
		dprintf(2, "[FAIL] %1$s(%2$.10s) -> %3$d != ft_%1$s(%2$.10s) -> %4$d\n",
				data->name, s, ref, ret);
		return TEST_FAIL;
	}
	return TEST_SUCCESS;
}


test_state_t run_test(const test_data_t *data) {
	test_state_t ret = TEST_SUCCESS;
	
	if (single_test("42", data) == TEST_FAIL)
		ret = TEST_FAIL;
	if (single_test(" 104", data) == TEST_FAIL)
		ret = TEST_FAIL;
	if (single_test("  512", data) == TEST_FAIL)
		ret = TEST_FAIL;
	if (single_test(" 	 4000", data) == TEST_FAIL)
		ret = TEST_FAIL;
	if (single_test("  .512", data) == TEST_FAIL)
		ret = TEST_FAIL;
	if (single_test("+2147483647", data) == TEST_FAIL)
		ret = TEST_FAIL;
	if (single_test("+1", data) == TEST_FAIL)
		ret = TEST_FAIL;
	if (single_test(" +0", data) == TEST_FAIL)
		ret = TEST_FAIL;
	if (single_test("  -0", data) == TEST_FAIL)
		ret = TEST_FAIL;
	if (single_test("-6", data) == TEST_FAIL)
		ret = TEST_FAIL;
	if (single_test("-1205", data) == TEST_FAIL)
		ret = TEST_FAIL;
	if (single_test("    -2147483648", data) == TEST_FAIL)
		ret = TEST_FAIL;

	return ret;
}

int main()
{
	TEST_ARR_BEGIN(test_data_t, tests, 1)
		TEST_DATA(atoi)
	TEST_ARR_END

	RUN_TESTS(tests);
	return TEST_SUCCESS;
}
