/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseabass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 17:46:01 by cseabass          #+#    #+#             */
/*   Updated: 2020/09/16 17:46:03 by cseabass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

/*
** НАХОДИМ ЭЛЕМЕНТ С МИНИМАЛЬНЫМ ПРИОРИТЕТОМ
*/


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

/*
** ВРАЩАЕМ СТЕКА А В ЗАВИСИМОСТИ ОТ ПОЛОЖЕНИЯ НУЖНОГО
** ЭЛЕМЕНТА ОТНОСИТЕЛЬНО КОНЦОВ СТЕКА
*/

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

/*
** ПРОВЕРЯЕМ ОТСОРТИРОВАН ЛИ МАССИВ
*/

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
