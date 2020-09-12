/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 17:05:39 by efleta            #+#    #+#             */
/*   Updated: 2020/08/06 17:05:41 by efleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	hexadecimal3(int i, t_struct *st)
{
	ft_memdel((void **)(&st->l));
	st->l = itoa(i);
}

int		hexadecimal2(unsigned long long int a, int trig, t_struct *st)
{
	int i;
	int f;

	f = 0;
	while (a > 0)
	{
		i = a % 16;
		if (i > 9)
		{
			if (trig == 1)
				st->l[0] = (i - 10) + 'A';
			else
				st->l[0] = (i - 10) + 'a';
			st->l[1] = '\0';
		}
		else
			hexadecimal3(i, st);
		st->str = ft_strjoin(st->tmp, st->l);
		ft_memdel((void **)(&st->tmp));
		st->tmp = st->str;
		a = a / 16;
		f++;
	}
	return (f);
}

void	hexadecimal(unsigned long long int a, int trig, t_struct *st)
{
	int	f;

	if (a == 0)
	{
		st->tmp[0] = '0';
		st->nul = 1;
		return ;
	}
	if (a < 0)
		a *= -1;
	ft_memdel((void **)(&st->tmp));
	st->l = ft_memalloc(20);
	f = hexadecimal2(a, trig, st);
	ft_memdel((void **)(&st->l));
	st->tmp = ft_memalloc(400);
	a = 0;
	while (--f >= 0)
		st->tmp[a++] = st->str[f];
	st->tmp[a] = '\0';
	ft_memdel((void **)(&st->str));
}
