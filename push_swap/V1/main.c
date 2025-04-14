/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbento <lalbento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:43:39 by lalbento          #+#    #+#             */
/*   Updated: 2025/01/29 21:40:46 by lalbento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


intmain(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    char    **array_numbers;
    int len;

    a = NULL;
    b = NULL;
    if (argc == 1 || (argc == 2 && !argv[1][0]))
        return (1);
    else if (argc == 2)
        array_numbers = ft_split(argv[1], ' ');
    create_stack(&stack_a, array_numbers);
    len = stack_len(stack_a);
    if (!stack_sorted(stack_a))
    {
        if (len == 2)
            swap_a(&a);
        else if (len == 3)
            sort_three(&a);
        else
            sort_stacks(&stack_a, &stack_b);
    }
    free_stack(&stack_a);
    return(0);
}

/*
int main(int argc, char **argv)
{
    char    **array_numbers;
    t_stack *stack_a;

    stack_a = NULL;

    if (argc != 2)
        return(1);
    array_numbers = ft_split(argv[1], ' ');
    create_stack(&stack_a, array_numbers);

    t_stack *current = stack_a;

    while(current)
    {
        printf("%i\n", current->num);
        current = current->next;
    }

    printf("\n");
    reverse_rotate(&stack_a);

    current = stack_a;

    while(current)
    {
        printf("%i\n", current->num);
        current = current->next;
    }
    return(0);
}
*/