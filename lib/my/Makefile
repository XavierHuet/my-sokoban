##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile
##

SRC		=	my_putchar.c			\
			my_putstr.c				\
			my_put_nbr.c			\
			my_strcmp.c				\
			my_strlen.c				\
			my_strcpy.c				\
			my_printf.c				\
			my_putnbr_base.c		\
			type.c                  \
			function.c              \
			function_2.c			\
			my_scient.c				\
			my_scient_maj.c			\
			my_float.c				\
			my_strndup.c			\
			my_strto_word_array.c	\
			sokoban_1.c				\
			sokoban_2.c				\
			sokoban_3.c
CFLAGS  = -g3
OBJ		=	$(SRC:.c=.o)

NAME	=		libmy.a

all: $(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp my.h ../../include/
	cp $(NAME) ../../

clean:
	rm -rf *~
	rm -rf *#
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	rm -rf ../../$(NAME)

re: fclean all
