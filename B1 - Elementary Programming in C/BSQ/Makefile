##
## EPITECH PROJECT, 2021
## makefile
## File description:
## make op
##

SRC	=	main.c\
		bsq.c\
		file.c\
		error.c\
		my_putstr.c

NAME	=	bsq

all:	$(NAME)

$(NAME):
	gcc $(SRC) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
