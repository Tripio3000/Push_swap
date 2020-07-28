# include "../push_swap.h"

void 	push_swap(t_stack *a, t_stack *b)
{
	printf("hahaha\n");
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

//void 	to_stack_b(t_data *tmp, t_stack *a, t_stack *b)
//{
//
//}

void 	get_prior(t_data *tmp, t_stack *a)
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
	printf("a\n");
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

	tmp = max_sequence(a);
	get_prior(tmp, a);

	print_stack(a, 'a');
	print_stack(b, 'b');
	printf("hahaha\n");
	return (0);
}