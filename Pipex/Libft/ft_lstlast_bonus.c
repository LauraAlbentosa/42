/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbento <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 23:13:01 by lalbento          #+#    #+#             */
/*   Updated: 2024/10/03 11:38:45 by lalbento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int	i;
	int	size;

	i = 0;
	size = ft_lstsize(lst);
	while (lst != NULL && i < (size - 1))
	{
		lst = lst->next;
		i++;
	}
	return (lst);
}
