/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbento <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:13:31 by lalbento          #+#    #+#             */
/*   Updated: 2024/10/03 10:27:16 by lalbento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr_s;
	unsigned char	c_copy;
	size_t			i;

	ptr_s = (unsigned char *)s;
	c_copy = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (ptr_s[i] == c_copy)
			return ((void *)&ptr_s[i]);
		i++;
	}
	return (NULL);
}
