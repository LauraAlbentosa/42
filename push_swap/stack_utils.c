#include "push_swap.h"

t_stack *find_last(t_stack *stack)
{
    if(!stack)
        return (NULL);
    while(stack->next)
        stack = stack->next;
    return (stack);
}

int stack_len(t_stack *stack)
{
    int i;

    if (!stack)
        return (0);
    i = 0;
    while(stack)
    {
        stack = stack->next;
        i++;
    }
    return(i);
}

void    node_to_top(t_stack **stack, t_stack *top, char stack_name)
{
    while (*stack != top)
    {
        if (stack_name == 'a')
        {
            if (top->medium)
                ra(stack);
            else
                rra(stack);
        }
        else if (stack_name == 'b')
        {
            if (top->medium)
                rb(stack);
            else
                rrb(stack);
        }
    }
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

t_stack *find_max(t_stack *stack)
{
    int max;
    t_stack *max_node;

    if (!stack)
        return (NULL);
    max = INT_MIN;
    while (stack)
    {
        if (stack->num > max)
        {
           max = stack->num;
           max_node = stack;
        }
        stack = stack->next;
    }
    return (max_node);

}