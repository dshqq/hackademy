#include <stddef.h>

void *ft_memcpy (void *dest, const void *source, size_t n)
{
	char *new_d = (char *)dest;
	char *new_s = (char *)source;
	for (size_t i = 1; i <= n; i++)
	{
		*new_d++ = *new_s++;
	}
	return (void *)dest;
}
