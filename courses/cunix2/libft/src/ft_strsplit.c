#include <stdlib.h>
#include <stddef.h>

unsigned int my_strlen(const char *str)
{
	int count;
	for (count = 0; *str != '\0'; str++)
	{
		count++;
	}
	return count;
}

char **ft_strsplit (char const *s, char c)
{
	int flag,k = 0;
	char const *s1, *s2 = s;
	while (*s1 != '\0')
	{
		if (*s1 != c && flag == 0)
		{
			flag = 1;
			k++;
		}
		if (*s1 == c && flag == 1)
		{
			flag = 0;
		}
		s1++;
	}
	int *words = (int *)malloc(k*sizeof(int));
	int w, len = 0;
	flag = 0;
	while (*s2 != '\0')
	{
		if (*s2 != c && flag == 1)
		{
			len++;
		}
		if (*s2 != c && flag == 0)
		{
			flag = 1;
			len++;
		}
		if (*s2 == c && flag == 1)
		{
			flag = 0;
			words[w] = len;
			len = 0;
			w++;
		}
		s2++;
	}
	if (k == 0)
	{
		return NULL;
	}
	char **fresh = (char **)malloc(k*sizeof(char *));
	int m, n = 0;
	while (*s != '\0')
	{
		if (*s != c && flag == 1)
		{
			fresh[n][m] = *s;
			m++;
		}
		if (*s != c && flag == 0)
		{
			fresh[n] = (char *)malloc(words[n]*sizeof(char));
			flag = 1;
			fresh[n][m] = *s;
			m++;
		}
		if (*s == c && flag == 1)
		{
			flag = 0;
			m = 0;
			n++;
		}
		s++;
	}
	return fresh;
}
