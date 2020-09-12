# include "../push_swap.h"

//void 	push_swap(t_stack *a, t_stack *b)
//{
//	printf("hahaha\n");
//}

int 	check_list(t_stack *a, int size)
{
	int i;
	t_data *p1;
	t_data *p2;

	if (a->size != size)
		return (0);
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
			return (0);
	}
	return (1);
}

void 	null_prior(t_stack *a)
{
	t_data *p;

	p = a->head;
	while (p != NULL)
	{
		p->prior = 0;
		p = p->next;
	}
}

t_data 	*max_sequence_greather(t_stack *a)
{
	t_data *start;
	t_data *p;
	t_data *tmp;
	int max_prior;
	int prior;
	int num;

	start = a->head;
	null_prior(a);

	max_prior = 0;
	while (start != NULL)
	{
		prior = 1;
		p = start;
		p->prior = prior;
		num = start->num;
		p = p->next;
		while (p != start)
		{
			if (p == NULL)
				p = a->head;
			else
			{
				if (num < p->num)
				{
					num = p->num;
					p->prior = ++prior;
				}
				p = p->next;
			}

		}
		if (max_prior < prior)
		{
			max_prior = prior;
			tmp = start;
		}
		null_prior(a);
		start = start->next;
	}
//	a->trig = max_prior;
	return (tmp);
}

//t_data	*max_sequence_index(t_stack *a, t_data *prev)
//{
//	int max_prior;
//	int i;
//	int prior;
//	t_data *p1;
//	t_data *start;
//	t_data *tmp;
//
//	start = a->head;
//	max_prior = 0;
//	while (start != NULL)
//	{
//		i = start->num;
//		p1 = start->next;
//		prior = 0;
//		while (p1 != start)
//		{
//			if (p1 == NULL)
//				p1 = a->head;
//			if (p1->num - 1 == i)
//			{
//				prior++;
//				i = p1->num;
//			}
//			if (p1->next == NULL)
//				p1 = a->head;
//			else
//				p1 = p1->next;
//		}
//		if (max_prior < prior)
//		{
//			max_prior = prior;
//			tmp = start;
//		}
//		start = start->next;
//	}
//	printf("greather: %d, index: %d\n", a->trig, max_prior);
//	if (a->trig > max_prior)
//	{
//		a->trig = 0;
//		return (prev);
//	}
//	else
//	{
//		a->trig = 1;
//		return (tmp);
//	}
//}

void 	to_stack_b(t_data *tmp, t_stack *a, t_stack *b, int size)
{
	t_data *p;
	int i;
	int j;

	i = 0;
	j = a->size;
	while (i < j)
	{
		p = a->head;
		if (p->prior != 0)
		{
			rotate(a);
			a->command++;
			ft_putstr("ra\n");
			if (check_list(a, size))
				return ;
		}
		else if (p->prior == 0)
		{
			push(a, b);
			a->command++;
			ft_putstr("pb\n");
		}
		i++;
	}
}

void	check_swap(t_stack *a)
{
	t_data *p;

	p = a->head;
	p = p->next;
	if (a->head->num > p->num)
//		return (1);
//	else
//		return (0);
	{
		swap(a);
		a->command++;
		ft_putstr("sa\n");
	}
}

t_data	*get_prior_greather(t_data *tmp, t_stack *a)
{
	int prior;
	t_data *p;
	int num;

	prior = 1;
	p = tmp;
	p->prior = prior;
	num = tmp->num;
	p = p->next;
	while (p != tmp)
	{
		if (p == NULL)
			p = a->head;
		else
		{
			if (num < p->num)
			{
				num = p->num;
				p->prior = prior;
			}
			p = p->next;
		}
	}
	return (p);
}

void 	sort_a(t_stack *a)
{
	t_data *p;
	int i;

	p = a->head;
	i = 1;
	while (p->prior != 1)
	{
		p = p->next;
		i++;
	}
	while (a->head->prior != 1)
	{
		if ((i - 1) < (a->size  - (i - 1)))
		{
			rotate(a);
			a->command++;
			ft_putstr("ra\n");
		}
		else
		{
			rev_rotate(a);
			a->command++;
			ft_putstr("rra\n");
		}
	}
}

t_data	*get_min(t_stack *src) //находим минимальное число в стеке
{
	t_data *p;
	t_data *tmp;
	int i;

	i = INT_MAX;
	p = src->head;
	while (p != NULL)
	{
		if (p->num < i)
		{
			i = p->num;
			tmp = p;
		}
		p = p->next;
	}
	return (tmp);
}

void 	prior_b(t_stack *a, t_stack *b)
{
	t_data *p1;
	t_data *p2;
	t_data *p3;
	t_data *start;
	int prior;
//	int shift;

	p1 = get_min(a);
	start = a->head;
	prior = 0;
	while (start != p1)
	{
		start = start->next;
		prior++;
	}
	start = p1;
	if (p1->next)
		p2 = p1->next;
	else
		p2 = a->head;
//	p2 = p1->next;
	p3 = b->head;
//	prior = shift;
	while (p3 != NULL)
	{
		if (p3->num < p1->num)
			p3->prior = prior;
		p3 = p3->next;
	}
	prior++;
	if (prior >= a->size)
		prior -= a->size;
	while (p2 != start)
	{
		p3 = b->head;
		while (p3 != NULL)
		{
			if (p1->num < p3->num && p2->num > p3->num)
				p3->prior = prior;
			p3 = p3->next;
		}
		p1 = p2;
		p2 = p2->next;
		if (p2 == NULL)
			p2 = a->head;
		prior++;
		if (prior >= a->size)
			prior -= a->size;
	}
	p3 = b->head;
	while (p3 != NULL)
	{
		if (p3->num > p1->num)
			p3->prior = prior;
		p3 = p3->next;
	}
}

int 	min_prior(t_stack *b)
{
	t_data *p;
	int i;
	int n;

	p = b->head;
	i = p->prior;
	n = 0;
	while(p != NULL)
	{
		if (i > p->prior)
			i = p->prior;
		p = p->next;
	}
	p = b->head;
	while (i != p->prior)
	{
		n++;
		p = p->next;
	}
	return (n);
}

void 	compound_ab(t_stack *a, t_stack *b)
{
	int n;
	int i;

	n = min_prior(b);
	i = 0;
	if (n <= (b->size / 2) && b->size > 1)
	{
		while (n > 0)
		{
			rotate(b);
			a->command++;
			ft_putstr("rb\n");
			n--;
			i++;
		}
	}
	else
	{
//		i = b->size - n;
		while (n < b->size && b->size > 1)
		{
			rev_rotate(b);
			a->command++;
			ft_putstr("rrb\n");
			n++;
			i++;
		}
	}
	b->head->prior -= i;
	i = b->head->prior;
	if (i < a->size / 2)
	{
		while (i > 0)
		{
			rotate(a);
			a->command++;
			ft_putstr("ra\n");
			i--;
		}
	}
	else
	{
		i = a->size - b->head->prior;
		i = a->size - i;
		while (i < a->size)
		{
			rev_rotate(a);
			a->command++;
			ft_putstr("rra\n");
			i++;
		}
	}
	push(b, a);
	a->command++;
	ft_putstr("pa\n");
}

void 	rotate_stack_a(t_stack *a)
{
	t_data *p;
	t_data *p1;
	int i;

	i = 0;
	p = get_min(a);
	p1 = a->head;
	while (p1 != p)
	{
		i++;
		p1 = p1->next;
	}
	while (a->head != p)
	{
		if ((i - 1) < (a->size  - (i - 1)))
		{
			rotate(a);
			a->command++;
			ft_putstr("ra\n");
		}
		else
		{
			rev_rotate(a);
			a->command++;
			ft_putstr("rra\n");
		}
	}
}

void	incr_prior(t_stack *b)
{
	int i;
	t_data *p;

	i = 0;
	p = b->head;
	while (p != NULL && i <= (b->size / 2))
	{
		p->prior += i;
		p = p->next;
		i++;
	}
	i--;
	if (b->size % 2 == 0)
		i--;
	while (p != NULL)
	{
		p->prior += i;
		p = p->next;
		i--;
	}
}

void	simple_form(t_stack *a)
{
	int  *arr;
	t_data *p;
	int i;
	int j;

	arr = ft_memalloc(a->size + 1);
	p = a->head;
	i = 0;
	while (p != NULL)
	{
		arr[i] = p->num;
		p = p->next;
		i++;
	}

//	i = 0;
//	while (arr[i] != '\0')
//	{
//		printf("%d ", arr[i]);
//		i++;
//	}
//	printf("\n\n");

	i = 0;
	while (arr[i + 1] != '\0')
	{
		if (arr[i] > arr[i + 1])
		{
			j = arr[i + 1];
			arr[i + 1] = arr[i];
			arr[i] = j;
			i = 0;
			continue ;
		}
		i++;
	}

//	i = 0;
//	while (arr[i] != '\0')
//	{
//		printf("%d ", arr[i]);
//		i++;
//	}
//	printf("\n\n");

	i = 0;
	j = 0;
	while (arr[i] != '\0')
	{
		p = a->head;
		while (p != NULL)
		{
			if (arr[i] == p->num)
			{
				p->num = j;
				j++;
				break ;
			}
			p = p->next;
		}
		i++;
	}
	p = a->head;

	printf("a: ");
	while (p != NULL)
	{
		printf("%d ", p->num);
		p = p->next;
	}
	printf("\n\n");
}

int 	exit_cycle(t_stack *a)
{
	t_data *p;

	p = a->head;
	while (p != NULL)
	{
		if (p->prior == 0)
			return (0);
		p = p->next;
	}
	return (1);
}

void 	three_elem(t_stack *a)
{
	t_data *p1;
	t_data *p2;
	t_data *p3;

	p1 = a->head;
	p2 = p1->next;
	p3 = a->end;
	if (p1->num > p2->num && p2->num > p3->num && p3->num < p1->num)
	{
		swap(a);
		ft_putstr("sa\n");
		rev_rotate(a);
		ft_putstr("rra\n");
		a->command += 2;
	}
	else if (p1->num > p2->num && p2->num < p3->num && p3->num < p1->num)
	{
		rotate(a);
		ft_putstr("ra\n");
		a->command++;
	}
	else if (p1->num < p2->num && p2->num > p3->num && p3->num > p1->num)
	{
		swap(a);
		ft_putstr("sa\n");
		rotate(a);
		ft_putstr("ra\n");
		a->command += 2;
	}
	else if (p1->num < p2->num && p2->num > p3->num && p3->num < p1->num)
	{
		rev_rotate(a);
		ft_putstr("rra\n");
		a->command++;
	}
	else if (p1->num > p2->num && p2->num < p3->num && p3->num > p1->num)
	{
		swap(a);
		ft_putstr("sa\n");
		a->command++;
	}
}

void 	five_elem(t_stack *a, t_stack *b)
{
	push(a, b);
	ft_putstr("pb\n");
	push(a, b);
	ft_putstr("pb\n");
	a->command += 2;
	three_elem(a);
}

int 	main(int ac, char **av)
{
	t_stack *a;
	t_stack *b;
	t_data *tmp;
	t_data *p;
	int size;
	int i;

	if (ac < 2)
		exit(0);
	a = (t_stack *)malloc(sizeof(t_stack));
	b = (t_stack *)malloc(sizeof(t_stack));
	ft_init(a, b);
	create_stack(a, ac, av);
	size = a->size;
	if (size < 2)
	{
		ft_freee(a, b);
		return (0);
	}

//	print_stack(a, 'a');
//	print_stack(b, 'b');

	if (size == 3)
		three_elem(a);
	else
		check_swap(a);
	if(check_list(a, size))
	{
		ft_freee(a, b);
		return (0);
	}


//	simple_form(a);

	if (size == 5)
		five_elem(a, b);
	else
	{
		tmp = max_sequence_greather(a);
		tmp = get_prior_greather(tmp, a);
		to_stack_b(tmp, a, b, size);
		sort_a(a);
	}


//	print_stack(a, 'a');
//	print_stack(b, 'b');

	while(b->size > 0)
	{
		prior_b(a, b);
		incr_prior(b);
		compound_ab(a, b);
//		print_stack(a, 'a');
//		print_stack(b, 'b');
	}
	rotate_stack_a(a);

//	print_stack(a, 'a');
//	print_stack(b, 'b');
//	printf("\n%d\n", a->command);
//	int k = check_list(a, size);
//	if (k == 1)
//		printf("OK\n");


	ft_freee(a, b);
	return (0);
}

// сега с одним аргументом  в пуш свапе 

// 159, -115, -47, -52, 11, 158, -141, 131, 92, 17, 49, -99