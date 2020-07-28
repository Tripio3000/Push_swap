#include "../push_swap.h"

void 	swapper(char *arr, t_stack *a, t_stack *b)
{
	if ((ft_strcmp(arr, "sa") == 0 || ft_strcmp(arr, "ss") == 0) &&
		a->head != NULL && a->head->next != NULL)
		swap(a);
	if ((ft_strcmp(arr, "sb") == 0 || ft_strcmp(arr, "ss") == 0) &&
		b->head != NULL && b->head->next != NULL)
		swap(b);

//	print_stack(a, 'a');
//	print_stack(b, 'b');
}

void 	rev_rotation(char *arr, t_stack *a, t_stack *b)
{
	if ((ft_strcmp(arr, "rra") == 0 || ft_strcmp(arr, "rrr") == 0) &&
		a->head != NULL && a->head->next != NULL)
		rev_rotate(a);
	if ((ft_strcmp(arr, "rrb") == 0 || ft_strcmp(arr, "rrr") == 0) &&
		b->head != NULL && b->head->next != NULL)
		rev_rotate(b);

//	print_stack(a, 'a');
//	print_stack(b, 'b');
}

void 	rotation(char *arr, t_stack *a, t_stack *b)
{
	if ((ft_strcmp(arr, "ra") == 0 || ft_strcmp(arr, "rr") == 0) &&
		a->head != NULL && a->head->next != NULL)
		rotate(a);
	if ((ft_strcmp(arr, "rb") == 0 || ft_strcmp(arr, "rr") == 0) &&
		b->head != NULL && b->head->next != NULL)
		rotate(b);

//	print_stack(a, 'a');
//	print_stack(b, 'b');
}

void	ascending_order(t_stack *a, int size)
{
	int i;
	t_data *p1;
	t_data *p2;

	if (a->size != size)
	{
		ft_putstr("KO\n");
		return ;
	}
	i = 0;
	p1 = a->head;
	p2 = p1->next;
	while (i < size && p2 != NULL)
	{
		if (p1->num < p2->num)
		{
			p1 = p2;
			p2 = p2->next;
			i++;
		}
		else
		{
			ft_putstr("KO\n");
			return ;
		}
	}
	ft_putstr("OK\n");
}

//		ЧТЕНИЕ СТАНДАРТНОГО ВВОДА
void 	std_input(t_stack *a, t_stack *b, int size)
{
	char *arr;

	while(get_next_line(0, &arr) > 0)
	{
		if (ft_strcmp(arr, "sa") == 0 ||
			ft_strcmp(arr, "sb") == 0 ||
			ft_strcmp(arr, "ss") == 0)
			swapper(arr, a, b);
		if (ft_strcmp(arr, "pb") == 0 && a->head != NULL)
		{
			push(a, b);
//			print_stack(a, 'a');
//			print_stack(b, 'b');
		}
		if (ft_strcmp(arr, "pa") == 0 && b->head != NULL)
		{
			push(b, a);
//			print_stack(a, 'a');
//			print_stack(b, 'b');
		}
		if (ft_strcmp(arr, "rra") == 0 ||
			ft_strcmp(arr, "rrb") == 0 ||
			ft_strcmp(arr, "rrr") == 0)
			rev_rotation(arr, a, b);
		if (ft_strcmp(arr, "ra") == 0 ||
			ft_strcmp(arr, "rb") == 0 ||
			ft_strcmp(arr, "rr") == 0)
			rotation(arr, a, b);
	}
	ascending_order(a, size);
}

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

//	if (ft_strcmp(av[0], "./a.out") == 0)
	std_input(a, b, size);
//	else
//		push_swap(a, b);
	return (0);
}