# include "../push_swap.h"

void 	push_swap(t_stack *a, t_stack *b)
{
	printf("hahaha\n");
}

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

t_data 	*max_sequence(t_stack *a)
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
	return (tmp);
}

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
			ft_putstr("ra\n");
			if (check_list(a, size))
				return ;
		}
		else if (p->prior == 0)
		{
			push(a, b);
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
	{
		swap(a);
		ft_putstr("sa\n");
	}
}

t_data	*get_prior(t_data *tmp, t_stack *a)
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
				p->prior = ++prior;
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
			ft_putstr("ra\n");
		}
		else
		{
			rev_rotate(a);
			ft_putstr("rra\n");
		}
	}
}

t_data	*get_min(t_stack *src)
{
	t_data *p;
	t_data *tmp;
	int i;

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
	int prior;


	p1 = get_min(a);
	if (p1->next)
		p2 = p1->next;
	else
		p2 = a->head;
//	p2 = p1->next;
	p3 = b->head;
//	p3 = get_min(b);
	prior = 0;
	while (p3 != NULL)
	{
		if (p3->num < p1->num)
			p3->prior = prior;
		p3 = p3->next;
	}
	prior++;
	while (p2 != NULL || p2 != p1)
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
		prior++;
	}
	p3 = b->head;
	while (p3 != NULL)
	{
		if (p1->num < p3->num)
			p3->prior = prior;
		p3 = p3->next;
	}
}

void 	compound_ab(t_stack *a, t_stack *b)
{
	int i;

	i = b->head->prior;
	while (i > 0)
	{
		rotate(a);
		ft_putstr("ra\n");
		i--;
	}
	push(b, a);
	ft_putstr("pb\n");
}

int 	main(int ac, char **av)
{
	t_stack *a;
	t_stack *b;
	t_data *tmp;
	int size;

	a = (t_stack *)malloc(sizeof(t_stack));
	b = (t_stack *)malloc(sizeof(t_stack));
	init(a, b);
	create_stack(a, ac, av);
	size = a->size;

	print_stack(a, 'a');
	print_stack(b, 'b');

	check_swap(a);
	if(check_list(a, size))
		return (0);
	tmp = max_sequence(a);
	tmp = get_prior(tmp, a);
	to_stack_b(tmp, a, b, size);
	sort_a(a);
	while(b->size > 0)
	{
		prior_b(a, b);
		compound_ab(a, b);
	}


	print_stack(a, 'a');
	print_stack(b, 'b');
	printf("hahaha\n");
	return (0);
}