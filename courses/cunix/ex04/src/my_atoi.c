int my_atoi(const char *nptr)
{
	int flag = 1;
	int digit = 0;  
	for(int i = 0; *nptr != '\0' && ((*nptr <= '9' && *nptr >= '0') || *nptr =='-'); nptr++)
	{
		if(*nptr == '-' && i != 0)
		{
			return flag*digit;
		}
		i++;
		digit = digit*10+(*nptr - '0');
		if (*nptr == '-')
		{
			flag = -1;
			digit = digit+3;
		}
	}
	return digit*flag;
}
