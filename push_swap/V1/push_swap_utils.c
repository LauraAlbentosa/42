/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbento <lalbento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:46:17 by lalbento          #+#    #+#             */
/*   Updated: 2025/01/29 20:24:15 by lalbento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

#include <stdlib.h> // For malloc and NULL

int stack_len(t_stack **stack)
{
    int i;
    t_stack *current;

    i = 0;
    current = *stack;
    while(current)
    {
        current = current->next;
        i++;
    }
    return(i);
}

t_stack *find_min(t_stack *stack)
{
    long    min;
    t_stack *min_node;
    
    if(!stack)
        return(NULL);
    min = LONG_MAX;
    while (stack)
    {
        if (stack->num < min)
        {
            min = stack->num;
            min_node = stack;  
        }
        stack = stack->next;
    }
    return(min_node);
}

bool    stack_sorted(t_stack *stack)
{
    if (!stack)
        return(1);
    while (stack->node)
    {
        if (stack->num > stack->next->num)
            return(0);
        stack = stack->next;
        
    }
    return(1);
}

t_stack *new_stack(int num)
{
    t_stack *new_node;

    new_node = (t_stack *)malloc(sizeof(t_stack));
    if (!new_node)
        return (NULL);
    new_node->num = num;
    new_node->next = NULL;
    return (new_node);
}

void stack_add_back(t_stack **stack, t_stack *new_node)
{
    t_stack *current;

    if (!*stack)
    {
        *stack = new_node;
        return;
    }
    current = *stack;
    while (current->next)
        current = current->next;
    current->next = new_node;
}

void   create_stack(t_stack **a, char **array_numbers)
{
    long    nbr;
    t_stack  *new_node;
    int i;

    i = 0;
    while (array_numbers[i])
    {
        nbr = ft_atoi(array_numbers[i]);
        new_node = new_stack(nbr);
        if(!new_node)   
            return;
        stack_add_back(a, new_node);
        i++;
    }
}
void    init_nodes_a(t_stack *stack_a, t_stack *stack_b)
{
    current_index(stack_a);
    current_index(stack_b);
    set_target_a(stack_a, stack_b);
    cost(stack_a, stack_b);
    cheapest(stack_a);
}