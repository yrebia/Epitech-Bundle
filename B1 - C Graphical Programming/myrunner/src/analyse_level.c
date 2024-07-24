/*
** EPITECH PROJECT, 2022
** analyse level
** File description:
** analyse level
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

void analyse_events_level_menu_r4(game_t *game)
{
    if (game->event.mouseButton.x <= game->s_level->home->pos.x + 200
        && game->event.mouseButton.x >= game->s_level->home->pos.x &&
        game->event.mouseButton.y <= game->s_level->home->pos.y + 200
        && game->event.mouseButton.y >= game->s_level->home->pos.y)
        game->level_menu = 0, game->menu = 1;
}

void analyse_events_level_menu_r3(game_t *game)
{
    if (game->bonus == -1 && game->event.mouseButton.x <=
        game->s_level->button[4]->pos.x + 425
        && game->event.mouseButton.x >= game->s_level->button[4]->pos.x &&
        game->event.mouseButton.y <= game->s_level->button[4]->pos.y + 155
        && game->event.mouseButton.y >= game->s_level->button[4]->pos.y) {
        sfText_setColor(game->s_level->txt[4]->txt, sfBlack);
        game->level = -1, start_game(game);
    }
    if (game->bonus == 1 && game->event.mouseButton.x <=
        game->s_level->button[5]->pos.x + 425
        && game->event.mouseButton.x >= game->s_level->button[5]->pos.x &&
        game->event.mouseButton.y <= game->s_level->button[5]->pos.y + 155
        && game->event.mouseButton.y >= game->s_level->button[5]->pos.y) {
        sfText_setColor(game->s_level->txt[5]->txt, sfBlack);
        game->level = 5, start_game(game);
    }
    analyse_events_level_menu_r4(game);
}

void analyse_events_level_menu_r2(game_t *game)
{
    if (game->event.mouseButton.x <= game->s_level->button[2]->pos.x + 425
            && game->event.mouseButton.x >= game->s_level->button[2]->pos.x &&
            game->event.mouseButton.y <= game->s_level->button[2]->pos.y + 155
            && game->event.mouseButton.y >= game->s_level->button[2]->pos.y) {
            sfText_setColor(game->s_level->txt[2]->txt, sfBlack);
            game->level = 3, start_game(game);
    }
    if (game->event.mouseButton.x <= game->s_level->button[3]->pos.x + 425
        && game->event.mouseButton.x >= game->s_level->button[3]->pos.x &&
        game->event.mouseButton.y <= game->s_level->button[3]->pos.y + 155
        && game->event.mouseButton.y >= game->s_level->button[3]->pos.y) {
        sfText_setColor(game->s_level->txt[3]->txt, sfBlack);
        game->level = 4, start_game(game);
    }
    analyse_events_level_menu_r3(game);
}

void analyse_events_level_menu_r(game_t *game)
{
    if (game->event.mouseButton.button == sfMouseLeft) {
        if (game->event.mouseButton.x <= game->s_level->button[0]->pos.x + 425
            && game->event.mouseButton.x >= game->s_level->button[0]->pos.x &&
            game->event.mouseButton.y <= game->s_level->button[0]->pos.y + 155
            && game->event.mouseButton.y >= game->s_level->button[0]->pos.y) {
            sfText_setColor(game->s_level->txt[0]->txt, sfBlack);
            game->level = 1, start_game(game);
        }
        if (game->event.mouseButton.x <= game->s_level->button[1]->pos.x + 425
            && game->event.mouseButton.x >= game->s_level->button[1]->pos.x &&
            game->event.mouseButton.y <= game->s_level->button[1]->pos.y + 155
            && game->event.mouseButton.y >= game->s_level->button[1]->pos.y) {
            sfText_setColor(game->s_level->txt[1]->txt, sfBlack);
            game->level = 2, start_game(game);
        }
        analyse_events_level_menu_r2(game);
    }
}
