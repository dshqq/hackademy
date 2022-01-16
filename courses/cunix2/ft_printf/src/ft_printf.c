#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

int my_strlen(char *str)
{
	int count;
	for (count = 0; *str != '\0'; str++)
	{
		++count;
	}
	return count;
}

int my_isdigit (int ch)
{
	if (ch >= '0' && ch <= '9')
	{
		return 1;
	}
	return 0;
}

int my_len (int k)
{
	if (k == 0)
	{
		return 1;
	}
	int flag = 0;
	if (k < 0)
	{
		flag++;
	}
	int count = 0;
	while (k != 0)
	{
		k /= 10;
		count++;
	}
	return count+flag;
}

int my_atoi (char nptr)
{
	int digit = 0;
	digit = nptr - '0';
	return digit;
}

int my_pow (int a, int b)
{
	if (a == 0)
	{
		return 1;
	}
	int k = b;
	for (int i = 1; i < a; i++)
	{
		k *= b;
	}
	return k;
}

char *my_itoa (int nmb)
{
	char *buff;
	int count = -1;
	int flag = 0;
	if (nmb < 0)
	{
		flag++;
		nmb *= -1;
	}
	if (nmb == 0)
	{
		count = 1;
	}
	int my_int = nmb;
	for (; my_int > 0; my_int /= 10)
	{
		count++;
	}
	char *str = (char *)malloc(count+flag*sizeof(char));
	buff = str;
	if (flag == 1)
	{
		*buff++ = '-';
	}
	if (nmb == 0)
	{
		*buff = '0';
		return str;
	}
	for (; count > -1; count--)
	{
		*buff++ = '0' + nmb/my_pow(count, 10);
		nmb %= my_pow(count,10);
	}
	*buff = '\0';	
	return str;
}

void ft_printf (char* format, ...)
{
	char *my_arg;
	int c, i, d, o, sp, m, k, l;
	char *s, *ch;
	va_list arg;
	int t, p, z = 0;
	va_start(arg, format);

	for(my_arg = format; ; my_arg++)
	{
		while (*my_arg != '%' && *my_arg != '\0')
		{
			write(1, my_arg++, 1);
		}
		
		if(*my_arg == '\0')
		{
			break;
		}
		my_arg++;

		switch (*my_arg)
		{
			case 'c': c = va_arg(arg, int);
				  write(1, &c, 1);
				  break;

			case 's': s = va_arg(arg, char *);
				  if(s == NULL)
				  {
					  write(1, "(null)", 6);
				  }
				  while (*s != '\0')
				  {
					  write(1, s++, 1);
				  }
				  break;

			case 'i':
			case 'd': d = va_arg(arg, int);
				  char *ch_d = my_itoa(d);
				  write(1, ch_d, my_len(d));
				  break;

			case '%': write(1, "%", 1);
				  break;

			case '0': my_arg++;
				  while (my_isdigit(*my_arg))
				  {
					  t = t*10 + my_atoi(*my_arg++);
				  }
				  o = va_arg(arg, int);
				  if(o < 0)
				  {
					  write(1, "-", 1);
					  o *= -1;
					  t--;
				  }

				  char *ch_o = my_itoa(o);
				  while (t-- > my_len(o))
				  {
					  write(1, "0", 1);
				  }
				  write(1, ch_o, my_strlen(ch_o));
				  break;

			case ' ': my_arg++;
				  while (my_isdigit(*my_arg))
				  {
					  p = p*10 + my_atoi(*my_arg);
					  my_arg++;
				  }
				  sp = va_arg(arg, int);
				  char *ch_sp = my_itoa(sp);
				  if (p == 0 && sp > 0)
				  {
					  write(1, " ", 1);
			          }
				  while (p-- > my_len(sp))
				  {
					  write(1, " ", 1);
				  }
				  write(1, ch_sp, my_strlen(ch_sp));
				  break;

			case '+': my_arg++;
				  m = va_arg(arg, int);
				  if(m >= 0)
				  {
					  write(1, "+", 1);
				  }
				  else if (m < 0)
				  {
					  write(1, "-", 1);
					  m *= -1;
				  }
				 
				  if(*my_arg == '0')
				  {
					  while (my_isdigit(*my_arg))
					  {
						  z = z*10 + my_atoi(*my_arg++);
					  }
					  while (--z > my_len(m))
					  {
						  write(1, "0", 1);
					  }
				  }
				  char *ch_m = my_itoa(m);
				  write(1, ch_m, my_len(m));
				  break;
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9': while (my_isdigit (*my_arg))
				  {
					  k = k*10 + my_atoi(*my_arg++);
				  }
				  switch (*my_arg)
				  {
					  case 'd':
					  case 'i': i = va_arg(arg, int);
						    char *ch_i = my_itoa(i);
						    while (k-- > my_len(i))
						    {
							    write (1, " ", 1);
						    }
						    write(1, ch_i, my_len(i));
						    break;
					  case 's': ch = va_arg(arg, char *);
						    if(ch == NULL)
						    {
							    while(k-6 > 0)
							    {
								    write(1, " ", 1);
							    }
							    write(1, "(null)", 6);
							    break;
						    }
						    while (k-- > my_strlen(ch))
						    {
							    write(1, " ", 1);
						    }
						    while (*ch != '\0')
						    {
							    write (1, ch++, 1);
						    }
						    break;
					  case 'c': l = va_arg(arg, int);
						    while (k-- > 1)
						    {
							    write(1, " ", 1);
						    }
						    write(1, &l, 1);
						    break;
					  case '%' : write(1, "%", 1);
						     break;
				  }
		}
	}
	va_end(arg);
}
