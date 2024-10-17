/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbento <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:19:28 by lalbento          #+#    #+#             */
/*   Updated: 2024/10/03 10:34:44 by lalbento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*ptr;
	int			i;

	i = 0;
	ptr = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			ptr = s + i;
		i++;
	}
	if (s[i] == (char)c)
	{
		ptr = s + i;
		return ((char *)ptr);
	}
	if (ptr == 0)
		return (NULL);
	else
		return ((char *)ptr);
}
