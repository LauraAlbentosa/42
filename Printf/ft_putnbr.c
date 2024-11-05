int	ft_putnbr(int n)
{
	char	number;
    int len;

    len = 0;
	if (n == -2147483648)
	{
		write(0, "-2147483648", 11);
        len = 11;
		return (len);
	}
	if (n < 0)
	{
		write(0, "-", 1);
		n = n * (-1);
        len += 1;
	}
	if (n >= 10)
        len += ft_putnbr((n / 10));
	number = (n % 10) + '0';
	write(0, &number, 1);
    len += 1;
    return (len);
}
