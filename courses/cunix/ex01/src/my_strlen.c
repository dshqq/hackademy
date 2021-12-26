unsigned int my_strlen(char *str)
{
	int count;
	for (count = 0; *str != '\0' ; str++)
	{
		++count;
	}
	return count;
}
