#include "push_swap.h"

void    init_a(t_stack *a, t_stack *b)
{
    current_index(a);
    current_index(b);
    set_target_a(a, b);
    cost(a, b);
    cheapest(a);
}

void    init_b(t_stack *a, t_stack *b)
{
    current_index(a);
    current_index(b);
    set_target_b(a, b);
}