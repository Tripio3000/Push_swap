/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseabass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 18:05:45 by cseabass          #+#    #+#             */
/*   Updated: 2020/07/31 18:05:49 by cseabass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_cs1(t_struct *st, va_list ap)
{
	st->c = va_arg(ap, int);
	st->specif = 'c';
	if (!st->c)
	{
		st->c_trig = 1;
		ft_strcpy(st->tmp, "s");
	}
	else
	{
		st->tmp[0] = st->c;
		st->tmp[1] = '\0';
	}
	st->i++;
}

void	ft_print_cs(int trig, t_struct *st, va_list ap)
{
	if (trig == 1)
	{
		st->s = va_arg(ap, char *);
		st->specif = 's';
		if (st->s == NULL)
			ft_strcpy(st->tmp, "(null)");
		else
			ft_strcpy(st->tmp, st->s);
		st->i++;
	}
	else if (trig == 2)
		ft_print_cs1(st, ap);
}

void	specifier(char *format, t_struct *st, va_list ap)
{
	if (format[st->i] != 's' && format[st->i] != 'c' && format[st->i] != 'p' &&
		format[st->i] != 'd' && format[st->i] != 'i' &&
		format[st->i] != 'o' && format[st->i] != 'u' &&
		format[st->i] != 'x' && format[st->i] != 'X' && format[st->i] !=
		'f')
	{
		st->tmp[0] = format[st->i];
		st->tmp[1] = '\0';
		st->f_space = 0;
		if (format[st->i] != '\0')
			ft_print(st);
		else
			st->i--;
		st->i++;
		return ;
	}
	if (format[st->i] == 's')
		ft_print_cs(1, st, ap);
	else if (format[st->i] == 'c')
		ft_print_cs(2, st, ap);
	else if (format[st->i] == 'f')
		ft_printf_fl(format, st, ap);
	else
		ft_printf_sec(format, st, ap);
	ft_print(st);
}

void	handle(char *format, va_list ap, t_struct *st)
{
	int i;

	init(st);
	st->i++;
	flags(format, st);
	width(format, st, ap);
	i = length(format, st, ap);
	if (format[st->i] == 'L')
		st->i++;
	if (i == 0)
		specifier(format, st, ap);
	else
		ft_print(st);
}

int		ft_printf(char *format, ...)
{
	va_list		ap;
	t_struct	*st;
	int			i;

	st = (t_struct *)ft_memalloc(sizeof(t_struct));
	va_start(ap, format);
	st->color = ft_memalloc(20);
	st->i = 0;
	while (format[st->i] != '\0')
	{
		if (format[st->i] == '%')
			handle(format, ap, st);
		else if (format[st->i] == '{' && st->f_color == 0)
			proverka(format, st);
		else
		{
			st->schet = st->schet + re_putchar(format[st->i]);
			st->i++;
		}
	}
	va_end(ap);
	i = st->schet;
	memdel(st);
	return (i);
}
