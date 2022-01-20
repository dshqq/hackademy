int my_pow (int a, int b)
{
	if (a == 0)
	{
		return  1;
	}
	int k = b;
	for (int i = 1; i < a; i++)
	{
		k *= b;
	}
	return k;
}
