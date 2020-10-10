/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseabass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 21:07:09 by cseabass          #+#    #+#             */
/*   Updated: 2020/09/12 21:07:11 by cseabass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
** ВСЕ НУЖНЫЕ КОМАНДЫ.
*/

void	swap(t_stack *a)
{
	t_data *p1;
	t_data *p2;
	t_data *p3;

	p1 = (*a).head;
	p2 = p1->next;
	p3 = p2->next;
	a->head = p2;
	a->head->prev = NULL;
	a->head->next = p1;
	p1->next = p3;
	if (p3)
		p3->prev = p1;
	else
		a->end = p1;
	p1->prev = p2;
}

void	push1(t_data *p1, t_stack *b)
{
	p1->prev = NULL;
	p1->next = b->head;
	if (b->head)
		b->head->prev = p1;
	b->head = p1;
	if (b->end == NULL)
		b->end = p1;
	b->size++;
}

void	push(t_stack *src, t_stack *dst)
{
	t_data *p1;
	t_data *p2;

	p1 = src->head;
	if (p1->next == NULL)
	{
		push1(p1, dst);
		src->head = NULL;
		src->size--;
		return ;
	}
	p2 = p1->next;
	src->head = p2;
	src->size--;
	p2->prev = NULL;
	push1(p1, dst);
}

void	rotate(t_stack *src)
{
	t_data *p1;
	t_data *p2;

	p1 = src->head;
	p2 = src->head->next;
	p1->next = NULL;
	p1->prev = src->end;
	if (src->end)
		src->end->next = p1;
	src->end = p1;
	if (src->head == NULL)
		src->head = p1;
	src->head = p2;
	p2->prev = NULL;
}

void	rev_rotate(t_stack *src)
{
	t_data *p1;
	t_data *p2;

	p1 = src->end;
	p2 = src->end->prev;
	p1->next = src->head;
	p1->prev = NULL;
	if (src->head)
		src->head->prev = p1;
	src->head = p1;
	if (src->end == NULL)
		src->end = p1;
	src->end = p2;
	p2->next = NULL;
}
