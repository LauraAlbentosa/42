/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbento <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:00:48 by lalbento          #+#    #+#             */
/*   Updated: 2024/10/03 10:29:55 by lalbento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char	*ptr;
	int			i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			ptr = s + i;
			return ((char *)ptr);
		}
		i++;
	}
	if (s[i] == (char)c)
	{
		ptr = s + i;
		return ((char *)ptr);
	}
	return (NULL);
}
