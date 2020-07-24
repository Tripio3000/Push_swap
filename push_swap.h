#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"

typedef struct 		s_data
{
	int a;
}					t_data;

typedef struct 		s_stack
{
	t_data data;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

#endif
