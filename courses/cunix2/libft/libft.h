#ifdef LIBFT_H_
#define LIBFT_H_
#include <stddef.h>


void ft_bzero(void *s, size_t n);
char *ft_strchr(const char *str, int ch);
int ft_isalpha(int ch);
int ft_isdigit(int ch);
int ft_isascii(int ch);
int ft_toupper(int ch);
int ft_tolower(int ch);

#endif
