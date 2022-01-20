char *ft_strstr ( char *strB, char *strA)
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
				return strB;
			}
		}
		strB++;
	}

	return NULL;
}
