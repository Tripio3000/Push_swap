/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseabass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 17:41:22 by cseabass          #+#    #+#             */
/*   Updated: 2020/09/16 17:41:24 by cseabass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swapper(char *arr, t_stack *a, t_stack *b)
{
	if ((ft_strcmp(arr, "sa") == 0 || ft_strcmp(arr, "ss") == 0) &&
		a->head != NULL && a->head->next != NULL)
		swap(a);
	if ((ft_strcmp(arr, "sb") == 0 || ft_strcmp(arr, "ss") == 0) &&
		b->head != NULL && b->head->next != NULL)
		swap(b);
}

void	rev_rotation(char *arr, t_stack *a, t_stack *b)
{
	if ((ft_strcmp(arr, "rra") == 0 || ft_strcmp(arr, "rrr") == 0) &&
		a->head != NULL && a->head->next != NULL)
		rev_rotate(a);
	if ((ft_strcmp(arr, "rrb") == 0 || ft_strcmp(arr, "rrr") == 0) &&
		b->head != NULL && b->head->next != NULL)
		rev_rotate(b);
}

void	rotation(char *arr, t_stack *a, t_stack *b)
{
	if ((ft_strcmp(arr, "ra") == 0 || ft_strcmp(arr, "rr") == 0) &&
		a->head != NULL && a->head->next != NULL)
		rotate(a);
	if ((ft_strcmp(arr, "rb") == 0 || ft_strcmp(arr, "rr") == 0) &&
		b->head != NULL && b->head->next != NULL)
		rotate(b);
}
