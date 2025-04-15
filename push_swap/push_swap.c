# include "push_swap.h"

int    sorted(t_stack *stack)
{
    if (!stack)
        return(1);
    while (stack->next)
    {
        if (stack->num > stack->next->num)
            return(0);
        stack = stack->next;
        
    }
    return(1);
}

void    sort_three(t_stack **a)
{
    t_stack *max;

    max = find_max(*a);
    if(max == *a)
        ra(a);
    else if ((*a)->next == max)
        rra(a);
    if((*a)->num > (*a)->next->num)
        sa(a);
}

void    sort_stacks(t_stack **a, t_stack **b)
{
    int len_a;

    len_a = stack_len(*a);
    if (len_a - 1 > 3 && !sorted(*a))
        pb(b, a);
    if (len_a - 1 > 3 && !sorted(*a))
        pb(b, a);
    while(len_a - 1 > 3 && !sorted(*a))
    {
        init_a(*a, *b);
        a_b(a,b);
    }
    sort_three(a);
    while(*b)
    {
        init_b(*a,*b);
        b_a(a,b);
    }
    current_index(*a);
    check_min(a);
}