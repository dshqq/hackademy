#include <stddef.h>


char *ft_strchr(const char *str, int ch)
{
	
	while (*str++ != '\0')
	{
		if (*str == ch)
		{
			return (char *)str;
		}
	}
	return NULL;
}
