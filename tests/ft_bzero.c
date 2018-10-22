#include <unistd.h>
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

extern void ft_bzero(void* addr, size_t size);

static int simple_tests(void)
{

	char a[] = "abcdfgh\0";
	ft_bzero(a, 0);
	if (strcmp(a, "abcdfgh\0"))
	{
		dprintf(2, "bzero(a, 0) fail: %s\n", a);
		return (0);
	}
	ft_bzero(a, 3);
	if (memcmp(a, "\0\0\0dfgh\0", 8))
	{
		dprintf(2, "bzero(a, 3) fail: %s\n", a);
		return (0);
	}
	ft_bzero(a, 8);
	if (memcmp(a, "\0\0\0\0\0\0\0\0", 8))
	{
		dprintf(2, "bzero(a, 8) fail: %s\n", a);
		return (0);
	}
	return (1);
}

static int large_tests(void)
{
	char *a = malloc(4096);
	memset(a, 0xa, 4096);
	ft_bzero(a, 4096);
	for (int i = 0; i < 4096; ++i)
		if (a[i])
		{
			dprintf(2, "large bzero, not null at index %i\n", i);
			return (0);
		}
	return (1);
}

int main()
{
	if (!simple_tests())
		return (1);
	return (!large_tests());
}
