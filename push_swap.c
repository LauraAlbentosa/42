

# include "push_swap.h"

int main(int argc, char **argv)
{
    char **array_numbers;
    t_stack *stack_a;

    if (argc != 2)
        return (1);

    stack_a = NULL;
    array_numbers = ft_split(argv[1], ' ');
    if (!array_numbers)
        return(1);
    create_list(&stack_a, array_numbers);
    return(0);
}

