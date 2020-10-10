/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseabass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 20:44:02 by cseabass          #+#    #+#             */
/*   Updated: 2020/09/12 20:44:04 by cseabass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_stack(t_stack *a, t_stack *b)
{
	t_data *p1;
	t_data *p2;

	ft_printf("+------A------+------B------+\n");
	p1 = a->head;
	p2 = b->head;
	while (p1 != NULL || p2 != NULL)
	{
		if (p1 != NULL)
		{
			ft_printf("|%13d", p1->num);
			p1 = p1->next;
		}
		else
			ft_printf("|             ");
		if (p2 != NULL)
		{
			ft_printf("|%-13d|\n", p2->num);
			p2 = p2->next;
		}
		else
			ft_printf("|             |\n");
	}
	ft_printf("+-------------+-------------+\n");
}

/*
** РАЗБИВАЕМ СТРОКУ НА ДВУМЕРНЫЙ МАССИВ ПО ПРОБЕЛАМ(НЕПЕЧАТНЫМ СИМВОЛАМ).
*/

char	**ft_split1(char *str, int i, int k)
{
	int		j;
	char	**mas;

	mas = (char **)malloc(sizeof(char *) * 1000);
	while (str[i] != '\0')
	{
		if (str[i] > 32)
		{
			j = 0;
			mas[k] = (char *)malloc(sizeof(char) * 1000);
			while (str[i] > 32)
			{
				mas[k][j] = str[i];
				j++;
				i++;
			}
			mas[k][j] = '\0';
			k++;
		}
		else
			i++;
	}
	mas[k] = 0;
	return (mas);
}

char	**ft_split(char *str)
{
	int		i;
	int		k;
	char	**mas;

	i = 0;
	k = 0;
	while (str[i] < 32)
		i++;
	mas = ft_split1(str, i, k);
	return (mas);
}

/*
**	ЗАПОЛНЕНИЕ СПИСКА ЧИСЛАМИ ИЗ АРГУМЕНТА
*/

void	create_stack1(char **mas)
{
	int j;

	j = 0;
	while (mas[j] != 0)
	{
		ft_memdel((void *)(&mas[j]));
		j++;
	}
	ft_memdel((void *)&mas);
}

void	create_stack(t_stack *a, int ac, char **av)
{
	int			i;
	int			j;
	long long	num;
	char		**mas;

	i = 1;
	if (a->v == 1)
		i = 2;
	while (i < ac)
	{
		mas = ft_split(av[i]);
		check_valid(mas);
		j = 0;
		while (mas[j] != 0)
		{
			num = ft_atoi_long(mas[j]);
			if (num > 2147483647 || num < -2147483648)
				error();
			push_back(a, num);
			j++;
		}
		i++;
		create_stack1(mas);
	}
	check_duplic(a);
}
