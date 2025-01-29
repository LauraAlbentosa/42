/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbento <lalbento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 20:13:18 by lalbento          #+#    #+#             */
/*   Updated: 2025/01/29 21:10:06 by lalbento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    swap_a(t_stack **stack)
{
    t_stack *first;
    t_stack *second;
    int len;
    
    len = stack_len(stack);
    if (len < 2)
        return;
        
    first = *stack;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *stack = second;
}
