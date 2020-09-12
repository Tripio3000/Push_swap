/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseabass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 18:40:32 by cseabass          #+#    #+#             */
/*   Updated: 2020/07/31 18:40:34 by cseabass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_length(long long int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n = n * (-1);
		i++;
	}
	while ((n / 10) > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*itoa(long long int n)
{
	char			*a;
	int				len;
	long long int	tmp;

	len = ft_length(n);
	tmp = n;
	if (n == (-9223372036854775807 - 1))
		return (ft_strdup("-9223372036854775808"));
	if (!(a = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (n == 0)
		a[0] = '0';
	if (n < 0)
	{
		a[0] = '-';
		n = n * (-1);
	}
	a[len] = '\0';
	while (n > 0)
	{
		len--;
		a[len] = (n % 10) + '0';
		n = n / 10;
	}
	return (a);
}

void	init(t_struct *st)
{
	st->tmp = ft_memalloc(200);
	st->str = NULL;
	st->a = 0;
	st->f = 0;
	st->f_scp = 0;
	st->f_plus = 0;
	st->f_minus = 0;
	st->f_space = 0;
	st->f_resh = 0;
	st->f_nul = 0;
	st->wdht = 0;
	st->specif = ' ';
	st->num_flags = 0;
	st->wdth_pres = 0;
	st->zvezd = 0;
	st->f_pres = 0;
	st->num_flags = 0;
	st->without_0x = 0;
	st->f_trig = 0;
	st->f_color = 0;
}

char	*u_itoa(unsigned long long n)
{
	char					*a;
	int						len;
	unsigned long long int	tmp;

	len = u_ft_length(n);
	tmp = n;
	if (n == 9223372036854775808u)
		return (ft_strdup("9223372036854775808u"));
	if (!(a = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (n == 0)
		a[0] = '0';
	if (n < 0)
	{
		a[0] = '-';
		n = n * (-1);
	}
	a[len] = '\0';
	while (n > 0)
	{
		len--;
		a[len] = (n % 10) + '0';
		n = n / 10;
	}
	return (a);
}

int		u_ft_length(unsigned long long int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n = n * (-1);
		i++;
	}
	while ((n / 10) > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}
