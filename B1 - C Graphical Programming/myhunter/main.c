/*
** EPITECH PROJECT, 2021
** hunter
** File description:
** hunter
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Export.h>
#include <SFML/System/Time.h>
#include <SFML/Window/Event.h>
#include <SFML/Audio.h>
#include <stddef.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

void analyse_events(game_t *game)
{
    if (game->event.type == sfEvtClosed)
        sfRenderWindow_close(game->wind);
    if (game->event.type == sfEvtMouseMoved && game->playing == 1) {
        game->viseur->pos.x = game->event.mouseMove.x - 30;
        game->viseur->pos.y = game->event.mouseMove.y - 30;
    }
    if (game->event.type == sfEvtMouseButtonPressed && game->playing == 1)
        manage_mouse_click(game);
    if (game->event.type == sfEvtMouseButtonPressed && game->menu == 1) {
        manage_mouse_menu(game);
    }
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        game->playing = 0, game->menu = 1;
}

void playing(game_t *game)
{
    sfRenderWindow_setMouseCursorVisible(game->wind, sfFalse);
    game->shot2->rect.width = 8 * game->bullet;
    update_game(game);
    time_gestion(game, game->duck);
    time_gestion(game, game->duck2);
    time_gestion(game, game->duck3);
    if (game->goal2->rect.width > 105)
        level_up(game);
    if (game->bullet == 0)
        game_over(game);
}

void launch_game(game_t *game)
{
    game->menu = 0, game->playing = 1, game->txt_bst->pos.x = 770;
    game->txt_bst->pos.y = 830, game->score->pos.x = 770;
    game->score->pos.y = 860, game->bullet = 3;
}

int main(int ac, char **av)
{
    char *rules = read_file("txt/rules.txt");
    if (ac > 1 && my_strcmp(av[1], "-h") == 0)
        write(1, rules, my_strlen(rules)), exit(0);
    game_t game;
    menu_t menu;
    set_struct(&game), set_menu(&menu);
    if (!game.wind)
        return 84;
    while (sfRenderWindow_isOpen(game.wind)) {
        while (sfRenderWindow_pollEvent(game.wind, &game.event))
            analyse_events(&game);
        if (game.menu == 1)
            menuing(&game, &menu);
        if (game.playing == 1)
            playing(&game);
        sfRenderWindow_display(game.wind);
    }
    destroy(&game);
    return (0);
}
