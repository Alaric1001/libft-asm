
#include "tests/tests.h"
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

void *ft_memchr(const void *s, int c, size_t n);

typedef void *(*func_t)(const void *, int, size_t);
typedef struct {
	func_t ref;
	func_t to_test;
	const char *name;
} test_data_t;

test_state_t single_test(const char *s, char c, size_t n, const test_data_t *data)
{
	const char *ref = data->ref(s, c, n);
	const char *ret = data->to_test(s, c, n);
	if (ret != ref) {
		dprintf(2, "[FAIL] %1$s(%2$.15s, %3$c, %4$zu) -> %5$p != ft_%1$s(%2$.15s, %3$c, %4$zu) -> %6$p\n",
				data->name, s, c, n, ref, ret);
		return TEST_FAIL;
	}
	return TEST_SUCCESS;
}

test_state_t run_test(const test_data_t *data) {
	test_state_t ret = TEST_SUCCESS;

	if (single_test("aaaaaaa", 'b', 7, data) == TEST_FAIL)
		ret = TEST_FAIL;
	if (single_test("", '1', 0, data) == TEST_FAIL)
		ret = TEST_FAIL;
	if (single_test("a", 'a', 1, data) == TEST_FAIL)
		ret = TEST_FAIL;
	if (single_test("123", '1', 3, data) == TEST_FAIL)
		ret = TEST_FAIL;
	if (single_test("123", '3', 3, data) == TEST_FAIL)
		ret = TEST_FAIL;
	if (single_test("HEllo World!", 'W', 12, data) == TEST_FAIL)
		ret = TEST_FAIL;
	return ret;
}

int main()
{
	TEST_ARR_BEGIN(test_data_t, tests, 1)
		TEST_DATA(memchr)
	TEST_ARR_END

	RUN_TESTS(tests);
	return TEST_SUCCESS;
}
