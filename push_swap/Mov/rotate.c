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

/*

void    rotate(t_stack **stack)
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
*/

void rotate(t_stack **stack)
{
    t_stack *current;
    t_stack *first;

    if (!*stack || !(*stack)->next)
        return;

    first = *stack;
    current = *stack;
    
    while (current->next)
        current = current->next;

    current->next = first;
    first->prev = current;  // Establece el puntero prev del primer nodo
    *stack = first->next;
    first->next = NULL;
}


void    ra(t_stack **a)
{
    rotate(a);
    write(1, "ra\n", 3);
}

void    rb(t_stack **b)
{
    rotate(b);
    write(1, "rb\n", 3);
}

void    rr(t_stack **a, t_stack **b)
{
    rotate(a);
    rotate(b);
    write(1, "rr\n", 3);
}