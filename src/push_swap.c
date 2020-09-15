/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseabass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 19:09:03 by cseabass          #+#    #+#             */
/*   Updated: 2020/09/15 19:09:05 by cseabass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		check_list(t_stack *a, int size)
{
	int		i;
	t_data	*p1;
	t_data	*p2;

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

void	null_prior(t_stack *a)
{
	t_data *p;

	p = a->head;
	while (p != NULL)
	{
		p->prior = 0;
		p = p->next;
	}
}

int		find_prior(t_data *start, t_stack *a)
{
	int		prior;
	int		num;
	t_data	*p;

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
	return (prior);
}

t_data	*max_sequence_greather(t_stack *a)
{
	t_data	*start;
	t_data	*tmp;
	int		max_prior;
	int		prior;

	start = a->head;
	null_prior(a);
	max_prior = 0;
	while (start != NULL)
	{
		prior = find_prior(start, a);
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

void	to_stack_b(t_stack *a, t_stack *b, int size)
{
	t_data	*p;
	int		i;
	int		j;

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
	{
		swap(a);
		a->command++;
		ft_putstr("sa\n");
	}
}

void	get_prior_greather(t_data *tmp, t_stack *a)
{
	int		prior;
	t_data	*p;
	int		num;

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
}

void	sort_a1(t_stack *a)
{
	rev_rotate(a);
	a->command++;
	ft_putstr("rra\n");
}

void	sort_a(t_stack *a)
{
	t_data	*p;
	int		i;

	p = a->head;
	i = 1;
	while (p->prior != 1)
	{
		p = p->next;
		i++;
	}
	while (a->head->prior != 1)
	{
		if ((i - 1) < (a->size - (i - 1)))
		{
			rotate(a);
			a->command++;
			ft_putstr("ra\n");
		}
		else
			sort_a1(a);
	}
}

/*
** НАХОДИМ МИНИМАЛЬНОЕ ЧИСЛО В СТЕКЕ
*/

t_data	*get_min(t_stack *src)
{
	t_data	*p;
	t_data	*tmp;
	int		i;

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

int		find_min_elem(t_stack *a)
{
	int		prior;
	t_data	*p1;
	t_data	*start;

	p1 = get_min(a);
	start = a->head;
	prior = 0;
	while (start != p1)
	{
		start = start->next;
		prior++;
	}
	return (prior);
}

void	prior_for_middle(t_stack *b, t_data *p2, t_data *p1, int prior)
{
	t_data *p3;

	p3 = b->head;
	while (p3 != NULL)
	{
		if (p1->num < p3->num && p2->num > p3->num)
			p3->prior = prior;
		p3 = p3->next;
	}
}

t_data	*begin_prior(t_stack *a, t_stack *b, t_data *p1, int prior)
{
	t_data *p2;
	t_data *p3;

	if (p1->next)
		p2 = p1->next;
	else
		p2 = a->head;
	p3 = b->head;
	while (p3 != NULL)
	{
		if (p3->num < p1->num)
			p3->prior = prior;
		p3 = p3->next;
	}
	return (p2);
}

void	end_prior(t_stack *b, t_data *p1, int prior)
{
	t_data *p3;

	p3 = b->head;
	while (p3 != NULL)
	{
		if (p3->num > p1->num)
			p3->prior = prior;
		p3 = p3->next;
	}
}

void	prior_b(t_stack *a, t_stack *b)
{
	t_data	*p1;
	t_data	*p2;
	t_data	*start;
	int		prior;

	prior = find_min_elem(a);
	p1 = get_min(a);
	start = p1;
	p2 = begin_prior(a, b, p1, prior);
	prior++;
	if (prior >= a->size)
		prior -= a->size;
	while (p2 != start)
	{
		prior_for_middle(b, p2, p1, prior);
		p1 = p2;
		p2 = p2->next;
		if (p2 == NULL)
			p2 = a->head;
		prior++;
		if (prior >= a->size)
			prior -= a->size;
	}
	end_prior(b, p1, prior);
}

int		min_prior(t_stack *b)
{
	t_data	*p;
	int		i;
	int		n;

	p = b->head;
	i = p->prior;
	n = 0;
	while (p != NULL)
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

void	compound_ab2(t_stack *a, t_stack *b, int i)
{
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
}

int		compound_ab1(t_stack *a, t_stack *b, int n, int i)
{
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
		while (n < b->size && b->size > 1)
		{
			rev_rotate(b);
			a->command++;
			ft_putstr("rrb\n");
			n++;
			i++;
		}
	}
	return (i);
}

void	compound_ab(t_stack *a, t_stack *b)
{
	int n;
	int i;

	n = min_prior(b);
	i = 0;
	i = compound_ab1(a, b, n, i);
	b->head->prior -= i;
	i = b->head->prior;
	compound_ab2(a, b, i);
	push(b, a);
	a->command++;
	ft_putstr("pa\n");
}

void	rotate_stack_a1(t_stack *a, int i)
{
	if ((i - 1) < (a->size - (i - 1)))
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

void	rotate_stack_a(t_stack *a)
{
	t_data	*p;
	t_data	*p1;
	int		i;

	i = 0;
	p = get_min(a);
	p1 = a->head;
	while (p1 != p)
	{
		i++;
		p1 = p1->next;
	}
	while (a->head != p)
		rotate_stack_a1(a, i);
}

void	incr_prior(t_stack *b)
{
	int		i;
	t_data	*p;

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

void	three_elem1(t_stack *a, t_data *p1, t_data *p2, t_data *p3)
{
	if (p1->num < p2->num && p2->num > p3->num && p3->num > p1->num)
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

void	three_elem(t_stack *a)
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
	else
		three_elem1(a, p1, p2, p3);
}

void	five_elem(t_stack *a, t_stack *b)
{
	push(a, b);
	ft_putstr("pb\n");
	push(a, b);
	ft_putstr("pb\n");
	a->command += 2;
	three_elem(a);
}

void	conditions(t_stack *a, t_stack *b, int size)
{
	if (size < 2)
	{
		ft_freee(a, b);
		exit(0);
	}
	if (size == 3)
		three_elem(a);
	else
		check_swap(a);
}

void	help_func1(t_stack *a, t_stack *b, int size)
{
	t_data *tmp;

	tmp = max_sequence_greather(a);
	get_prior_greather(tmp, a);
	to_stack_b(a, b, size);
	sort_a(a);
}

void	help_func2(t_stack *a, t_stack *b)
{
	while (b->size > 0)
	{
		prior_b(a, b);
		incr_prior(b);
		compound_ab(a, b);
	}
	rotate_stack_a(a);
	ft_freee(a, b);
}

int		main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		size;

	if (ac < 2)
		exit(0);
	a = (t_stack *)malloc(sizeof(t_stack));
	b = (t_stack *)malloc(sizeof(t_stack));
	ft_init(a, b);
	create_stack(a, ac, av);
	size = a->size;
	if (size <= 3)
		conditions(a, b, size);
	if (check_list(a, size))
	{
		ft_freee(a, b);
		return (0);
	}
	if (size == 5)
		five_elem(a, b);
	else
		help_func1(a, b, size);
	help_func2(a, b);
	return (0);
}
