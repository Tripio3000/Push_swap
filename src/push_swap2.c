/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseabass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 17:45:48 by cseabass          #+#    #+#             */
/*   Updated: 2020/09/16 17:45:49 by cseabass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
** ВРАЩАЕМ СТЕКИ НУЖНОЕ КОЛИЧЕСТВО РАЗ И ПЕРЕНОСИМ ЭЛЕМЕНТ В СТЕК А.
*/

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

/*
** УВЕЛИЧИВАЕМ ПРИОРИТЕТ ЭЛЕМЕНТА, В ЗАВИСИМОСТИ ОТ ЕГО
** ПОЗИЦИИ ОТНОСИТЕЛЬНО КОНЦОВ СТЕКА.
*/

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
