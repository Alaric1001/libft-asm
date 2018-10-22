#include <unistd.h>
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

extern char *ft_strcat(char *s1, char const *s2);

static int cmp(char *s1, size_t s1_size, char const *s2)
{
	char tmp[s1_size];
	memcpy(tmp, s1, s1_size);
	return (strcmp(strcat(tmp, s2), ft_strcat(s1, s2)));
}

static int simple_test(void)
{
	char s1[50] = "123";
	char s2[]	= "456789";
	if (cmp(s1, 50, s2))
	{
		dprintf(2, "simple test fail. s1: %s\n", s1);
		return (0);
	}
	return (1);
}

static int check_auto_end_null(void)
{
	char s1[50] = "123";
	char s2[]	= "456789";
	if (cmp(s1, 50, s2))
	{
		dprintf(2, "check_auto_end_null fail. s1: %s\n", s1);
		return (0);
	}
	return (1);
}

static int check_null_ptrs(void)
{
	char test[] = "abc";
	char *ret;
	if ((ret = ft_strcat(NULL, test)))
	{
		dprintf(2, "ft_strcat(null, test) return something: %p", ret);
		return (0);
	}
	if (strcmp(ft_strcat(test, NULL), "abc"))
	{
		dprintf(2, "ft_strcat(test, null) return something bad: %p", ret);
		return (0);
	}
	return (1);
}

int main()
{
	if (!simple_test())
		return (1);
	if (!check_auto_end_null())
		return (1);
	if (!check_null_ptrs())
		return (1);
	return (0);
}
