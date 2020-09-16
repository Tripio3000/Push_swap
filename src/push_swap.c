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
