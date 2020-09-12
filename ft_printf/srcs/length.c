/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseabass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 18:15:31 by cseabass          #+#    #+#             */
/*   Updated: 2020/07/31 18:15:33 by cseabass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		length(char *format, t_struct *st, va_list ap)
{
	if (format[st->i] == 'h' && format[st->i + 1] == 'h')
	{
		st->i = st->i + 2;
		if (format[st->i] == 'd' || format[st->i] == 'i')
		{
			st->a = (char)va_arg(ap, int);
			specif_di(st);
		}
		else if (format[st->i] == 'o' || format[st->i] == 'u' ||
				format[st->i] == 'x' || format[st->i] == 'X')
		{
			st->a = (unsigned char)va_arg(ap, int);
			specif_uoxx(st, format, st->a);
			st->f_plus = 0;
		}
	}
	else if (format[st->i] == 'h')
		return (short_length(format, st, ap));
	else if (format[st->i] == 'l' ||
	(format[st->i] == 'l' && format[st->i + 1] == 'l'))
		return (long_length(format, st, ap));
	else
		return (0);
	return (1);
}

int		short_length(char *format, t_struct *st, va_list ap)
{
	st->i++;
	if (format[st->i] == 'd' || format[st->i] == 'i')
	{
		st->a = (short int)va_arg(ap, int);
		specif_di(st);
	}
	else if (format[st->i] == 'o' || format[st->i] == 'u' ||
			format[st->i] == 'x' || format[st->i] == 'X')
	{
		st->a = (unsigned short int)va_arg(ap, int);
		specif_uoxx(st, format, st->a);
		st->f_plus = 0;
	}
	else
		st->f_space = 0;
	return (1);
}

void	long_length1(char *format, t_struct *st, va_list ap)
{
	st->o = va_arg(ap, unsigned long long int);
	specif_uoxx(st, format, st->o);
	st->f_plus = 0;
}

int		long_length(char *format, t_struct *st, va_list ap)
{
	st->i++;
	if (format[st->i] == 'l')
		st->i++;
	if (format[st->i] == 'd' || format[st->i] == 'i')
	{
		ft_memdel((void **)(&st->tmp));
		st->d = va_arg(ap, long long int);
		if (st->d < 0)
		{
			st->d *= -1;
			if (st->d != (-9223372036854775807 - 1))
				st->num_flags = 1;
		}
		st->tmp = itoa(st->d);
		st->i++;
	}
	else if (format[st->i] == 'o' || format[st->i] == 'u' ||
			format[st->i] == 'x' || format[st->i] == 'X')
		long_length1(format, st, ap);
	else
		return (0);
	return (1);
}
