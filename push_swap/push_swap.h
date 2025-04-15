/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbento <lalbento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:44:02 by lalbento          #+#    #+#             */
/*   Updated: 2025/01/29 21:40:28 by lalbento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "../Libft/libft.h"

typedef struct s_stack
{
    int num;
    int index;
    int cost;
    int    medium;
    int    cheapest;
    struct  s_stack *target_node;
    struct  s_stack *next;
    struct  s_stack *prev;
}  t_stack;

//sort
void    sort_three(t_stack **a);
int    sorted(t_stack *stack);
void    sort_stacks(t_stack **a, t_stack **b);

//sort utils
void    cheapest(t_stack *stack);
void    current_index(t_stack *stack);
void    init_a(t_stack *a, t_stack *b);
void    init_b(t_stack *a, t_stack *b);
void    set_target_b(t_stack *a, t_stack *b);
void set_target_a(t_stack *a, t_stack *b);
void    a_b(t_stack **a, t_stack **b);
void b_a(t_stack **a, t_stack **b) ;
void cost(t_stack *a, t_stack *b);
t_stack *get_cheapest(t_stack *stack);




//manage stacks
void    create_stack_a(t_stack **a, char **numbers);
void    append_node(t_stack **stack, int n);


//stack utils
int stack_len(t_stack *stack);
void    node_to_top(t_stack **stack, t_stack *top, char stack_name);
t_stack *find_last(t_stack *stack);
t_stack *find_max(t_stack *stack);
t_stack *find_min(t_stack *stack);
void	check_min(t_stack **a);


//utils
void    display_error(t_stack **stack);
int duplicates(t_stack *stack, int n);
int is_number(char  *str);
void free_stacks(t_stack **stack);
void    display_error(t_stack **stack);


/*movs
void    push_a(t_stack **stack_a, t_stack **stack_b);
void    push_b(t_stack **stack_a, t_stack **stack_b);
void    reverse_rotate(t_stack **stack);
void    rra(t_stack **a);
void    rrb(t_stack **b);
void    rrr(t_stack **a, t_stack **b);
void    rotate(t_stack **stack);
void    ra(t_stack **a);
void    rb(t_stack **b);
void    rr(t_stack **a, t_stack **b);
void    swap_a(t_stack **stack);
void    swap_b(t_stack **stack);
*/

void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);
void    rra(t_stack **a);
void    rrb(t_stack **b);
void    rrr(t_stack **a, t_stack **b);
void    ra(t_stack **a);
void    rb(t_stack **b);
void    rr(t_stack **a, t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	sb(t_stack **b);
void	sa(t_stack	**a);
void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
#endif

