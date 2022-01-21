#include <stdlib.h>


unsigned int my_strlen(const char *str)
{
    int count;

    for (count = 0; *str != '\0'; str++)
    {
        count++;
    }

    return count;
}

char *ft_strjoin(const char *str1, const char *str2)
{
    if (my_strlen(str1) == 0 && my_strlen(str2) == 0)
    {
        return NULL;
    }

    char *fresh_1 = (char *)(malloc(my_strlen(str1) + my_strlen(str2) + 1));
    char *fresh = fresh_1;

    while (*str1 != '\0')
    {
        *fresh++ = *str1++;
    }

    while (*str2 != '\0')
    {
        *fresh++ = *str2++;
    }

    *fresh = '\0';

    return fresh_1;
}
