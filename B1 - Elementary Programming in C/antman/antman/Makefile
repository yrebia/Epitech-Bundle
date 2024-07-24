##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

SRC	=	main.c			\
		file.c			\
		frequence_sort.c\
		tree.c			\
		final_print.c	\
		../lib/lib.c	\
		../lib/library.c

NAME	=	antman

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) -g3

clean:
	rm -f $(NAME)

fclean:	clean
	rm -f $(NAME)

re: fclean all
