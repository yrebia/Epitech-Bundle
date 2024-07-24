/*
** EPITECH PROJECT, 2022
** INIT
** File description:
** Function initializing the base
*/

#include "../../include/my.h"

void init(t_game *game)
{
    sfVideoMode v_mode = {1920, 1080, 32};
    game->window = sfRenderWindow_create
    (v_mode, "MyDefender", sfClose | sfResize, NULL);
    sfRenderWindow_setFramerateLimit(game->window, 60);
    game->gamestate = 0;
}
