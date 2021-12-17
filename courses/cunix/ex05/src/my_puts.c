#include <stdio.h>
#include <unistd.h>
int my_puts(const char *s)
{
	while(*s != '\0')
	{
		if (write(1,s++,1) == '\0')
		{
			return '\0';
		}

	}
	if (write(1,"\n",1) == '\0')
	{
		return '\0';
	}
	return 0;
}
