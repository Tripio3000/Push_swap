/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseabass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 17:45:41 by cseabass          #+#    #+#             */
/*   Updated: 2020/09/16 17:45:43 by cseabass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
** СОРТИРОВКА ТРЕХ ЭЛЕМЕНТОВ
*/

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

/*
** ЕСЛИ В СТЕКЕ 5 ЭЛЕМЕНТОВ
*/

void	five_elem(t_stack *a, t_stack *b)
{
	push(a, b);
	ft_putstr("pb\n");
	push(a, b);
	ft_putstr("pb\n");
	a->command += 2;
	three_elem(a);
}

/*
** СЛУЧАЙ С <= 3 ЭЛЕМЕНТАМИ
*/

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

/*
** ПРОВЕРКА НЕОБХОДИМОСТИ ПРИМЕНЕНИЯ КОМАНДЫ sa
*/

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
