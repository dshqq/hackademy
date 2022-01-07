char *ft_strstr (const char *strB, const char *strA)
{
	while (*strB != '\0')
	{
		char *newA = strA;
		char *newB = strB;
		if (*newB == *newA)
		{
			while(*newA != '\0' && *newB == *newA)
			{
				newB++;
				newA++;
			}
			if (*newA == '\0')
			{
				return (char*)strB;
			}
		}
		strB++;
	}
	return NULL;
}
