#include <unistd.h>
#include "print.h"

void case_digit_s(char *c, int n)
{
    if (c == NULL)
    {
        while (n - 6 > 0)
        {
            write(1, " ", 1);
            n--;
        }
        write(1, "(null)", 6);
    }

    else
    {
        while (n-- > my_strlen(c))
        {
            write(1, " ", 1);
        }

        while (*c != '\0')
        {
            write(1, c++, 1);
        }
    }
}
