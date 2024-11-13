/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbento <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:04:11 by lalbento          #+#    #+#             */
/*   Updated: 2024/11/11 12:59:51 by lalbento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long long hex, int flag)
{
	char	*hex_str;
	int		i;

	i = 0;
	hex_str = "0123456789abcdef";
	if (flag)
		hex_str = "0123456789ABCDEF";
	if (hex >= 16)
		i += ft_puthex((hex / 16), flag);
	write(1, &hex_str[hex % 16], 1);
	i++;
	return (i);
}
