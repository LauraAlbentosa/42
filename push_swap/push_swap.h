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
# include "Libft/libft.h"

typedef struct s_stack
{
    int num;
    struct s_stack *next;
}  t_stack;

t_stack *new_stack(int num);
void    stack_add_back(t_stack **stack, t_stack *new_node);
void    create_stack(t_stack **a, char **array_numbers);
int stack_len(t_stack **stack);
void    swap_a(t_stack **stack);
void    rotate_a(t_stack **stack);
void    push_a(t_stack **stack_a, t_stack **stack_b);
void    reverse_rotate(t_stack **stack);

#endif

