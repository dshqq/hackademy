int my_len(int k)
{
    if (k == 0)
    {
        return 1;
    }

    int flag = 0;
    int count = 0;

    if (k < 0)
    {
        flag++;
    }

    while (k != 0)
    {
        k /= 10;
        count++;
    }

    return count + flag;
}

