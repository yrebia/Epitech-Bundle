/*
** EPITECH PROJECT, 2022
** GAME_MANAGEMENT
** File description:
** Function managing game
*/

#include "../../include/my.h"

int game_management(t_game *game)
{
    if (game->lives <= 0)
        game->lives = 3, game->gamestate = MENU;
    if (game->gamestate == MENU)
        sfRenderWindow_clear(game->window, sfBlack), main_menu(game);
    if (game->gamestate == GAME)
        sfRenderWindow_clear(game->window, sfBlack), defender(game);
    if (game->gamestate == PAUSE)
        game_pause(game);

    return (0);
}
