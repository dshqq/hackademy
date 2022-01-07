#include "../libft.h"
#include <stddef.h>

int ft_asascii (int ch)
{
	if ((int)ch >= 0 && (int)ch <= 127)
	{
		return 1;
	}
	return 0;
}
