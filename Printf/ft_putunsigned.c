/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbento <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:04:00 by lalbento          #+#    #+#             */
/*   Updated: 2024/11/08 15:16:37 by lalbento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putunsigned(unsigned int u_num)
{
    char	number;
    int len;

    len = 0;
	if (u_num >= 10)
        len += ft_putnbr((u_num / 10));
	number = (u_num % 10) + '0';
	write(0, &number, 1);
    len++;
    return (len);
}
