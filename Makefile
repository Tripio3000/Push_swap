FLAGS = -Wall -Wextra -Werror

FILES_P = src/push_swap.c \
			src/read.c \
			src/operators.c \

FILES_C = src/checker.c \
			src/read.c \
			src/operators.c \
			gnl/get_next_line.c \


LIBSRC = libft
LIB = $(LIBSRC)/libft.a

INCLUDES = push_swap.h

NAME_C = checker
NAME_P = push_swap

OBJ = $(patsubst %.c,%.o,$(FILES_C)$(FILES_P))
# OBJ = $(FILES_C:.c=.o)

.PHONY: clean all fclean re

all : $(NAME_P) $(NAME_C)

$(NAME_P) : $(OBJ)
	@make -C $(LIBSRC)
	@cc -o $(NAME_P) $(FILES_P) -I $(INCLUDES) $(LIB) -g

$(NAME_C) : $(OBJ)
	@cc -o $(NAME_C) $(FILES_C) -I $(INCLUDES) $(LIB) -g

%.o: %.c $(INCLUDES) libft/libft.h
	cc -I $(INCLUDES) $< -c -o $@ -g

# %.o: %.c $(INCLUDES)

clean :
	@rm -rf $(OBJ)
	@make clean -C libft

fclean : clean
	@rm -rf $(NAME_P)
	@rm -rf $(NAME_C)
	@make fclean -C libft

re : fclean all