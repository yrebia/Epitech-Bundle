##
## EPITECH PROJECT, 2022
## MAKEFILE
## File description:
## Makefile for MyDefender
##

NAME	=	my_defender

SRC 	=	src/main.c				\
		src/random.c				\
		src/generate_map.c			\
		src/stats.c				\
		src/analyse/analyse_events.c		\
		src/analyse/analyse_game.c		\
		src/analyse/analyse_menu.c		\
		src/analyse/analyse_option.c		\
		src/analyse/analyse_play.c		\
		src/analyse/analyse_towers.c		\
		src/bullets/create_bullets.c		\
		src/bullets/display_bullets.c		\
		src/creation/creation_one.c		\
		src/creation/creation_two.c		\
		src/enemy/animate_enemy.c		\
		src/enemy/create_enemy.c		\
		src/enemy/display_enemys.c		\
		src/enemy/pathfinding.c			\
		src/init/init_bullet.c			\
		src/init/init_description.c		\
		src/init/init_game.c			\
		src/init/init_music_sfx.c		\
		src/init/init_menu.c			\
		src/init/init_option.c			\
		src/init/init_pause.c			\
		src/init/init_tower_menu.c		\
		src/init/init.c				\
		src/music_sfx/destroy_music_sfx.c	\
		src/game_management/defender.c		\
		src/game_management/game_management.c	\
		src/game_management/menu.c		\
		src/game_management/pause.c		\
		src/towers/create_tower.c		\
		src/towers/display_tower.c		\

OBJ	=	$(SRC:.c=.o)

LIBNAME	=	libmy.a

LIBSRC	=	lib/my_strcmp.c		\
		lib/my_strlen.c		\
		lib/my_putstr.c		\
		lib/my_int_to_str.c	\

LIBOBJ	=	$(LIBSRC:.c=.o)

RM	=	rm -rf

CFLAGS	=	-lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio -lm \
		-Wall -Wextra

$(NAME)	:	$(OBJ) $(LIBOBJ)
		ar rc $(LIBNAME) $(LIBOBJ)
		cc -o $(NAME) $(SRC) $(LIBSRC) $(CFLAGS)

all	:	$(NAME)

clean	:
		$(RM) $(OBJ) $(LIBOBJ) $(LIBNAME) *~ *# vgcore*

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all
