#include <stddef.h>
#include <unistd.h>

void case_s (char *s)
{
	if (s == NULL)
	{
		write(1, "(null)", 6);
	}
	while (*s != '\0')
	{
		write(1, s++, 1);
	}
}
