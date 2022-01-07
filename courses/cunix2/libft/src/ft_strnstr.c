char *ft_strnstr (const char *strB, const char *strA, size_t len)
{
	int count = 1;
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
				return (char*)strB;
			}
		}
		strB++;
		count++;
	}
	return NULL;
}
