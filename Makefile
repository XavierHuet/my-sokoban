##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile
##

SRC_TESTS	=	\

LIB		=	lib/my/my_putchar.c		\
			lib/my/my_putstr.c		\
			lib/my/my_put_nbr.c		\
			lib/my/my_strcmp.c		\
			lib/my/my_strlen.c		\
			lib/my/my_printf.c		\
			lib/my/my_putnbr_base.c	\
			lib/my/my_float.c		\
			lib/my/type.c			\
			lib/my/function.c		\
			lib/my/my_scient.c		\
			lib/my/my_scient_maj.c	\
			lib/my/function_2.c		\
			lib/my/my_strndup.c		\
			lib/my/my_strto_word_array.c\
			lib/my/sokoban_1.c		\
			lib/my/sokoban_2.c		\
			lib/my/sokoban_3.c


MAIN		=		src/main.c
NAME		=		libmy.a
TEST_BIN	=		unit_tests
LOCAL_BIN	=		my_sokoban
NCURSES		=		-l ncurses
ERROR		=		-W -Wall -Werror -Wextra


all:
	make -C lib/my
	gcc -o $(LOCAL_BIN) $(MAIN) $(NCURSES) -Iinclude -Llib/my -lmy -g3

$(NAME):
	make -C lib/my

unit_tests: re
	gcc -o $(TEST_BIN) -I include $(LIB) $(SRC_TESTS) --coverage -lcriterion

tests_run: unit_tests

clean:
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *~
	rm -rf *#
	make clean -C lib/my

fclean: clean
	rm -rf $(TEST_BIN)
	rm -rf $(LOCAL_BIN)
	make fclean -C lib/my

re: fclean all

run_local: re
	gcc -o $(LOCAL_BIN) $(MAIN) -Iinclude -Llib/my -lmy

gcovr_branch:
	gcovr -b --exclude tests/

gcovr:
	gcovr --exclude tests/
