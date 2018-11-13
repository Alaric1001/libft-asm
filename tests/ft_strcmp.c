#include "tests/tests.h"
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

int ft_strcmp(char const *s1, char const *s2);

typedef int (*func_t)(char const *s1, char const *s2);
typedef struct {
	func_t ref;
	func_t to_test;
	const char *name;
} test_data_t;

test_state_t single_test(char const *s1, const char *s2, const test_data_t *data)
{
	int ref = data->ref(s1, s2);
	int ret = data->to_test(s1, s2);
	if (ret != ref) {
		dprintf(2, "[FAIL] %1$s(%2$.15s, %3$.15s) -> %4$d != ft_%1$s(%2$.15s, %3$.15s) -> %5$d\n",
				data->name, s1, s2, ref, ret);
		return TEST_FAIL;
	}
	return TEST_SUCCESS;
}

test_state_t run_test(const test_data_t *data) {
	test_state_t ret = TEST_SUCCESS;

	if (single_test("le", "ld", data) == TEST_FAIL)
		ret = TEST_FAIL;
	if (single_test("e", "d", data) == TEST_FAIL)
		ret = TEST_FAIL;
	if (single_test("Hello world", "Hello world", data) == TEST_FAIL)
		ret = TEST_FAIL;
	if (single_test("Hello", "Hello world", data) == TEST_FAIL)
		ret = TEST_FAIL;
	if (single_test("Hello world", "Hello", data) == TEST_FAIL)
		ret = TEST_FAIL;
	if (single_test("", "", data) == TEST_FAIL)
		ret = TEST_FAIL;
	if (single_test("s", "", data) == TEST_FAIL)
		ret = TEST_FAIL;
	return ret;
}

int main()
{
	TEST_ARR_BEGIN(test_data_t, tests, 1)
		TEST_DATA(strcmp)
	TEST_ARR_END

	RUN_TESTS(tests);
	return TEST_SUCCESS;
}
