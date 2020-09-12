C = clang

FLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

DIR_O = ./obj
DIR_S = ./srcs
DIR_H = ./includes

LIBFT = libft


INCS = -I $(DIR_H)

FILES = ft_printf.c \
        flags.c \
        new.c \
        re_func.c \
        color_print.c \
        print.c \
        pres.c \
        length.c \
        support.c \
        floats.c \
        float_print.c \
        hex.c \

FILES_MAIN = srcs/flags.c \
             srcs/ft_printf.c \
             srcs/new.c \
             srcs/re_func.c \
             srcs/color_print.c \
             srcs/print.c \
             srcs/pres.c \
             srcs/length.c \
             srcs/support.c \
             srcs/floats.c \
             srcs/float_print.c \
             srcs/hex.c \
             srcs/floats2.c \
             srcs/floats3.c \
             srcs/floats4.c \
             srcs/floats5.c \
             srcs/width.c \
             srcs/flags_print.c

SRCS = srcs/ft_printf.c srcs/new.c srcs/flags.c \
       srcs/re_func.c srcs/color_print.c srcs/print.c \
       srcs/pres.c srcs/length.c srcs/support.c srcs/floats.c \
       srcs/float_print.c \
       srcs/hex.c srcs/floats2.c srcs/floats3.c srcs/floats4.c \
       srcs/floats5.c srcs/width.c  srcs/flags_print.c

OBJS = srcs/ft_printf.o srcs/new.o srcs/flags.o \
       srcs/re_func.o srcs/color_print.o srcs/print.o \
       srcs/pres.o srcs/length.o srcs/support.o srcs/floats.o \
       srcs/float_print.o srcs/hex.o srcs/floats2.o srcs/floats3.o \
       srcs/floats4.o srcs/floats5.o srcs/width.o  srcs/flags_print.o

all: $(NAME) $(DIR_H)/ft_printf.h

$(NAME): $(OBJS) $(DIR_H)/ft_printf.h
	@make -C $(LIBFT) re
	@cp $(LIBFT)/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(DIR_S)/%.o: $(DIR_S)/%.c $(DIR_H)/ft_printf.h
	gcc $(FLAGS) -I $(DIR_H)/ft_printf.h -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all


main: fclean all
	@gcc -g $(FILES_MAIN) $(LIBFT)/libft.a
	@./a.out

del: fclean
	@rm a.out

test:
	@gcc test.c libftprintf.a
	@./a.out

.PHONY: all clean fclean re