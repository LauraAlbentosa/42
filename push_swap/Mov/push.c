/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbento <lalbento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:21:26 by lalbento          #+#    #+#             */
/*   Updated: 2025/01/29 21:35:07 by lalbento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    push_a(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *first_b;

    if (!*stack_b)
        return;
    first_b = *stack_b;
    *stack_b = (*stack_b)->next;
    first_b->next = *stack_a;
    *stack_a = first_b;
    write(1, "pa\n", 3);
}

void    push_b(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *first_b;

    if (!*stack_b)
        return;
    first_b = *stack_b;
    *stack_b = (*stack_b)->next;
    first_b->next = *stack_a;
    *stack_a = first_b;
    write(1, "pb\n", 3);
}