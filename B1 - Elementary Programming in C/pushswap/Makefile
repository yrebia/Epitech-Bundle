##
## EPITECH PROJECT, 2021
## makefile
## File description:
## make ls
##

SRC	=	main.c\
		lib.c\
		calculator.c\
		option.c

NAME	=	push_swap

all:	$(NAME)

$(NAME):
	gcc $(SRC) -o $(NAME) -g3

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
