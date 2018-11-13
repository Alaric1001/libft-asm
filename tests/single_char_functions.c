#include "tests/tests.h"

#include <limits.h>
#include <stdio.h>
#include <ctype.h>

int ft_isalpha(int c);
int ft_isdigit(int c);
int ft_isalnum(int c);
int ft_isascii(int c);
int ft_isprint(int c);
int ft_isspace(int c);
int ft_toupper(int c);
int ft_tolower(int c);

typedef int (*func_t)(int);
typedef struct {
	func_t ref;
	func_t to_test;
	const char *name;
} test_data_t;

test_state_t single_test(int i, const test_data_t *data) {
	int ref;
	int res;

	ref = data->ref(i);
	res = data->to_test(i);
	if (ref != res) {
		dprintf(2, "[FAIL] %1$s(%2$i) -> %3$i != ft_%1$s(%2$i) -> %4$i\n"
				, data->name, i, ref, res);
		return TEST_FAIL;
	}
	return TEST_SUCCESS;
}

test_state_t run_test(const test_data_t *data) {
	test_state_t ret = TEST_SUCCESS;

	for (int i = -500; i < 500; ++i) {
		if (single_test(i, data) == TEST_FAIL)
			ret = TEST_FAIL;
	}
	if (single_test(INT_MAX, data) == TEST_FAIL)
		ret = TEST_FAIL;
	if (single_test(INT_MIN, data) == TEST_FAIL)
		ret = TEST_FAIL;
	return (ret);
}

int main() {
	TEST_ARR_BEGIN(test_data_t, tests, 8)
		TEST_DATA(isalpha),
		TEST_DATA(isdigit),
		TEST_DATA(isalnum),
		TEST_DATA(isascii),
		TEST_DATA(isprint),
		TEST_DATA(isspace),
		TEST_DATA(toupper),
		TEST_DATA(tolower),
	TEST_ARR_END

	RUN_TESTS(tests);
	return TEST_SUCCESS;
}
