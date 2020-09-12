/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseabass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 13:30:04 by cseabass          #+#    #+#             */
/*   Updated: 2020/07/31 13:30:06 by cseabass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	init_array(t_struct *st)
{
	st->arr = ft_memalloc(2);
	st->arr[0] = '1';
	st->arr[1] = '\0';
	st->sp = ft_memalloc(st->size);
	st->sp = ft_realloc(st->sp, st->size);
	st->fp = ft_memalloc(st->size);
	st->fp = ft_realloc(st->fp, st->size);
}

void	init_chars(t_struct *st)
{
	ft_memdel((void **)(&st->tmp));
	st->size = 8;
	st->f_zero = 0;
	st->neg_round = 0;
	st->sign_bit = 0;
	if (st->f_pres == 1)
		st->round = st->wdth_pres;
	else
		st->round = 6;
}

void	circle(t_struct *st, t_sun eeei)
{
	int c;
	int b;

	c = (SIZE_M - st->shift - 1);
	while (c < SIZE_M)
	{
		if (c == (SIZE_M - st->shift - 1) || c < 0)
		{
			if (c == (SIZE_M - st->shift - 1))
			{
				b = bits(eeei, c);
				if (b == 1 && c > 0)
					st->fp = sum_char(st->fp, st->arr);
			}
			else if (c < 0)
				two_degree(st);
			c++;
			continue ;
		}
		b = bits(eeei, c);
		two_degree(st);
		if (b == 1)
			st->fp = sum_char(st->fp, st->arr);
		c++;
	}
}

void	bit_parcer(long double f, t_struct *st)
{
	t_sun	eeei;
	int		c;

	eeei.f = f;
	init_chars(st);
	if (eeei.v.sign == 1)
		st->sign_bit = 1;
	c = check_zero(eeei, st);
	if (c == 1)
		return ;
	init_array(st);
	st->shift = exp_shift(eeei);
	if (st->shift >= 0)
	{
		circle(st, eeei);
		st->fp = get_char(st->fp);
		ft_memdel((void **)(&st->arr));
	}
	else
	{
		ft_memdel((void **)(&st->arr));
		st->f_zero = 1;
	}
	after_point(eeei, st);
	ft_out(st->sp, st);
}
