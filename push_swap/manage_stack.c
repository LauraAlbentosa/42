#include "push_swap.h"

void    append_node(t_stack **stack, int n)
{
    t_stack *new;
    t_stack *last;

    if (!stack)
        return;
    new = malloc(sizeof(t_stack));
    if (!new)
        return;
    new->next = NULL;
    new->num = n;
    if(!(*stack))
    {
        *stack = new;
        new->prev = NULL;
    }
    else
    {
        last = find_last(*stack);
        last->next = new;
        new->prev = last;
    }
}

void    create_stack_a(t_stack **a, char **numbers)
{
    int n;
    int i;

    i = 0;
    while(numbers[i])
    {
        if(is_number(numbers[i]))
            display_error(a);
        n = ft_atoi(numbers[i]);
        if (n > INT_MAX || n < INT_MIN)
            display_error(a);
        if(duplicates(*a, n))
            display_error(a);
        append_node(a, n);
        i++;
    }
}
