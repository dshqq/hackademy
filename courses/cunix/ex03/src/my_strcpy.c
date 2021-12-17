char *my_strcpy(char *dest, const char *src)
{
	char *my_char = dest;
	while((*dest++ = *src++) != '\0')
		;
return my_char;
}

