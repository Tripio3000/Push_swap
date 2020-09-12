/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efleta <efleta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:00:01 by efleta            #+#    #+#             */
/*   Updated: 2020/03/06 16:35:43 by efleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	proverka(char *format, t_struct *st)
{
	int i;

	i = 0;
	st->i++;
	while (format[st->i] != '}')
	{
		st->color[i] = format[st->i++];
		i++;
	}
	st->color[i] = '\0';
	st->i++;
	color_print(st);
}

void	color_print(t_struct *st)
{
	if (ft_strcmp(st->color, "Blue") == 0)
		re_putstr("\033[1;34m");
	else if (ft_strcmp(st->color, "Magenta") == 0)
		re_putstr("\033[1;35m");
	else if (ft_strcmp(st->color, "Cyan") == 0)
		re_putstr("\033[1;36m");
	else if (ft_strcmp(st->color, "Red") == 0)
		re_putstr("\033[1;31m");
	else if (ft_strcmp(st->color, "Green") == 0)
		re_putstr("\033[1;32m");
	else if (ft_strcmp(st->color, "eoc") == 0)
		re_putstr("\033[0m");
	else
	{
		st->i = st->i - ft_strlen(st->color) - 2;
		st->f_color = 1;
	}
}
