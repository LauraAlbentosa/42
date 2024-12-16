/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbento <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 09:41:22 by lalbento          #+#    #+#             */
/*   Updated: 2024/10/03 12:31:17 by lalbento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numstr(char const *s, char c)
{
	int	i;
	int	number;
	int	cont;

	i = 0;
	cont = 0;
	number = 0;
	while (s[i])
	{
		if (s[i] != c && !cont)
		{
			cont = 1;
			number++;
		}
		else if (s[i] == c)
			cont = 0;
		i++;
	}
	return (number);
}

static int	free_malloc(char **array, int index)
{
	if (!array[index])
	{
		while (index >= 0)
		{
			free(array[index]);
			index--;
		}
		free(array);
		return (0);
	}
	return (1);
}

static char	**create_substr(char const *s, char c, char **array)
{
	int		i;
	int		j;
	int		index;

	i = 0;
	j = 0;
	index = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
		{
			array[index] = ft_substr(s, j, i - j);
			if (!free_malloc(array, index))
				return (NULL);
			index++;
		}
	}
	array[index] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		num_str;

	num_str = numstr(s, c);
	array = (char **)malloc((num_str + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	array = create_substr(s, c, array);
	return (array);
}
