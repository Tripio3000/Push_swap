FILES = src/checker.c src/push_swap.c \

INCLUDES = push_swap.h

NAME_C = checker

all : library $(NAME_C)

library :
	@make -C libft

$(NAME_C) :
	@gcc $(FILES) $(INCLUDES) libft/libft.a gnl/get_next_line.c

clean :
	@rm a.out
	@make clean -C libft

fclean : clean
	@make fclean -C libft

re : fclean all