#include "push_swap.h"

void    display_error(t_stack **stack)
{
    free_stacks(stack);
    write(2, "Error\n", 6);
    exit(1);
}
/*
void free_stacks(t_stack **stack)
{
    t_stack *temp;
    t_stack *current;
    if (!stack)
        return;
    current = *stack;
    while(current)
    {
        temp = current->next;
        current->num = 0;
        free(current);
        current = temp;
    }
    *stack = NULL;
}

*/

void free_stacks(t_stack **stack)
{
    t_stack *temp;
    t_stack *current;

    if (!stack || !*stack)
        return;

    current = *stack;
    while (current)
    {
        temp = current->next;
        free(current);
        current = temp;
    }
    *stack = NULL;
}


int	is_number(char *str)
{
    if (!str)  
        return (1);
    if (*str == '\0')  
        return (1);
    
    if (!(*str == '+' || *str == '-' || (*str >= '0' && *str <= '9'))) 
        return (1);
    if ((*str == '+' || *str == '-') && !(str[1] >= '0' && str[1] <= '9')) 
        return (1);
    
    while (*++str) 
    {
        if (!(*str >= '0' && *str <= '9')) 
            return (1);
    }
    
    return (0);
}

int duplicates(t_stack *stack, int n)
{
    if (!stack)
        return (0);
    while (stack)
    {
        if (stack->num == n)
            return (1);
        stack = stack->next;
    }
    return (0);
}

void	check_min(t_stack **a) 
{
	while ((*a)->num != find_min(*a)->num) 
	{
		if (find_min(*a)->medium) 
			ra(a);
		else
			rra(a);
	}
}