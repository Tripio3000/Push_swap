/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseabass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 17:46:08 by cseabass          #+#    #+#             */
/*   Updated: 2020/09/16 17:46:09 by cseabass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
