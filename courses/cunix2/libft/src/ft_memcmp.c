void *ft_memcmp (const void *arr1, const void *arr2, size_t n)
{
	char *new_1 = arr1;
	char *new_2 = arr2;
	for (int i = 1; i <= n; i++)
	{
		if (*new_1 > *new_2)
		{
			return 1;
		}
		else if (*new_1 < *new_2)
		{
			return -1;
		}
		new_1++;
		new_2++;
	}
	return 0;
}
