#include "push_swap.h"
/*
void    a_b(t_stack **a, t_stack **b)
{
    t_stack *cheapest_node;

    cheapest_node = get_cheapest(*a);
    if (cheapest_node->medium && cheapest_node->target_node->medium)
        rr(a, b);
    else if (!(cheapest_node->medium) && !(cheapest_node->target_node->medium))
        rrr(a, b);
    node_to_top(a, cheapest_node, 'a');
    node_to_top(b, cheapest_node, 'b');
    push_b(b, a);
}
*/
void b_a(t_stack **a, t_stack **b) 
{
	node_to_top(a, (*b)->target_node, 'a'); 
	push_a(a, b); 
}


void a_b(t_stack **a, t_stack **b)
{
    t_stack *cheapest_node;

    cheapest_node = get_cheapest(*a);
    while (*a != cheapest_node && *b != cheapest_node->target_node)
    {
        if (cheapest_node->medium && cheapest_node->target_node->medium)
            rr(a, b);
        else if (!cheapest_node->medium && !cheapest_node->target_node->medium)
            rrr(a, b);
        else
            break;
    }
    node_to_top(a, cheapest_node, 'a');
    node_to_top(b, cheapest_node->target_node, 'b');
    push_b(b, a);
}


