##
## EPITECH PROJECT, 2021
## makefile
## File description:
## make op
##

SRC	=	src/main.c\
		src/parallax.c\
		src/time_gestion.c\
		src/analyse.c\
		src/analyse_menu.c\
		src/analyse_menu_game.c\
		src/analyse_level_menu.c\
		src/analyse_level.c\
		src/init.c\
		src/init_text.c\
		src/init_menu.c\
		src/init_level.c\
		src/destroy.c\
		src/update_game.c\
		src/game_start_end.c\
		src/update_menu.c\
		src/map.c\
		src/file.c\
		lib/lib.c\
		lib/library.c\

NAME	=	my_runner

FLAGS	=	-lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio -g3

all:	$(NAME)

$(NAME):
	gcc $(SRC) -o $(NAME) $(FLAGS)

clean:
	rm -f

fclean:	clean
	rm -f $(NAME)

re:	fclean all
