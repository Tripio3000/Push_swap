/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 17:06:05 by efleta            #+#    #+#             */
/*   Updated: 2020/08/06 17:06:07 by efleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	two_degree2(t_struct *st)
{
	char	*newptr;
	int		i;

	i = 0;
	while (st->arr[i] != '\0')
	{
		if (st->arr[i + 1] == '\0' && st->arr[i] > '9')
		{
			newptr = ft_memalloc(i + 4);
			ft_strcpy(newptr, st->arr);
			newptr[i] -= 10;
			newptr[i + 1] = 49;
			newptr[i + 2] = '\0';
			ft_memdel((void **)(&st->arr));
			st->arr = newptr;
			return ;
		}
		if (st->arr[i] > '9')
		{
			st->arr[i] -= 10;
			st->arr[i + 1]++;
		}
		i++;
	}
}

void	two_degree(t_struct *st)
{
	char	*tm;
	int		i;

	i = ft_strlen(st->arr);
	tm = ft_memalloc(i + 1);
	ft_strcpy(tm, st->arr);
	i = 0;
	while (st->arr[i] != '\0')
	{
		st->arr[i] += tm[i] - '0';
		i++;
	}
	ft_memdel((void **)(&tm));
	two_degree2(st);
}

void	rounding_fp(t_struct *st)
{
	char *arr;

	arr = ft_memalloc(2);
	arr[0] = '1';
	arr[1] = '\0';
	st->fp = get_char(st->fp);
	sum_char(st->fp, arr);
	st->fp = get_char(st->fp);
	st->f_zero = 0;
	st->sp[0] -= 10;
	ft_memdel((void **)(&arr));
}

int		sum_reverse2(const char *arr, t_struct *st)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	while (arr[j] != '\0')
	{
		st->sp[i] += arr[j] - '0';
		k = i;
		while (k > 0)
		{
			if (st->sp[k] > '9')
			{
				st->sp[k - 1]++;
				st->sp[k] -= 10;
			}
			k--;
		}
		i++;
		j++;
	}
	return (k);
}

void	sum_reverse(char *tmp, t_struct *st)
{
	int		i;
	int		j;
	int		k;
	char	*arr;

	i = ft_strlen(st->sp);
	j = ft_strlen(tmp);
	arr = ft_memalloc(j + 1);
	ft_strcpy(arr, tmp);
	arr = get_char(arr);
	while ((i - 1) == j || j > i)
	{
		st->sp = ft_realloc(st->sp, (i * 2));
		i = ft_strlen(st->sp);
	}
	k = sum_reverse2(arr, st);
	if (k == 0 && st->sp[k] > '9')
		rounding_fp(st);
	ft_memdel((void **)(&arr));
}
