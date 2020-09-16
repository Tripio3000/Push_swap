FLAGS = -Wall -Wextra -Werror

FILES_P = src/push_swap.c \
			src/read.c \
			src/read1.c \
			src/operators.c \
			src/help_func.c \
			src/push_swap1.c \
			src/push_swap2.c \
			src/push_swap3.c \
			src/push_swap4.c \
			src/push_swap5.c \

FILES_C = src/checker.c \
			src/checker1.c \
			src/read.c \
			src/read1.c \
			src/operators.c \
			gnl/get_next_line.c \
			src/help_func.c \


LIBSRC = libft
LIB = $(LIBSRC)/libft.a
PRINT = ft_printf/libftprintf.a

INCLUDES = push_swap.h

NAME_C = checker
NAME_P = push_swap

OBJ = $(patsubst %.c,%.o,$(FILES_C)$(FILES_P))
# OBJ = $(FILES_C:.c=.o)

.PHONY: clean all fclean re

all : $(NAME_P) $(NAME_C)

$(NAME_P) : lib_comp $(OBJ)
	@cc $(FLAGS) -o $(NAME_P) $(FILES_P) -I $(INCLUDES) $(LIB) $(PRINT) -g

$(NAME_C) : lib_comp $(OBJ)
	@cc $(FLAGS) -o $(NAME_C) $(FILES_C) -I $(INCLUDES) $(LIB) $(PRINT) -g

lib_comp :
		@make -C $(LIBSRC) re
		@make -C ft_printf

%.o: %.c $(INCLUDES) libft/libft.h ft_printf/includes/ft_printf.h
	cc -I $(INCLUDES) $< -c -o $@ -g

# %.o: %.c $(INCLUDES)

clean :
	@rm -rf $(OBJ)
	@make clean -C libft
	@make clean -C ft_printf

fclean : clean
	@rm -rf $(NAME_P)
	@rm -rf $(NAME_C)
	@make fclean -C libft
	@make fclean -C ft_printf

re : fclean all