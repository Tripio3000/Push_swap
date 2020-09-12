/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseabass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 18:42:31 by cseabass          #+#    #+#             */
/*   Updated: 2020/07/31 18:42:33 by cseabass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		re_putstr(char const *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int		re_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

void	plus_print(t_struct *st)
{
	if (st->specif == 's' || st->specif == 'c' || st->specif == 'p')
		st->f_plus = 0;
	if (st->f == 1)
	{
		if (st->sign_bit == 1)
			st->schet = st->schet + re_putchar('-');
		else if (st->f_plus == 1 && ft_strcmp(st->tmp, "nan") != 0)
			st->schet = st->schet + re_putchar('+');
	}
	else
	{
		if (st->num_flags == 1)
			st->schet = st->schet + re_putchar('-');
		else if (st->f_plus == 1)
			st->schet = st->schet + re_putchar('+');
	}
}

void	ft_printf_fl(char *format, t_struct *st, va_list ap)
{
	st->i--;
	if (format[st->i] == 'L')
		st->f_long = 2;
	else
		st->f_long = 0;
	st->i++;
	if (format[st->i] == 'f' && st->f_long == 0)
		st->fl = va_arg(ap, double);
	else if (format[st->i] == 'f' && st->f_long == 2)
		st->fl = va_arg(ap, long double);
	st->i++;
	st->f = 1;
	bit_parcer(st->fl, st);
}

void	ft_printf_sec(char *format, t_struct *st, va_list ap)
{
	if (format[st->i] == 'd' || format[st->i] == 'i')
	{
		st->a = va_arg(ap, int);
		st->specif = 'd';
		specif_di(st);
	}
	else if (format[st->i] == 'o' || format[st->i] == 'u' ||
		format[st->i] == 'x' || format[st->i] == 'X')
	{
		st->u = va_arg(ap, unsigned int);
		specif_uoxx(st, format, st->u);
		st->f_plus = 0;
	}
	else if (format[st->i] == 'p')
	{
		st->d = va_arg(ap, long long int);
		hexadecimal(st->d, 0, st);
		st->specif = 'p';
		st->i++;
	}
}
