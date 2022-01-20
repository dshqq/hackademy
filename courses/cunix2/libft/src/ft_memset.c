#include <stddef.h>

void *ft_memset (void *dest, int c, size_t n)
{
	char *new = dest;

	for (size_t i = 1; i <= n; i++)
	{
		*new++ = c;
	}

	return dest;
}
