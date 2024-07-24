##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## test
##

SRC	=	asc_to_bin.c	\
		open.c			\
		code.c			\
		../lib/lib.c	\
		../lib/library.c\

NAME	=	giantman

$(NAME)	:
		gcc -o $(NAME) $(SRC) -g3

all	:	$(NAME)

clean	:
		rm -f $(NAME)
		find . -name "*~" -type f -delete

fclean	:	clean

re:		fclean all
