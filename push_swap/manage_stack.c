#include "push_swap.h"

void    append_node(t_stack **stack, int n)
{
    t_stack *new;
    t_stack *last;

    if (!stack)
        return;
    node = malloc(sizeof(t_stack));
    if (!node)
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
        las = find_last(*stack);
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
        if(error_syntax(numbers[i]))
            free_errors(a);
        n = ft_atoi(numbers[i]);
        if (n > INT_MAX || n < INT_MIN)
            free_errors(a);
        if(duplicates(*a, n))
            free_errors(a);
        append_node(a, n);
        i++;
    }
}
