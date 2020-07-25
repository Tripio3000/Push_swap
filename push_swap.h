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
	int num;
	struct s_data	*next;
	struct s_data	*prev;
}					t_data;

typedef struct 		s_stack
{
	size_t size;
	t_data 	*head;
	t_data 	*end;
}					t_stack;

#endif
