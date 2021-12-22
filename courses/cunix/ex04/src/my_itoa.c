#include <stdlib.h>
char *my_itoa(int nmb)
{
	if(nmb == 0)
	{
		return "0";
	}
	int count = 0;
	char *buff = (char *)malloc(100*sizeof(char));
	int my_int = nmb;
	int my_int2 = nmb;
	for (; my_int != 0; my_int /=10)
	{
		count++;
	}
	for ( int i = count-1; i >= -1; i--)
	{
		buff[i] = 48 + my_int2%10;
		my_int2 = my_int2/10;
	}
	return buff;

}
