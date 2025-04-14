#include "push_swap.h"

void    display_error(void)
{
    write(2, "Error\n", 6);
    exit(1);
}

t_stack *find_last(t_stack *stack)
{
    if(!stack)
        return (NULL);
    while(stack->next)
        stack = stack->next;
    return (stack);
}


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

