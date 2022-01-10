#include <stddef.h>

char *ft_strnstr (const char *strB, const char *strA, size_t len)
{
	size_t count = 1;
	while (*strB != '\0' && count <= len)
	{
		char *newA = (char *)strA;
		char *newB = (char *)strB;
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
				return (char*)strB;
			}
		}
		strB++;
		count++;
	}
	return NULL;
}
