##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile
##

SRC	=	src/*.c							\
		src/menu/text/*.c				\
		src/pollevent/*.c				\
		src/pollevent/button_state/*.c  \
		src/update/*.c					\
		src/menu/*.c					\
		src/initialisation/*.c			\
		src/game/*.c					\
		src/librairy/*.c 				\

NAME	=	my_rpg

$(NAME)	:
		gcc -o $(NAME) $(SRC) -l csfml-graphics -l csfml-system -l csfml-audio \
		-Wall -g3 -lm

all	:	$(NAME) msg

clean	:
		rm -f $(NAME)
		find . -name "*~" -type f -delete

fclean	:	clean

re:		fclean all

msg:
	@echo -e "\e[1;32m===Compilation Completed Have Fun ;) !===$<\e[0m"
