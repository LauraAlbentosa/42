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
/*
void    swap_a(t_stack **stack)
{
    t_stack *first;
    t_stack *second;
    int len;
    
    len = stack_len(*stack);
    if (len < 2)
        return;
        
    first = *stack;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *stack = second;
    write(1, "sa\n", 3);
}

void    swap_b(t_stack **stack)
{
    t_stack *first;
    t_stack *second;
    int len;
    
    len = stack_len(*stack);
    if (len < 2)
        return;
        
    first = *stack;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *stack = second;
    write(1, "sb\n", 3);
}


void swap_a(t_stack **stack)
{
    t_stack *first;
    t_stack *second;
    int len;

    len = stack_len(*stack);
    if (len < 2)
        return;

    first = *stack;
    second = first->next;
    first->next = second->next;
    if (second->next)
        second->next->prev = first;  // Actualiza el prev del siguiente nodo
    second->next = first;
    first->prev = second;  // Establece el puntero prev del primer nodo
    *stack = second;
    write(1, "sa\n", 3);
}
void swap_b(t_stack **stack)
{
    t_stack *first;
    t_stack *second;
    int len;

    len = stack_len(*stack);
    if (len < 2)
        return;

    first = *stack;
    second = first->next;
    first->next = second->next;
    if (second->next)
        second->next->prev = first;
    second->next = first;
    first->prev = second;
    *stack = second;
    write(1, "sb\n", 3);
}
*/


static void	swap(t_stack **head) 
{
	if (!*head || !(*head)->next) 
		return ;
	*head = (*head)->next; 
	(*head)->prev->prev = *head; 
	(*head)->prev->next = (*head)->next; 
	if ((*head)->next) 
		(*head)->next->prev = (*head)->prev; 
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL; 
}

void	sa(t_stack	**a) 
{
	swap(a);
    write(1, "sa\n", 3);

}

void	sb(t_stack **b) 
{
	swap(b);
    write(1, "sb\n", 3);

}

void	ss(t_stack **a, t_stack **b) 
{
	swap(a);
	swap(b);
    write(1, "ss\n", 3);

}