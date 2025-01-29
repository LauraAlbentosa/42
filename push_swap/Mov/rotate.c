/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbento <lalbento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 20:48:17 by lalbento          #+#    #+#             */
/*   Updated: 2025/01/29 21:45:45 by lalbento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    rotate_a(t_stack **stack)
{
    t_stack *current;
    t_stack *first;

    first = *stack;
    current = *stack;
    
    while(current->next)
        current = current->next;

    current->next = first;
    *stack = first->next;
    first->next = NULL;
}


