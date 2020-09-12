/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pres.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseabass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 18:43:37 by cseabass          #+#    #+#             */
/*   Updated: 2020/07/31 18:43:39 by cseabass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	pres_print(t_struct *st)
{
	if (st->wdth_pres == 0)
	{
		if (st->specif == 'o' && st->f_resh == 1)
			ft_strcpy(st->tmp, "0");
		else
			ft_strcpy(st->tmp, "");
		return ;
	}
	if (st->c_trig != 1)
	{
		if (st->a < 0)
		{
			st->schet += re_putchar('-');
			ft_memdel((void **)(&st->tmp));
			st->tmp = itoa((st->a * -1));
		}
		if (st->specif == 's')
			pres_str(st);
		else
			pres_num(st);
	}
}

void	pres_str(t_struct *st)
{
	int			i;
	long int	len;

	len = ft_strlen(st->tmp);
	i = 0;
	if (len == 0 && st->wdht == 0)
		return ;
	if ((st->wdth_pres < len) && st->wdth_pres >= 0)
	{
		while (i < st->wdth_pres)
		{
			st->schet = st->schet + re_putchar(st->tmp[i]);
			i++;
		}
	}
	else
	{
		while (st->tmp[i])
		{
			st->schet = st->schet + re_putchar(st->tmp[i]);
			i++;
		}
	}
}

void	pres_num(t_struct *st)
{
	int d;

	d = st->wdth_pres - ft_strlen(st->tmp);
	if (((size_t)st->wdth_pres > ft_strlen(st->tmp)) && st->f_scp == 0)
	{
		while (d > 0)
		{
			st->schet = st->schet + re_putchar('0');
			d--;
		}
	}
	else if (((size_t)st->wdth_pres < ft_strlen(st->tmp)))
		return ;
}
