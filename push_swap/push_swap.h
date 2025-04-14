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
void    inti_a(t_stack *a, t_stack *b);
//manage stacks
void    create_stack_a(t_stack **a, char **numbers);
void    append_node(t_stack **stack, int n);
t_stack *find_max(t_stack *stack);

//utils
void    display_error(void);
int stack_len(t_stack **stack);
t_stack *find_last(t_stack *stack);

//movs
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

#endif

