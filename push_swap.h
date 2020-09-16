/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseabass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 17:15:41 by cseabass          #+#    #+#             */
/*   Updated: 2020/09/16 17:15:43 by cseabass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "ft_printf/includes/ft_printf.h"
# include "gnl/get_next_line.h"

typedef struct		s_data
{
	int				num;
	int				prior;
	struct s_data	*next;
	struct s_data	*prev;
}					t_data;

typedef struct		s_stack
{
	size_t	command;
	int		size;
	int		v;
	t_data	*head;
	t_data	*end;
}					t_stack;

/*
** help_func.c
*/

long long			ft_atoi_long(const char *nptr);
void				error(void);

/*
** read.c
*/

char				**ft_split(char *str);
char				**ft_split1(char *str, int i, int k);
void				ft_freee(t_stack *a, t_stack *b);
void				push_back(t_stack *src, int num);
void				create_stack(t_stack *a, int ac, char **av);
void				create_stack1(char **mas);
void				check_duplic(t_stack *a);
void				check_valid(char **mas);
void				print_stack(t_stack *a, t_stack *b);
void				ft_init(t_stack *a, t_stack *b);

/*
** operators.c
*/

void				swap(t_stack *a);
void				push1(t_data *p1, t_stack *b);
void				push(t_stack *src, t_stack *dst);
void				rev_rotate(t_stack *src);
void				rotate(t_stack *src);

/*
** push_swap.c
*/

void				help_func2(t_stack *a, t_stack *b);
void				help_func1(t_stack *a, t_stack *b, int size);
void				conditions(t_stack *a, t_stack *b, int size);
void				five_elem(t_stack *a, t_stack *b);
void				three_elem(t_stack *a);
void				three_elem1(t_stack *a, t_data *p1, t_data *p2, t_data *p3);
void				incr_prior(t_stack *b);
void				rotate_stack_a(t_stack *a);
void				rotate_stack_a1(t_stack *a, int i);
void				compound_ab(t_stack *a, t_stack *b);
int					compound_ab1(t_stack *a, t_stack *b, int n, int i);
void				compound_ab2(t_stack *a, t_stack *b, int i);
int					min_prior(t_stack *b);
void				prior_b(t_stack *a, t_stack *b);
void				end_prior(t_stack *b, t_data *p1, int prior);
t_data				*begin_prior(t_stack *a, t_stack *b, t_data *p1, int prior);
void				prior_for_middle(t_stack *b, t_data *p2,
					t_data *p1, int prior);
int					find_min_elem(t_stack *a);
t_data				*get_min(t_stack *src);
void				sort_a(t_stack *a);
void				sort_a1(t_stack *a);
void				get_prior_greather(t_data *tmp, t_stack *a);
void				check_swap(t_stack *a);
void				to_stack_b(t_stack *a, t_stack *b, int size);
t_data				*max_sequence_greather(t_stack *a);
int					find_prior(t_data *start, t_stack *a);
void				null_prior(t_stack *a);
int					check_list(t_stack *a, int size);

/*
** checker.c
*/

void				rotation(char *arr, t_stack *a, t_stack *b);
void				ascending_order(t_stack *a, int size);
void				std_input(t_stack *a, t_stack *b, int size);
void				check_command(char *arr);
int					wrong_size(t_stack *a, int size);
void				swapper(char *arr, t_stack *a, t_stack *b);
void				rev_rotation(char *arr, t_stack *a, t_stack *b);

#endif
