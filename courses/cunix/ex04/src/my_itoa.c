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
	int count = -1;
	int flag = 0;
	if (nmb < 0)
	{
		flag++;
		nmb *= -1;
	}
	if (nmb == 0)
	{
		count = 1;
	}
	int my_int = nmb;
	for (; my_int > 0; my_int /= 10)
	{
		count++;
	}
	char *str = (char *)malloc(count+flag*sizeof(char));
	buff = str;
	if (flag == 1)
	{
		*buff++ = '-';
	}
	if (nmb == 0)
	{
		*buff = '0';
		return str;
	}
	for (; count > -1; count--)
	{
		*buff++ = '0' + nmb/my_pow(count,10);
		nmb %= my_pow(count,10);	
	}
	*buff = '\0';
	return str;
}