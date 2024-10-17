/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbento <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:36:42 by lalbento          #+#    #+#             */
/*   Updated: 2024/10/03 10:26:46 by lalbento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	length_num(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	if (n < 0)
		len++;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	unsigned int	num;
	char			*number;
	int				i;
	int				len_num;

	i = 0;
	num = (unsigned int)n;
	len_num = length_num(n);
	number = malloc((len_num + 1) * sizeof(char));
	if (number == NULL)
		return (NULL);
	if (n < 0)
	{
		number[i] = '-';
		num = (unsigned int)(-n);
		i = 1;
	}
	number[len_num] = '\0';
	while (len_num > i)
	{
		number[len_num - 1] = (num % 10) + '0';
		num = num / 10;
		len_num--;
	}
	return (number);
}
