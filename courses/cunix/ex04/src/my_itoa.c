#include <stdlib.h>
char *my_itoa(int nmb)
{
	char *buff = malloc(100*sizeof(char));
	int my_int = nmb;
	int count = 0;
	for (; my_int != 0; my_int /=10)
	{
		count++;
	}
	for (; nmb != 0; count-- )
	{
		*buff++ = '0' + nmb/(10*count);
		nmb = nmb%(10*count);
	}
	*buff = '\0';
	return buff;

}
