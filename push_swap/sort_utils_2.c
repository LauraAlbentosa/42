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
	pa(a, b); 
}


void a_b(t_stack **a, t_stack **b)
{
    t_stack	*cheapest_node;

	cheapest_node = get_cheapest(*a); 
	if (cheapest_node->medium && cheapest_node->target_node->medium) 
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->medium) && !(cheapest_node->target_node->medium)) 
		rev_rotate_both(a, b, cheapest_node); 
	node_to_top(a, cheapest_node, 'a'); 
	node_to_top(b, cheapest_node->target_node, 'b');
	pb(b, a);
}


