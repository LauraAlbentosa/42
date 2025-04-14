#include "push_swap.h"

void    current_index(t_stack *stack)
{
    int i;
    int mid;

    i = 0;
    if (!stack)
        return;
    mid = stack_len(stack) / 2;
    while (stack)
    {
        stack->index = i;
        if (i <= mid)
            stack->medium = 1;
        else
            stack->medium = 0;
        stack = stack->next;
        i++;
    }

}

void set_target_a(t_stack *a, t_stack *b)
{
    t_stack *current_b;
    t_stack *target;
    int match;

    while(a)
    {
        match = INT_MIN;
        current_b = b;
        while(current_b)
        {
            if (current_b->num < a->num && current_b->num > match)
            {
                match = current_b->num;
                target = current_b;
            }
            current_b = current_b->next;
        }
        if (match == INT_MIN)
            a->target_node = find_max(b);
        else
            a->target_node = target;
        a = a->next;
    }
}

void    set_target_b(t_stack *a, t_stack *b)
{
    t_stack *current_a;
    t_stack *target;
    int match;

    while(b)
    {
        match = INT_MAX;
        current_a = a;
        while (current_a)
        {
            if (current_a->num > b->num && current_a->num < match)
            {
                match = current_a->num;
                target = current_a;
            }
            current_a = current_a->next;
        }
        if (match == INT_MAX)
            b->target_node = find_min(a);
        else
            b->target_node = target;
        b = b->next; 
    }
}

void cost(t_stack *a, t_stack *b)
{
    int len_a;
    int len_b;

    len_a = stack_len(a);
    len_b = stack_len(b);
    while (a)
    {
        a->cost = a->index;
        if (!(a->medium))
            a->cost = len_a - (a->index);
        if (a->target_node->medium)
            a->cost += a->target_node->index;
        else
            a->cost += len_b - (a->target_node->index);
        a = a->next;
    }
}
/*
void    cheapest(t_stack *stack)
{
    int cheapest_value;
    t_stack *cheap_node;

    if (!stack)
        return;
    cheapest_value = INT_MAX;
    while(stack)
    {
        if (stack->cost < cheapest_value)
        {
            cheapest_value = stack->cost;
            cheap_node = stack;
        }
        stack = stack->next;
    }
    cheap_node->cheapest = 1;
}

*/

void cheapest(t_stack *stack)
{
    int cheapest_value;
    t_stack *cheap_node;
    //t_stack *head = stack;

    if (!stack)
        return;

    cheapest_value = INT_MAX;
    while (stack)
    {
        stack->cheapest = 0;  // <- Limpia antes
        if (stack->cost < cheapest_value)
        {
            cheapest_value = stack->cost;
            cheap_node = stack;
        }
        stack = stack->next;
    }
    if (cheap_node)
        cheap_node->cheapest = 1;
}


t_stack *get_cheapest(t_stack *stack)
{
    if (!stack)
        return (NULL);
    while(stack)
    {
        if (stack->cheapest)
            return (stack);
        stack = stack->next;
    }
    return (NULL);
}


