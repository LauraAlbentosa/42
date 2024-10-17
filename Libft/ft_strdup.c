/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbento <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:59:18 by lalbento          #+#    #+#             */
/*   Updated: 2024/10/03 10:30:12 by lalbento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen((char *)s);
	ptr = malloc((len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (i < len)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
