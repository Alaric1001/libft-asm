#include <unistd.h>
extern void ft_bzero(void* addr, size_t size);

int main()
{
	char a[] = "abcdfgh\0";
	ft_bzero(a, 0);
	write(1, a, 8);
}
