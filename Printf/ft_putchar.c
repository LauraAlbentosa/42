int	ft_putchar_fd(char c)
{
	write(0, &c, 1);
    return (1);
}