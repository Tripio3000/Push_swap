/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 17:06:29 by efleta            #+#    #+#             */
/*   Updated: 2020/08/06 17:06:30 by efleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		check_zero1(t_sun eeei, t_struct *st)
{
	int i;

	i = check_inf_nan(eeei, st);
	if (i == 1)
	{
		st->f_nul = 0;
		st->wdth_pres = 0;
		st->f_pres = 0;
		return (1);
	}
	return (0);
}

int		check_zero(t_sun eeei, t_struct *st)
{
	int i;
	int j;

	i = -1;
	j = 0;
	if (eeei.v.exp == 0 && eeei.v.mant == 0)
	{
		st->tmp = ft_memalloc(st->round + 4);
		st->tmp[++i] = '0';
		if (st->round != 0 || st->f_resh != 0)
			st->tmp[++i] = '.';
		if (st->round < 0)
			st->round = 6;
		while (j < st->round)
		{
			st->tmp[++i] = '0';
			j++;
		}
		return (1);
	}
	i = check_zero1(eeei, st);
	if (i == 1)
		return (1);
	return (0);
}

int		bits(t_sun eeei, int c)
{
	if (eeei.v.mant & (1L << c))
		return (1);
	return (0);
}

void	after_point(t_sun eeei, t_struct *st)
{
	int count;
	int c;
	int b;

	st->arr = ft_memalloc(2);
	st->arr[0] = '1';
	count = 0;
	c = (SIZE_M - st->shift - 2);
	while (c >= 0)
	{
		count++;
		b = bits(eeei, c);
		if (c > SIZE_M)
		{
			st->arr = multiplication(st->arr, 5, count);
			c--;
			continue;
		}
		st->arr = multiplication(st->arr, 5, count);
		if (b == 1 && c != SIZE_M)
			sum_reverse(st->arr, st);
		c--;
	}
	ft_memdel((void **)(&st->arr));
}
