#include <stddef.h>

int ft_isascii (int ch)
{
	if ((int)ch >= 0 && (int)ch <= 127)
	{
		return 1;
	}
	return 0;
}
