/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseabass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 17:45:55 by cseabass          #+#    #+#             */
/*   Updated: 2020/09/16 17:45:56 by cseabass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
** ВЫСЧИТЫВАЕМ ПРИОРИТЕТЫ ДЛЯ КАЖДОГО ЭЛЕМЕНТА СТЕКА Б.
** СУТЬ: СКОЛЬКО ОПЕРАЦИЙ ВРАЩЕНИЯ СТЕКА А НАДО СДЕЛАТЬ, ЧТОБ ЭЛЕМЕНТ ВСТАЛ В НУЖНОЕ МЕСТО
*/

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

/*
** ВЫСЧИТЫВАЕМ МИНИМАЛЬНЫЙ ЭЛЕМЕНТ В СТЕКЕ И ВОЗВРАЩАЕМ
** ЗНАЧЕНИЕ ПРИОРИТЕТА ДЛЯ НЕГО
*/

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

/*
** ВЫСТАВЛЯЕМ ПРИОРИТЕТЫ ДЛЯ НАЧАЛА, СЕРИДИНЫ И КОНЦА СТЕКА Б ОТДЕЛЬНО.
*/

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
