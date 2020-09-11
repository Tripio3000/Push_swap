#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "ft_printf/includes/ft_printf.h"
# include "gnl/get_next_line.h"
# include <limits.h>

//#define INT_MAX 0xffffffff

typedef struct 		s_data
{
	int num;
	int prior;
	struct s_data	*next;
	struct s_data	*prev;
}					t_data;

typedef struct 		s_stack
{
	size_t command;
	size_t size;
	int		v;
	t_data 	*head;
	t_data 	*end;
}					t_stack;

char 				**ft_split(char *str);
void 				ft_freee(t_stack *a, t_stack *b);
long long	ft_atoi_long(const char *nptr);
void 	error(void);
void 				pushBack(t_stack *src, int num);
void				create_stack(t_stack *a, int ac, char **av);
void 	print_stack(t_stack *a, t_stack *b); 			//УДАЛИТЬ
void 				swap(t_stack *a);
//void 				swapper(char *arr, t_stack *a, t_stack *b);
void 				push1(t_data *p1, t_stack *b);
void 				push(t_stack *src, t_stack *dst);
void 				ft_init(t_stack *a, t_stack *b);
void 				rev_rotate(t_stack *src);
//void 				rev_rotation(char *arr, t_stack *a, t_stack *b);
void 				rotate(t_stack *src);
//void 				rotation(char *arr, t_stack *a, t_stack *b);
//void				ascending_order(t_stack *a, int size);
//void 				std_input(t_stack *a, t_stack *b, int size);
//void 				push_swap(t_stack *a, t_stack *b);

#endif
