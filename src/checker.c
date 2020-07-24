#include "../push_swap.h"

//int 	*ft_valid(int ac, char **av)
//{
//
//}

int 	main(int ac, char **av)
{
	char *arr;
	t_stack *list;
	int i;

//	if (ac > 1)
//		ft_valid(ac, av);

	list = (t_stack *)malloc(sizeof(t_stack));
	i = 0;
	while (i < (ac - 1))
	{
		list->num = av[i][0];
		list = list->next;
		i++;
	}
//	while(get_next_line(0, &arr) > 0)
//	{
//		if (ft_strcmp(arr, "sa") == 0)
//			printf("Helloworld\n");
//	}
	ft_putchar('s');
	printf("Hello    world");
	return (0);
}