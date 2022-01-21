#include <unistd.h>
#include "print.h"

void case_space(int n, int m)
{
    char *ch_sp = my_itoa(n);

    if (m == 0 && n > 0)
    {
        write(1, " ", 1);
    }

    while (m-- > my_len(n))
    {
        write(1, " ", 1);
    }

    write(1, ch_sp, my_strlen(ch_sp));
}
