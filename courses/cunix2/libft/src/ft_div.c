#include <math.h>
#include <stdio.h>
#include <stdlib.h>


div_t div (int num, int den)
{
	div_t division;
	division.quot = num/den;
	division.rem = num%den;
	return division;
}
