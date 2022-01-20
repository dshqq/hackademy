#include <unistd.h>
#include "print.h"

void case_digit_i (int n, int m)
{
	char *ch_i = my_itoa(n);
	while(m-- > my_len(n))
	{
		write(1, " ", 1);
	}
	write(1, ch_i, my_len(n));
}
