/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbento <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:50:58 by lalbento          #+#    #+#             */
/*   Updated: 2024/10/03 10:23:48 by lalbento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == 32 || (c >= '\t' && c <= '\r'))
		return (1);
	else
		return (0);
}

static int	ft_sign(int cont, char c)
{
	int	sign;

	sign = 1;
	if (cont > 0)
		sign = 0;
	else if (c == '-')
		sign = -1;
	return (sign);
}

int	ft_atoi(const char *ptr)
{
	int	i;
	int	cont;
	int	num;
	int	sign;

	sign = 1;
	cont = 0;
	i = 0;
	num = 0;
	while (ptr[i] && ft_isspace(ptr[i]))
		i++;
	while (ptr[i] && (ptr[i] == '-' || ptr[i] == '+' ))
	{
		sign = ft_sign(cont, ptr[i]);
		cont++;
		i++;
	}
	while (ptr[i] && (ptr[i] >= '0' && ptr[i] <= '9'))
	{
		num = num * 10 + (ptr[i] - '0');
		i++;
	}
	return (num * sign);
}
