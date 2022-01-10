#include <stdlib.h>


unsigned int my_strlen(char *str)
{
	int count;
	for (count = 0; *str != '\0'; str++)
	{
		count++;
	}
	return count;
}


char *ft_strtrim (const char *s)
{
	char *s1 = (char *)s;
	int i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		s1++;
		i++;
	}
	int k = my_strlen(s1);
	while (s1[k-1] == ' ' || s1[k-1] == '\n' || s1[k-1] == '\n')
	{
		k--;
	}
	if (k == 0)
	{
		return NULL;
	}
	char *fresh = (char *)(malloc(k+1));
	for (int j = 0; j < k; j++)
	{
		fresh[j] = s1[j];
	}
	fresh[k] = '\0';
	return fresh;
}
