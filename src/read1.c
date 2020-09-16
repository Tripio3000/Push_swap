/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseabass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 17:43:31 by cseabass          #+#    #+#             */
/*   Updated: 2020/09/16 17:43:33 by cseabass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_init(t_stack *a, t_stack *b)
{
	a->size = 0;
	a->head = NULL;
	a->end = NULL;
	b->size = 0;
	b->head = NULL;
	b->end = NULL;
	a->command = 0;
	a->v = 0;
	b->v = 0;
}

void	push_back(t_stack *src, int num)
{
	t_data	*tmp;

	tmp = (t_data *)malloc(sizeof(t_data));
	tmp->num = num;
	tmp->next = NULL;
	tmp->prev = src->end;
	if (src->end)
		src->end->next = tmp;
	src->end = tmp;
	if (src->head == NULL)
		src->head = tmp;
	src->size++;
}

void	check_valid(char **mas)
{
	int i;
	int j;

	i = 0;
	while (mas[i] != 0)
	{
		if (ft_strlen(mas[i]) > 11)
			error();
		j = 0;
		while (mas[i][j] != '\0')
		{
			if ((mas[i][j] < '0' || mas[i][j] > '9') &&
				mas[i][j] != '-')
				error();
			j++;
		}
		i++;
	}
}

void	check_duplic(t_stack *a)
{
	t_data	*p1;
	t_data	*p2;
	int		i;

	p1 = a->head;
	while (p1 != NULL)
	{
		i = p1->num;
		p2 = p1->next;
		while (p2 != NULL)
		{
			if (i == p2->num)
				error();
			p2 = p2->next;
		}
		p1 = p1->next;
	}
}

void	ft_freee(t_stack *a, t_stack *b)
{
	t_data	*p;
	t_data	*tmp;

	p = a->head;
	while (p != NULL)
	{
		tmp = p->next;
		ft_memdel((void *)&p);
		p = tmp;
	}
	p = b->head;
	while (p != NULL)
	{
		tmp = p->next;
		ft_memdel((void *)&p);
		p = tmp;
	}
	ft_memdel((void *)&a);
	ft_memdel((void *)&b);
}
