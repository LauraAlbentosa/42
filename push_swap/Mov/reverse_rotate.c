/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbento <lalbento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:35:54 by lalbento          #+#    #+#             */
/*   Updated: 2025/01/29 21:45:42 by lalbento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    reverse_rotate(t_stack **stack)
{
    t_stack *current;
    t_stack *second_last;
    t_stack *last;

    current = *stack;

    while(current->next->next)
        current = current->next;

    second_last = current;
    last = current->next;

    second_last->next = NULL;
    last->next = *stack;
    *stack = last;
}

void    rra(t_stack **a)
{
    reverse_rotate(a);
    write(1, "rra\n", 4);
}
void    rrb(t_stack **b)
{
    reverse_rotate(b);
    write(1, "rrb\n", 4);
}
void    rrr(t_stack **a, t_stack **b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    write(1, "rrr\n", 4);
}

