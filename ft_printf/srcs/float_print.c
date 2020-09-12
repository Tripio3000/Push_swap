/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseabass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 18:45:05 by cseabass          #+#    #+#             */
/*   Updated: 2020/07/31 18:45:07 by cseabass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_out1(t_struct *st, int i)
{
	int j;
	int k;

	j = 0;
	k = ft_strlen(st->sp);
	while (j < st->round && j < k)
		st->tmp[i++] = st->sp[j++];
	while (j < st->round)
	{
		st->tmp[i++] = '0';
		j++;
	}
}

void	ft_out(char *sp, t_struct *st)
{
	int i;
	int j;

	if (st->round < 0)
		st->round = 6;
	rounding(sp, st);
	st->tmp = ft_memalloc(ft_strlen(st->fp) + st->round + 2);
	i = 0;
	j = 0;
	if (st->f_zero == 0)
	{
		while (st->fp[j] == '0')
			j++;
		while (st->fp[j] != '\0')
			st->tmp[i++] = st->fp[j++];
	}
	else
		st->tmp[i++] = '0';
	if (st->round != 0 || st->f_resh != 0)
		st->tmp[i++] = '.';
	ft_out1(st, i);
	ft_memdel((void **)(&st->fp));
	ft_memdel((void **)(&st->sp));
}

int		check_round(t_struct *st)
{
	int j;

	j = st->round + 1;
	while (st->sp[j] != '\0')
	{
		if (st->sp[j] != '0')
			break ;
		j++;
	}
	if (st->sp[j] == '\0')
		return (1);
	return (0);
}

void	zero_round(t_struct *st)
{
	int i;
	int j;

	i = 0;
	j = check_round(st);
	while (st->fp[i] != '\0')
		i++;
	i--;
	if ((st->fp[i] == '0' || st->fp[i] == '2' ||
	st->fp[i] == '4' || st->fp[i] == '6' ||
	st->fp[i] == '8') && st->sp[st->round] == '5' && j == 1)
		return ;
	else if (st->sp[st->round] >= '5')
		rounding_fp(st);
}

void	rounding(char *sp, t_struct *st)
{
	int		i;
	int		j;
	char	*arr;

	j = check_round(st);
	i = ft_strlen(sp);
	if (st->round == 0)
		zero_round(st);
	if (st->round < i && sp[st->round] >= '5' && st->round > 0 && j == 0)
	{
		arr = ft_memalloc(st->round + 2);
		arr[j] = '1';
		while (j < st->round - 1)
		{
			j++;
			arr[j] = '0';
		}
		sum_reverse(arr, st);
		ft_memdel((void **)(&arr));
	}
}
