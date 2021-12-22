#include <stdio.h>
#include <stdlib.h>


int my_pow(int a, int b)
{
	if (a == 0)
	{
		return 1;
	}
	int k = b;
	for (int i = 1; i < a; i++)
	{
		k *= b;
	}
	return k;
}

char *my_itoa(int nmb)
{
	char *buff;
        char *str = (char *)malloc(100*sizeof(char));
	buff = str;
	int my_int = nmb;
	int count = 0;
	for (; my_int != 1; my_int /= 10)
	{
		count++;
	}
	for (; count > -1; count--)
	{
		*buff++ = '0' + nmb/my_pow(count,10);
		nmb %= my_pow(count,10);
		
	}
	*buff = '\0';
	return str;
}
