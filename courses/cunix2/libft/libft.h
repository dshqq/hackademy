#ifndef LIBFT_H_
#define LIBFT_H_
#include <stddef.h>
#include <stdlib.h>


void ft_bzero (void *s, size_t n);
char *ft_strchr (const char *str, int ch);
int ft_isalpha (int ch);
int ft_isdigit (int ch);
int ft_isascii (int ch);
int ft_toupper (int ch);
int ft_tolower (int ch);
int ft_abs (int i);
div_t ft_div (int num, int dev);
char *ft_strstr (const char *strB, const char *strA);
char *ft_strnstr (const char *strB, const char *strA, size_t len);
void *ft_memset (void *dest, int c, size_t n);
void *ft_memcpy (void *dest, const void *source, size_t n);
int ft_memcmp (const void *arr1, const void *arr2, size_t n);
void ft_striter (char *s, void (*f)(char *));
char *ft_strjoin (char const *s1, char const *s2);
char *ft_strtrim (char const *s);
char **ft_strsplit (char const *s, char c);

#endif
