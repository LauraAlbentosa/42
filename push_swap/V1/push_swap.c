/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lam_16 <lam_16@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:43:39 by lalbento          #+#    #+#             */
/*   Updated: 2025/04/02 18:07:57 by lam_16           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sotr_three(t_Stack **stack_a)
{
    t_stack *biggest;

    biggest = find_max(*stack_a);
    if ( biggest_node == *stack_a)
        rotate_a(stack_a);
    else if ((*stack_a)->next == biggest_node)
        reverse_rotate(stack_a);
    if ((*stack_a)->num > (*stack_a)->next->num)
        swap_a(stack_a);
}
void    current_index(t_stack *stack)
{
    int i;
    int mid;

    i = 0;
    if (!stack)
        return;
    mid = stack_len(stack)/2;
    while(stack)
    {
        stack->index = i;
        if (i <= mid)
            stack->medium = 1;
        else
            stack->medium = 0;
        stack = stack->next;
        ++i;
    }
}

static void set_target_a(t_stack *stack_a, t_stack *stack_b)
{
    t_stack *current_b;
    t_stack *target;
    long    best_targ;

    while(stack_a)
    {
        best_targ = LONG_MIN;
        current_b = stack_b;
        while(current_b)
        {
            if ( current_b->num < stack_a->num && current_b->num > best_targ)
            {
                best_targ = current_b->num;
                target = current;
            }
            current_b = current_b->next;
        }
        if (best_targ == LONG_MIN)
            stack_a->target = find_max(stack_b);
        else
            stack_a->target = target:
        stack_a = stack_a->next;
    }
}

static void cost(t_stack *stack_a, t_stack *stack_b)
{
    int len_a;
    int len_b;

    len_a = stack_len(stack_a);
    len_b = stack_len(stack_b);

    while(stack_a)
    {
        stack_a->cost = stack_a->index;
        if (!(stack_a->medium))
            stack_a->cost = lena_a - (stack_a->index);
        if (stack_a->target_node->medium)
            stack_a->cost += stack_a->target_node->index;
        else
            stack_a->cost + = len_b - (stack_a->target_node->index);
        stack_a = stack_a->next;5
    }
}

void    sort_stacks(t_stack **stack_a, t_stack **stack_b)
{
    int     len_a;

    len_a = stack_len(*stack_a);
    if ((len_a - 1) > 3 && !stack_sorted(*stack_a))
        push_b(stack_b, stack_a);
    while ((len_a - 1) > 3 && !stack_sorted(*stack_a))
    {
        init_nodes_a(*stack_a, *stack_b);
        move_a_to_b(stack_a, stack_b);
    }
    sort_three(stack_a);
    while(stack_b)
    {
        init_nodes_b(*stack_a, *stack_b);
        move_b_to_a(stack_a,stack_b);
    }

    current_index(*stack_a);
    min_on_top(stack_a);
}