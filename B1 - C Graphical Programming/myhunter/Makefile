##
## EPITECH PROJECT, 2021
## makefile
## File description:
## make op
##

SRC	=	main.c\
		init.c\
		init_struct.c\
		init_menu.c\
		lib.c\
		file.c\
		game.c\
		update_game.c\
		menu.c

NAME	=	my_hunter

FLAGS	=	-lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio

all:	$(NAME)

$(NAME):
	gcc $(SRC) -o $(NAME) $(FLAGS)

clean:
	rm -f

fclean:	clean
	rm -f $(NAME)

re:	fclean all
