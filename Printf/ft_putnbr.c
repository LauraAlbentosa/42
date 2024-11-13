/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbento <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:14:21 by lalbento          #+#    #+#             */
/*   Updated: 2024/11/11 13:00:24 by lalbento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	char	number;
	int		len;

	len = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		len = 11;
		return (len);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = n * (-1);
		len++;
	}
	if (n >= 10)
		len += ft_putnbr((n / 10));
	number = (n % 10) + '0';
	write(1, &number, 1);
	len++;
	return (len);
}
