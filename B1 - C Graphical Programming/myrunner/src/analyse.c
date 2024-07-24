/*
** EPITECH PROJECT, 2021
** analyse
** File description:
** analyse
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
#include "../include/my.h"

void analyse_events_shop_r(game_t *game)
{
    if (game->event.mouseButton.x <= game->s_level->home->pos.x + 200
        && game->event.mouseButton.x >= game->s_level->home->pos.x &&
        game->event.mouseButton.y <= game->s_level->home->pos.y + 200
        && game->event.mouseButton.y >= game->s_level->home->pos.y)
        game->shop = 0, game->menu = 1;
}

void analyse_events_shop(game_t *game)
{
    if (game->event.mouseButton.button == sfMouseLeft) {
        if (game->event.mouseButton.x <= game->skin[0]->pos.x + 160 &&
            game->event.mouseButton.x >= game->skin[0]->pos.x &&
            game->event.mouseButton.y <= game->skin[0]->pos.y + 160 &&
            game->event.mouseButton.y >= game->skin[0]->pos.y)
            game->activ_skin = 0, change_skin(game, "asset/player1/run.png");
        if (game->event.mouseButton.x <= game->skin[1]->pos.x + 160 &&
            game->event.mouseButton.x >= game->skin[1]->pos.x &&
            game->event.mouseButton.y <= game->skin[1]->pos.y + 160 &&
            game->event.mouseButton.y >= game->skin[1]->pos.y)
            game->activ_skin = 1, change_skin(game, "asset/player2/run.png");
        if (game->event.mouseButton.x <= game->skin[2]->pos.x + 160 &&
            game->event.mouseButton.x >= game->skin[2]->pos.x &&
            game->event.mouseButton.y <= game->skin[2]->pos.y + 160 &&
            game->event.mouseButton.y >= game->skin[2]->pos.y)
            game->activ_skin = 2, change_skin(game, "asset/player3/run.png");
    }
}

void analyse_events2(game_t *game)
{
    if (game->event.type == sfEvtClosed)
        sfRenderWindow_close(game->wind);
    if (game->event.type == sfEvtMouseButtonPressed && game->shop == 1)
        analyse_events_shop(game);
    if (game->event.type == sfEvtMouseButtonReleased && game->shop == 1)
        analyse_events_shop_r(game);
    if (game->event.type == sfEvtMouseButtonPressed && game->play == 1)
        analyse_events_game(game);
    if (game->event.type == sfEvtKeyPressed && game->play == 1)
        analyse_events_game(game);
    if (game->event.type == sfEvtMouseButtonPressed && game->menu == 1)
        analyse_events_menu(game);
    if (game->event.type == sfEvtMouseButtonReleased && game->menu == 1)
        analyse_events_menu_r(game);
    if (game->event.type == sfEvtMouseMoved && game->menu == 1)
        analyse_events_menu_m(game);
    if (game->event.type == sfEvtMouseButtonPressed && game->level_menu == 1)
        analyse_events_level_menu(game);
    if (game->event.type == sfEvtMouseMoved && game->level_menu == 1)
        analyse_events_level_menu_m(game);
}

void analyse_events(game_t *game)
{
    analyse_events2(game);
    if (game->event.type == sfEvtMouseButtonReleased && game->level_menu == 1)
        analyse_events_level_menu_r(game);
    if (game->event.type == sfEvtKeyPressed && game->event.key.code ==
        sfKeyEscape) {
        game->play = 0, game->shop = 0, game->menu = 1;
        game->level_menu = 0;
    }
}
