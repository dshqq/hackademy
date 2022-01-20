#include <stddef.h>

char *ft_strnstr (char *strB, char *strA, size_t len)
{
	if(*strA == '\0')
	{
		return strB;
	}

	size_t count = 1;

	while (*strB != '\0' && count <= len)
	{
		char *newA = strA;
		char *newB = strB;
		if (*newB == *newA)
		{
			while (*newA != '\0' && *newB == *newA && count <= len)
			{
				newB++;
				newA++;
				count++;
			}
			if (*newA == '\0')
			{
				return strB;
			}
		}
		strB++;
		count++;
	}

	return NULL;
}
