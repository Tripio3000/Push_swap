/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 17:05:52 by efleta            #+#    #+#             */
/*   Updated: 2020/08/06 17:05:54 by efleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	*ft_cpy(char *newptr, char *ptr, int size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (ptr[i] != '\0')
	{
		newptr[i] = ptr[i];
		i++;
	}
	while (i < size)
	{
		newptr[i] = '0';
		i++;
	}
	newptr[i] = '\0';
	return (newptr);
}

void	*ft_realloc(void *ptr, size_t size)
{
	char	*newptr;

	if (!size && ptr)
	{
		if (!(newptr = (char *)malloc(1)))
			return (NULL);
		ft_memdel(&ptr);
		return (newptr);
	}
	if (!(newptr = (char *)malloc(size + 1)))
		return (NULL);
	if (ptr)
	{
		ft_cpy(newptr, ptr, size);
		ft_memdel(&ptr);
	}
	return (newptr);
}

void	*get_char(char *arr)
{
	char	*mas;
	int		i;
	int		j;

	j = ft_strlen(arr);
	i = 0;
	mas = ft_memalloc(ft_strlen(arr) + 1);
	while (arr[i] != '\0')
	{
		mas[i] = arr[j - 1];
		i++;
		j--;
	}
	mas[i] = '\0';
	ft_memdel((void **)(&arr));
	arr = mas;
	return (arr);
}

void	*sum_char2(char *ans, int i, int j)
{
	char *newptr;

	while (ans[i] != '\0')
	{
		if (ans[i] > '9')
		{
			if (ans[i + 1] == '\0')
			{
				newptr = ft_strnew(j + 1);
				ft_strcpy(newptr, ans);
				newptr[i] -= 10;
				newptr[i + 1] = 49;
				newptr[i + 2] = '\0';
				ft_memdel((void **)(&ans));
				return (newptr);
			}
			else
			{
				ans[i + 1]++;
				ans[i] -= 10;
			}
		}
		i++;
	}
	return (ans);
}

void	*sum_char(char *ans, char *tmp)
{
	int i;
	int j;

	i = ft_strlen(ans);
	j = ft_strlen(tmp);
	while ((i - 1) == j || j > i)
	{
		ans = ft_realloc(ans, (i * 2));
		i = ft_strlen(ans);
		j = ft_strlen(tmp);
	}
	i = 0;
	while (tmp[i] != '\0' && ans[i] != '\0')
	{
		ans[i] += tmp[i] - '0';
		i++;
	}
	i = 0;
	ans = sum_char2(ans, i, j);
	return (ans);
}
