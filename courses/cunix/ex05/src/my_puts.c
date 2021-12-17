#include <stdio.h>
int my_puts(const char *s)
{
	int i = 0;
	while(s[i] != '\0')
	{
		putchar(s[i]);
		i++;
	}
	putchar('\n');
	return 0;
}
