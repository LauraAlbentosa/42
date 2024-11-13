/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbento <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:13:51 by lalbento          #+#    #+#             */
/*   Updated: 2024/11/11 12:49:40 by lalbento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	indentify_format(int flag, char format, va_list args, int len)
{
	if (format == 'i' || format == 'd')
		len += ft_putnbr(va_arg(args, int));
	else if (format == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (format == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (format == 'p')
		len += ft_putptr(va_arg(args, void *));
	else if (format == 'x' || format == 'X')
	{
		if (format == 'X')
			flag = 1;
		len += ft_puthex(va_arg(args, unsigned int), flag);
	}
	else if (format == 'u')
		len += ft_putunsigned(va_arg(args, unsigned int));
	else if (format == '%')
		len += ft_putchar('%');
	else
	{
		len += ft_putchar('%');
		len += ft_putchar(format);
	}
	return (len);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		i;
	int		b_print;

	i = 0;
	b_print = 0;
	if (format == NULL)
		return (0);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				break ;
			b_print += indentify_format(0, format[i + 1], args, 0);
			i++;
		}
		else
			b_print += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (b_print);
}
