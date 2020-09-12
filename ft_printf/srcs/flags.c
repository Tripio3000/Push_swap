/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseabass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 19:33:02 by cseabass          #+#    #+#             */
/*   Updated: 2020/07/31 19:33:05 by cseabass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	specif_di(t_struct *st)
{
	if (st->a < 0)
	{
		st->a *= -1;
		if (st->a != -2147483648)
			st->num_flags = 1;
	}
	ft_memdel((void **)(&st->tmp));
	st->tmp = itoa(st->a);
	st->i++;
}

void	specif_uoxx1(t_struct *st, unsigned long long a)
{
	st->specif = 'u';
	if (a == 9223372036854775808u)
		ft_strcpy(st->tmp, "9223372036854775808");
	else
	{
		ft_memdel((void **)(&st->tmp));
		st->tmp = u_itoa(a);
	}
	st->i++;
}

void	specif_uoxx(t_struct *st, char *format, unsigned long long int a)
{
	int trig;

	trig = 0;
	if (format[st->i] == 'o')
	{
		st->specif = 'o';
		octal(a, st);
		st->i++;
	}
	else if (format[st->i] == 'x' || format[st->i] == 'X')
	{
		st->specif = 'x';
		if (format[st->i] == 'X')
		{
			trig = 1;
			st->specif = 'X';
		}
		hexadecimal(a, trig, st);
		st->i++;
	}
	else if (format[st->i] == 'u')
		specif_uoxx1(st, a);
}

int		octal1(unsigned long long int a, t_struct *st)
{
	char	*hhh;
	int		i;
	int		f;

	f = 0;
	while (a > 0)
	{
		i = a % 8;
		hhh = itoa(i);
		st->tmp = ft_strjoin(st->str, hhh);
		free(hhh);
		ft_memdel((void **)(&st->str));
		st->str = st->tmp;
		a = a / 8;
		f++;
	}
	return (f);
}

void	octal(unsigned long long int a, t_struct *st)
{
	int		f;

	if (a == 0)
	{
		st->nul = 1;
		st->tmp[0] = '0';
		return ;
	}
	ft_memdel((void **)(&st->tmp));
	f = octal1(a, st);
	st->tmp = ft_memalloc(40);
	a = 0;
	while (--f >= 0)
		st->tmp[a++] = st->str[f];
	st->tmp[a] = '\0';
	ft_memdel((void **)(&st->str));
}
