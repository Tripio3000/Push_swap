/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 17:11:30 by efleta            #+#    #+#             */
/*   Updated: 2020/08/06 17:11:32 by efleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	pres_check(char *format, t_struct *st, va_list ap)
{
	if (format[st->i] == '.')
	{
		pres_width(format, st, ap);
		st->f_pres = 1;
	}
}

void	pres_width1(t_struct *st, char *wdht, char *format)
{
	int j;

	j = 0;
	while (format[st->i] != '\0' && format[st->i] != '%')
	{
		if (format[st->i] >= 48 && format[st->i] <= 57)
		{
			wdht[j] = format[st->i];
			j++;
		}
		st->i++;
		if (format[st->i] == '.' || (format[st->i] > 96 &&
			format[st->i] < 123) || format[st->i] == st->specif)
			break ;
	}
	st->wdth_pres = ft_atoi(wdht);
	if (format[st->i - 1] >= 65 && format[st->i - 1] <= 122)
		st->i--;
}

void	pres_width(char *format, t_struct *st, va_list ap)
{
	int		j;
	char	*wdht;

	j = 0;
	if ((format[st->i] > 59 && format[st->i] < 127) && st->zvezd == 0)
		return ;
	if (st->zvezd > 0 || (format[st->i - 2] == '*' &&
		format[st->i - 1] != '%' && format[st->i - 1] != '.'))
		st->wdth_pres = va_arg(ap, int);
	else
	{
		wdht = ft_memalloc(20);
		pres_width1(st, wdht, format);
		free(wdht);
	}
}

void	width1(char *format, t_struct *st, va_list ap)
{
	if (format[st->i - 1] == '.' || (format[st->i - 2] == '.' &&
		format[st->i - 1] != '%'))
	{
		pres_width(format, st, ap);
		st->f_pres = 1;
	}
	else
	{
		detect_wdth(format, st, ap);
		pres_check(format, st, ap);
	}
}

void	width(char *format, t_struct *st, va_list ap)
{
	if (st->zvezd > 0)
	{
		if (st->zvezd == 1 && st->f_pres == 1 && format[st->i - 1] != '.')
			pres_width(format, st, ap);
		else if (st->zvezd == 2)
		{
			detect_wdth(format, st, ap);
			pres_width(format, st, ap);
		}
		else
			detect_wdth(format, st, ap);
	}
	else
		width1(format, st, ap);
	if (st->zvezd == 1 && st->f_pres == 1 && format[st->i - 1] == '.')
	{
		st->zvezd--;
		pres_width(format, st, ap);
	}
}
