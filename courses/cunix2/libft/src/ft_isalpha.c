#include "../libft.h"
#include <stddef.h>

int isalpha (int ch)
{
	if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
	{
		return 1;
	}
	return 0;
}
