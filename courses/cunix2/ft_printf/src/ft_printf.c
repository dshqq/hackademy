#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "print.h"
#include "case.h"

void ft_printf(char *format, ...)
{
    char *my_arg;
    int c, i, d, o, sp, m, l;
    char *s, *ch;
    va_list arg;
    int t = 0, p = 0, z = 0, k = 0;
    va_start(arg, format);

    for (my_arg = format; ; my_arg++)
    {
        while (*my_arg != '%' && *my_arg != '\0')
        {
            write(1, my_arg++, 1);
        }
		
        if (*my_arg == '\0')
        {
            break;
        }

        my_arg++;

        if (*my_arg == 'c')
        {
            c = va_arg(arg, int);
            write(1, &c, 1);
        }
		
        else if (*my_arg == 's')
        {
            s = va_arg(arg, char *);
            case_s(s);
        }
		
        else if (*my_arg == 'i' || *my_arg == 'd')
        {
            d = va_arg(arg, int);
            char *ch_d = my_itoa(d);

            write(1, ch_d, my_len(d));
        }

        else if (*my_arg == '%')
        {
            write(1, "%", 1);
        }

        else if (*my_arg == '0')
        {
            my_arg++;
            o = va_arg(arg, int);

            loop(&my_arg, &t);
            case_zero(o, t);
        }

        else if (*my_arg == ' ')
        {
            my_arg++;
            sp = va_arg(arg, int);

            loop(&my_arg, &p);
            case_space(sp, p);
        }

        else if (*my_arg == '+')
        {
            my_arg++;
            m = va_arg(arg, int);

            case_plus(m);

            if (*my_arg == '0')
            {
                loop(&my_arg, &z);

                while (--z > my_len(m))
                {
                    write(1, "0", 1);
                }
            }

            char *ch_m = my_itoa(m);
            write(1, ch_m, my_len(m));
        }

        else if (my_isdigit(*my_arg))
        {
            loop(&my_arg, &k);

            switch (*my_arg)
            {
                case 'd':
                case 'i': 
                    i = va_arg(arg, int);
                    case_digit_i(i, k);
                    break;

                case 's': 
                    ch = va_arg(arg, char *);
                    case_digit_s(ch, k);
                    break;

                case 'c': 
                    l = va_arg(arg, int);
                    case_digit_c(l, k);
                    break;

                case '%' : 
                    write(1, "%", 1);
                    break;
            }
        }
    }
    va_end(arg);
}
