#include <unistd.h>
#include "case.h"

void case_plus(int n)
{
	if (n >= 0)
	{
		write(1, "+", 1);
	}
	else if (n < 0)
	{
		n *= -1;
	}
}
