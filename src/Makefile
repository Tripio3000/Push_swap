LIB = libft

LIBA = libft.a

DIR_S = src

DIR_O = obj

DIR_H = includes

FILES = checker.c \

SRCS = $(addprefix $(DIR_S)/,$(FILES))

OBJS = $(addprefix $(DIR_O)/,$(FILES:.c=.o))

NAME_C = checker

all : library $(NAME_C)

library :
	make -C $(LIB)

$(NAME_C) : $(OBJS)
	gcc -o $(OBJS) $(LIB)/$(LIBA)

$(DIR_O)/%.o : $(DIR_S)/%.c
	mkdir -p $(DIR_O)
	gcc -o -c

clean :
	rm -rf $(DIR_O)
	make clean -C $(LIB)

fclean : clean
	rm -f $(NAME_C)
	make fclean -C $(LIB)

re : fclean all