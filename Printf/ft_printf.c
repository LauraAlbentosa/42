/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbento <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:13:51 by lalbento          #+#    #+#             */
/*   Updated: 2024/11/06 16:28:24 by lalbento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int indentify_format(int flag, int index, const char *format, va_list args)
{
    int     cont;

    cont = 0;
    if (format[index + 1] == 'i' || format[index + 1] == 'd')
        cont = ft_putnbr(va_arg(args, int));
    else if (format[index + 1] == 's')
        cont = ft_putstr(va_arg(args, char *));
    else if (format[index + 1] == 'c')
        cont = ft_putchar(va_arg(args, int));
    else if (format[index + 1] == 'p')
        cont = ft_putptr(va_arg(args, void *));
    else if (format[index + 1] == 'x' || format[index + 1] == 'X')
    {
        if (format[index + 1] == 'X')
            flag = 1;
        cont = ft_puthex(va_arg(args, unsigned int), flag);
    }
    else if (format[index + 1] == 'u')
        cont = ft_putunsigned(va_arg(args, unsigned int));
    else if (format[index + 1] == '%')
        cont = ft_putchar('%');
    else 
    {
        cont += ft_putchar('%');
        cont += ft_putchar(format[index + 1]);
    }
    return (cont);
}

int ft_printf(char const *format, ...)
{
    va_list args;
    int i;
    int b_print;

    i = 0;
    b_print = 0;
    va_start(args, format);
    while(format[i])
    {
        if (format[i] == '%')
        {
            b_print += indentify_format(0, i, format, args);
            i++;
        }
        else
            b_print += ft_putchar(format[i]);
        i++;
    }
    va_end (args);
    return(b_print);
}

