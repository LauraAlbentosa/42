/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbento <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:39:09 by lalbento          #+#    #+#             */
/*   Updated: 2024/10/01 11:50:22 by lalbento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*first;
	t_list	*safe;

	first = *lst;
	while (first != NULL)
	{
		safe = first->next;
		del(first->content);
		free(first);
		first = safe;
	}
	*lst = NULL;
}
