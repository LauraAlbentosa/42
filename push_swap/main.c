# include "push_swap.h"


int main(int argc, char** argv)
{
    t_stack *a;
    t_stack *b;
    //char    **numbers;

    a = NULL;
    b = NULL;
    if (argc == 1 || (argc == 2 && !argv[1][0]))
        return (1);
    else if (argc == 2)
        argv = ft_split(argv[1], ' ');
    /*else 
        numbers = &argv[1];
    */
    create_stack_a(&a, argv + 1);
    if (!sorted(a))
    {
        if (stack_len(a) == 2)
            sa(&a);
        else if (stack_len(a) == 3)
            sort_three(&a);
        else
            sort_stacks(&a, &b);
    }
    free_stacks(&a);
    return (0);
}

