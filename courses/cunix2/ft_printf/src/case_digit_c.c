#include <unistd.h>
#include "print.h"

void case_digit_c(int n, int m)
{
    while (m-- > 1)
    {
        write(1, " ", 1);
    }
    write(1, &n, 1);
}

