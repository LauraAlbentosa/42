/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbento <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:24:11 by lalbento          #+#    #+#             */
/*   Updated: 2024/10/07 17:47:56 by lalbento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_char(const char *set, char c)
{
	if (ft_strchr(set, (int)c))
		return (1);
	else
		return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*newstr;
	int		i;
	int		j;
	int		len;
	int		k;

	i = 0;
	k = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[i] && check_char(set, s1[i]))
		i++;
	j = ft_strlen(s1);
	while (j > i && check_char(set, s1[j - 1]))
		j--;
	len = j - i;
	newstr = (char *)malloc((len + 1) * sizeof(char));
	if (newstr == NULL)
		return (NULL);
	while (i < j)
		newstr[k++] = s1[i++];
	newstr[k] = '\0';
	return (newstr);
}

int	main(void)
{
	char	s1[] = "adios";
	char 	set[] = "o";

	printf("%s", ft_strtrim(s1, set));
	return (0);
}
