/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 17:14:14 by efleta            #+#    #+#             */
/*   Updated: 2020/08/06 17:14:15 by efleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	space_print1(t_struct *st, int c, int i)
{
	if (st->specif == 's' || st->specif == 'c' || st->specif == 'p')
		st->f_plus = 0;
	if ((st->num_flags == 1 && st->f_plus != 1) ||
		(st->num_flags != 1 && st->f_plus == 1) || st->sign_bit == 1)
		c--;
	else if (st->num_flags == 1 && st->f_plus == 1)
		c--;
	else if (st->f_space == 1 && st->num_flags != 1)
		c--;
	if (st->specif == 'p')
		c = c - 2;
	if (st->f_resh == 1 && (st->specif == 'x' || st->specif == 'X') &&
		st->without_0x == 0)
		c = c - 2;
	else if ((st->f_resh == 1 && st->specif == 'o') &&
			((st->f_pres == 1 && st->wdth_pres <= i) ||
			(st->wdht > 0 && st->f_pres == 0 && st->without_0x != 1)))
		c--;
	while (c > 0)
	{
		st->schet = st->schet + re_putchar(' ');
		c--;
	}
}

void	space_print(t_struct *st)
{
	int c;
	int i;

	if (st->f_space == 1 && st->num_flags != 1 && st->wdht == 0)
		return ;
	if (st->wdth_pres == 0 && st->f_pres == 1 && st->f != 1 &&
	(st->specif == 's' || ft_strcmp(st->tmp, "0") == 0))
		i = 0;
	else
		i = ft_strlen(st->tmp);
	if (st->wdth_pres > 0 && i < st->wdth_pres && st->specif == 's')
		c = st->wdht - i;
	else if (st->wdth_pres > 0 && i > st->wdth_pres && st->specif == 's')
		c = st->wdht - st->wdth_pres;
	else if (st->wdth_pres > 0 && (i < st->wdth_pres) && st->f_scp == 0)
		c = st->wdht - st->wdth_pres;
	else if (st->wdth_pres > 0 && (i > st->wdth_pres) && st->specif != 's')
		c = st->wdht - i;
	else
		c = st->wdht - i;
	space_print1(st, c, i);
}

void	null_print2(t_struct *st, int c)
{
	if (st->specif == 'p')
		c = c - 2;
	if ((st->f_resh == 1 && (st->specif == 'x' || st->specif == 'X')) &&
		st->without_0x == 0)
		c = c - 2;
	else if (st->f_resh == 1 && st->specif == 'o' &&
			st->without_0x == 0)
		c--;
	while (c > 0)
	{
		st->schet = st->schet + re_putchar('0');
		c--;
	}
}

void	null_print1(t_struct *st, int i)
{
	int c;

	if (st->wdth_pres > 0 && i > st->wdth_pres)
		c = st->wdht - i;
	else if (st->wdth_pres > 0 && i < st->wdth_pres)
		c = st->wdht - st->wdth_pres;
	else
		c = st->wdht - i;
	if (st->wdth_pres > 0 && i > st->wdth_pres && st->f_scp == 1)
		c = st->wdht - st->wdth_pres;
	if ((st->num_flags == 1 && st->f_plus != 1) ||
		(st->num_flags != 1 && st->f_plus == 1) || st->sign_bit == 1)
		c--;
	else if (st->num_flags == 1 && st->f_plus == 1)
		c--;
	else if (st->f_space == 1 && st->num_flags != 1)
		c--;
	null_print2(st, c);
}

void	null_print(t_struct *st)
{
	int i;

	i = ft_strlen(st->tmp);
	if (st->f_scp == 1 && st->wdth_pres == 0 && st->f_pres == 1)
		i = 0;
	else
		null_print1(st, i);
}
