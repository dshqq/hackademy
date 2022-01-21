#include <unistd.h>
#include "print.h"

void case_zero(int n, int m)
{
    if (n < 0)
    {
        write(1, "-", 1);
        n *= -1;
        m--;
    }

    char *ch_o = my_itoa(n);

    while (m-- > my_len(n))
    {
        write(1, "0", 1);
    }

    write(1, ch_o, my_strlen(ch_o));
}
