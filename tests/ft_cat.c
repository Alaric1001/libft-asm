#include "tests/tests.h"
#include <fcntl.h>
#include <unistd.h>

void ft_cat(int fd);

void test(const char *fname) {
	int fd = open(fname, O_RDONLY);
	if (fd >= 0) {
		ft_cat(fd);
		close(fd);
	}
}

int main()
{
	test("src/ft_bzero.s");
	test("src/ft_cat.s");
	test("t_cat");
	test("/usr/bin/ccmake");
	ft_cat(-1);
	ft_cat(42);
	return TEST_SUCCESS;
}
