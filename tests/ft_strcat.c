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

test_state_t single_test(char *s1, size_t s1_size, const char *s2, const test_data_t *dat)
{
	char tmp[s1_size];
	char original_s1[s1_size];
	memcpy(tmp, s1, s1_size);
	memcpy(original_s1, s1, s1_size);
	if (strcmp(dat->ref(tmp, s2), dat->to_test(s1, s2))) {
		dprintf(2, "[FAIL] %s(%s, %s) :  %s != %s \n", dat->name, original_s1, s2, s1, tmp);
	}
	return TEST_SUCCESS;
}

test_state_t check_null_ptrs(const test_data_t *data)
{
	test_state_t ret = TEST_SUCCESS;
	char test[] = "abc";
	char *ptr;
	if ((ptr = data->to_test(NULL, test)))
	{
		dprintf(2, "ft_strcat(null, test) return something: %p", ptr);
		ret = TEST_FAIL;
	}
	if (single_test(test, 3, NULL, data))
		ret = TEST_FAIL;
	return ret;
}

test_state_t run_test(const test_data_t *data) {
	test_state_t ret = TEST_SUCCESS;

	char s1[50] = "123";
	char cat[]	= "456789";
	if (single_test(s1, 50, cat, data) == TEST_FAIL)
		ret = TEST_FAIL;

	char s2[50] = "123";
	if (single_test(s2, 50, cat, data) == TEST_FAIL)
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
