
#include <unistd.h>
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <ctype.h>

int ft_isalpha(int c);

int test_alphabet(char start) {
	for (int i = 0; i < 26; ++i) {
		if (!ft_isalpha(start + i)) {
			dprintf(2, "%c not alpha. (%c, %c)\n", start + i, start, start + 25);
			return 0;
		}
	}
	return 1;
}

int test_non_alphabet(void) {
	for (int i = 0; i < 256; ++i) {
		if (!isalpha(i) && ft_isalpha(i)) {
			dprintf(2, "%i is alpha but should not.\n", i);
			return 0;
		}
	}
	return 1;
}

int main()
{
	if (!test_alphabet('A') || !test_alphabet('a'))
		return 1;
	if (!test_non_alphabet())
		return (1);
	return (0);
}
