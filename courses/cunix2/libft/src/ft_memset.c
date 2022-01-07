void *ft_memset (void *dest, int c, size_t n)
{
	char *new = dest;
	for (int i = 1; i <= n; i++)
	{
		*new++ = c;
	}
	return dest;
}
