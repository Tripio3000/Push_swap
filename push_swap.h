#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"

typedef struct 		s_stack
{
	int num;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

#endif
