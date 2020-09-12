/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 17:06:17 by efleta            #+#    #+#             */
/*   Updated: 2020/08/06 17:06:18 by efleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	*get_zero(char *arr)
{
	char	*newptr;
	int		i;

	newptr = ft_memalloc(ft_strlen(arr) + 3);
	i = 0;
	while (arr[i] != '\0')
	{
		newptr[i] = arr[i];
		i++;
	}
	newptr[i] = '0';
	newptr[i + 1] = '\0';
	ft_memdel((void **)(&arr));
	return (newptr);
}

void	*multiplication2(const char *ar, char *newptr)
{
	int j;

	j = 0;
	while (ar[j] != '\0')
	{
		newptr[j] += ar[j] - '0';
		if (newptr[j] > '9')
		{
			if (newptr[j + 1] == '\0')
			{
				newptr[j + 1] = '0';
				newptr[j + 2] = '\0';
			}
			newptr[j + 1]++;
			newptr[j] -= 10;
		}
		j++;
	}
	return (newptr);
}

void	*multiplication(char *arr, int num, int deg)
{
	int		i;
	char	*newptr;

	newptr = ft_memalloc(ft_strlen(arr) + 3);
	ft_strcpy(newptr, arr);
	i = 0;
	while (i < num - 1)
	{
		newptr = multiplication2(arr, newptr);
		i++;
	}
	if (ft_strlen(newptr) < (size_t)deg)
		newptr = get_zero(newptr);
	ft_memdel((void **)(&arr));
	return (newptr);
}

int		exp_shift(t_sun eeei)
{
	int a;

	a = eeei.v.exp - SIZE_E;
	return (a);
}

int		check_inf_nan(t_sun eeei, t_struct *st)
{
	if (eeei.f == eeei.f * 10 && eeei.f != 0.0)
	{
		st->tmp = ft_strjoin(st->tmp, "inf");
		return (1);
	}
	else if (eeei.f != eeei.f)
	{
		st->tmp = ft_strjoin(st->tmp, "nan");
		st->f_space = 0;
		st->f_plus = 0;
		return (1);
	}
	return (0);
}
