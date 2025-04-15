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

/*
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
    t_stack *first_a;

    if (!*stack_a)
        return;
    first_a = *stack_a;
    *stack_a = (*stack_a)->next;
    first_a->next = *stack_b;
    *stack_b = first_a;
    write(1, "pb\n", 3);
}




void push_b(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *first_b;

    if (!*stack_b)
        return;
    first_b = *stack_b;
    *stack_b = (*stack_b)->next;
    if (*stack_b)
        (*stack_b)->prev = NULL;
    first_b->next = *stack_a;
    if (*stack_a)
        (*stack_a)->prev = first_b;
    *stack_a = first_b;
    write(1, "pb\n", 3);
}

void push_a(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *first_b;

    if (!*stack_b)
        return;
    first_b = *stack_b;
    *stack_b = (*stack_b)->next;
    if (*stack_b)
        (*stack_b)->prev = NULL;  // Asegurarse de que el siguiente nodo apunta a NULL
    first_b->next = *stack_a;
    if (*stack_a)
        (*stack_a)->prev = first_b;  // Asegurarse de que el nodo de destino apunta correctamente al primero
    *stack_a = first_b;
    write(1, "pa\n", 3);
}
void push_b(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *first_a;

    if (!*stack_a)
        return;
    first_a = *stack_a;
    *stack_a = (*stack_a)->next;
    if (*stack_a)
        (*stack_a)->prev = NULL;
    first_a->next = *stack_b;
    if (*stack_b)
        (*stack_b)->prev = first_a;
    *stack_b = first_a;
    write(1, "pb\n", 3);
}
*/


static void	push(t_stack **dst, t_stack **src) 
{
	t_stack	*push_node; 

	if (!*src) 
		return ;
	push_node = *src; 
	*src = (*src)->next; 
	if (*src) 
		(*src)->prev = NULL; 
	push_node->prev = NULL; 
	if (!*dst) 
	{
		*dst = push_node; 
		push_node->next = NULL; 
	}
	else 
	{
		push_node->next = *dst; 
		push_node->next->prev = push_node; 
		*dst = push_node; 
	}
}

void	pa(t_stack **a, t_stack **b) 
{
	push(a, b); 
    write(1, "pa\n", 3);
}

void	pb(t_stack **b, t_stack **a) 
{
	push(b, a);
    write(1, "pb\n", 3);
}