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
    int    nbr;
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
