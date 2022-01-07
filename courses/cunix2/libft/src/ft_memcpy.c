void *ft_memcpy (void *dest, const void *source, size_t n)
{
	char *new_d = dest;
	char *new_s = source;
	for (int i = 1; i <= n; i++)
	{
		*new_d++ = *new_s++;
	}
	return dest;
}
