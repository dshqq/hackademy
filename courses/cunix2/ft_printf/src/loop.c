#include "print.h"

void loop(char **c, int *n)
{
    while (my_isdigit(**c))
    {
        (*n) = (*n) * 10 + my_atoi(**c);
        (*c)++;
    }
}
