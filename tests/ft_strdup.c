#include "tests/tests.h"
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

#define LOREM "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Etiam quis nunc risus. In nibh lorem, dictum eget gravida iaculis, luctus eget ex. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Proin laoreet erat sed facilisis iaculis. In hac habitasse platea dictumst. Nunc lobortis ante sed sollicitudin hendrerit. Suspendisse felis odio, porta sit amet porta vel, imperdiet ac mauris. Maecenas mattis lacus nisl, vitae vulputate magna commodo at. Quisque a aliquam dolor, sit amet congue justo. Curabitur maximus ex metus, eu mollis tellus tristique quis. Praesent ut lectus metus. Nullam purus massa, maximus ac aliquet porttitor, tempor eu metus. Sed dignissim dapibus erat in suscipit. Nunc lectus velit, pretium vel sem et, tempus aliquam ligula. Nullam viverra magna ac ex ullamcorper, sit amet maximus nisi malesuada. Vivamus vel rhoncus augue, nec condimentum libero."

char *ft_strdup(char const *s);

typedef char *(*func_t)(char const *);
typedef struct {
	func_t ref;
	func_t to_test;
	const char *name;
} test_data_t;

test_state_t single_test(const char *s, const test_data_t *data) {
	test_state_t state = TEST_SUCCESS;
	char* ref = data->ref(s);
  	char* ret = data->to_test(s);
	if (ref == ret || (!ref && ret) || strcmp(ref, ret)) {
		dprintf(2, "[FAIL] %1$s(%2$.10s) -> %3$p, %3$s != ft_%1$s(%2$.10s) -> %4$p, %4$s\n",
				data->name, s, ref, ret);
		state = TEST_FAIL;
	}
	free(ref);
	free(ret);
	return state;
}


test_state_t run_test(const test_data_t *data) {
	test_state_t ret = TEST_SUCCESS;
	
	if (single_test("123456", data) == TEST_FAIL)
		ret = TEST_FAIL;
	if (single_test("1", data) == TEST_FAIL)
		ret = TEST_FAIL;
	if (single_test("", data) == TEST_FAIL)
		ret = TEST_FAIL;
	if (single_test(LOREM, data) == TEST_FAIL)
		ret = TEST_FAIL;
	return ret;
}

int main()
{
	TEST_ARR_BEGIN(test_data_t, tests, 1)
		TEST_DATA(strdup)
	TEST_ARR_END

	RUN_TESTS(tests);
	return TEST_SUCCESS;
}
