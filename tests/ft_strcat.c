#include "tests/tests.h"
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

char *ft_strcat(char *s1, char const *s2);


typedef char *(*func_t)(char *, char const *s2);
typedef struct {
	func_t ref;
	func_t to_test;
	const char *name;
} test_data_t;

test_state_t single_test(char const* dest, size_t dest_size, const char *src, const test_data_t *data)
{
	char s1[dest_size];
	char s2[dest_size];
	memcpy(s1, dest, dest_size);
	memcpy(s2, dest, dest_size);
	char* ref = data->ref(s1, src);
  	char* ret = data->to_test(s2, src);
	if (ref != s1 || ret != s2 || strcmp(s1, s2)) {
		dprintf(2, "[FAIL] %1$s(%2$.10s, %3$.10s) -> %4$p, %5$s != ft_%1$s(%2$.10s, %3$.10s) -> %6$p, %7$s\n",
				data->name, dest, src, ref, s1, ret, s2);
		return TEST_FAIL;
	}
	return TEST_SUCCESS;
}

test_state_t run_test(const test_data_t *data) {
	test_state_t ret = TEST_SUCCESS;

	char s1[16] = "123\0";
	char cat[]	= "456789";
	if (single_test(s1, 50, cat, data) == TEST_FAIL)
		ret = TEST_FAIL;
	if (single_test(s1, 50, cat, data) == TEST_FAIL)
		ret = TEST_FAIL;

	char s2[50] = "test\0aaaaaaaaaaaaaaaaaaaaaaaaaa";
	if (single_test(s2, 50, "bbb", data) == TEST_FAIL)
		ret = TEST_FAIL;
	if (single_test(s2, 50, "", data) == TEST_FAIL)
		ret = TEST_FAIL;
	s2[0] = 0;
	if (single_test(s2, 50, "", data) == TEST_FAIL)
		ret = TEST_FAIL;
	if (single_test(s2, 50, "123", data) == TEST_FAIL)
		ret = TEST_FAIL;
	return ret;
}

int main()
{
	TEST_ARR_BEGIN(test_data_t, tests, 1)
		TEST_DATA(strcat)
	TEST_ARR_END

	RUN_TESTS(tests);
	return TEST_SUCCESS;
}
