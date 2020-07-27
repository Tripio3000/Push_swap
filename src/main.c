#include "../push_swap.h"

int 	main(int ac, char **av)
{
	char *arr;
	t_stack *a;
	t_stack *b;
	int size;

	a = (t_stack *)malloc(sizeof(t_stack));
	b = (t_stack *)malloc(sizeof(t_stack));
	init(a, b);
	create_stack(a, ac, av);
	size = a->size;

//	print_stack(a, 'a');
//	print_stack(b, 'b');

	if (ft_strcmp(av[0], "./a.out") == 0)
		std_input(a, b, size);
	else
		push_swap(a, b);
	return (0);
}