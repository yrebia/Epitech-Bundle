/*
** EPITECH PROJECT, 2022
** analyse level menu
** File description:
** analyse level menu
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

void analyse_events_level_menu2(game_t *game)
{
    if (game->event.mouseButton.x <= game->s_level->button[3]->pos.x + 425
        && game->event.mouseButton.x >= game->s_level->button[3]->pos.x &&
        game->event.mouseButton.y <= game->s_level->button[3]->pos.y + 155
        && game->event.mouseButton.y >= game->s_level->button[3]->pos.y)
        sfText_setColor(game->s_level->txt[3]->txt, sfBlue);
    if (game->bonus == -1 && game->event.mouseButton.x <=
        game->s_level->button[4]->pos.x + 425
        && game->event.mouseButton.x >= game->s_level->button[4]->pos.x &&
        game->event.mouseButton.y <= game->s_level->button[4]->pos.y + 155
        && game->event.mouseButton.y >= game->s_level->button[4]->pos.y)
        sfText_setColor(game->s_level->txt[4]->txt, sfBlue);
    if (game->bonus == 1 && game->event.mouseButton.x <=
        game->s_level->button[5]->pos.x + 425
        && game->event.mouseButton.x >= game->s_level->button[5]->pos.x &&
        game->event.mouseButton.y <= game->s_level->button[5]->pos.y + 155
        && game->event.mouseButton.y >= game->s_level->button[5]->pos.y)
        sfText_setColor(game->s_level->txt[5]->txt, sfBlue);
}

void analyse_events_level_menu(game_t *game)
{
    if (game->event.mouseButton.button == sfMouseLeft) {
        if (game->event.mouseButton.x <= game->s_level->button[0]->pos.x + 425
            && game->event.mouseButton.x >= game->s_level->button[0]->pos.x &&
            game->event.mouseButton.y <= game->s_level->button[0]->pos.y + 155
            && game->event.mouseButton.y >= game->s_level->button[0]->pos.y)
            sfText_setColor(game->s_level->txt[0]->txt, sfBlue);
        if (game->event.mouseButton.x <= game->s_level->button[1]->pos.x + 425
            && game->event.mouseButton.x >= game->s_level->button[1]->pos.x &&
            game->event.mouseButton.y <= game->s_level->button[1]->pos.y + 155
            && game->event.mouseButton.y >= game->s_level->button[1]->pos.y)
            sfText_setColor(game->s_level->txt[1]->txt, sfBlue);
        if (game->event.mouseButton.x <= game->s_level->button[2]->pos.x + 425
            && game->event.mouseButton.x >= game->s_level->button[2]->pos.x &&
            game->event.mouseButton.y <= game->s_level->button[2]->pos.y + 155
            && game->event.mouseButton.y >= game->s_level->button[2]->pos.y)
            sfText_setColor(game->s_level->txt[2]->txt, sfBlue);
        analyse_events_level_menu2(game);
    }
}

void analyse_events_level_menu_m3(game_t *game)
{
    if (game->bonus == -1 && game->event.mouseMove.x <=
        game->s_level->button[4]->pos.x + 425
        && game->event.mouseMove.x >= game->s_level->button[4]->pos.x &&
        game->event.mouseMove.y <= game->s_level->button[4]->pos.y + 155
        && game->event.mouseMove.y >= game->s_level->button[4]->pos.y)
        sfText_setColor(game->s_level->txt[4]->txt, sfRed);
    else
        sfText_setColor(game->s_level->txt[4]->txt, sfBlack);
    if (game->bonus == 1 && game->event.mouseMove.x <=
        game->s_level->button[5]->pos.x + 425
        && game->event.mouseMove.x >= game->s_level->button[5]->pos.x &&
        game->event.mouseMove.y <= game->s_level->button[5]->pos.y + 155
        && game->event.mouseMove.y >= game->s_level->button[5]->pos.y)
        sfText_setColor(game->s_level->txt[5]->txt, sfRed);
    else if (game->bonus == 1)
        sfText_setColor(game->s_level->txt[5]->txt, sfBlack);
}

void analyse_events_level_menu_m2(game_t *game)
{
    if (game->event.mouseMove.x <= game->s_level->button[2]->pos.x + 425
        && game->event.mouseMove.x >= game->s_level->button[2]->pos.x &&
        game->event.mouseMove.y <= game->s_level->button[2]->pos.y + 155
        && game->event.mouseMove.y >= game->s_level->button[2]->pos.y)
        sfText_setColor(game->s_level->txt[2]->txt, sfRed);
    else
        sfText_setColor(game->s_level->txt[2]->txt, sfBlack);
    if (game->event.mouseMove.x <= game->s_level->button[3]->pos.x + 425
        && game->event.mouseMove.x >= game->s_level->button[3]->pos.x &&
        game->event.mouseMove.y <= game->s_level->button[3]->pos.y + 155
        && game->event.mouseMove.y >= game->s_level->button[3]->pos.y)
        sfText_setColor(game->s_level->txt[3]->txt, sfRed);
    else
        sfText_setColor(game->s_level->txt[3]->txt, sfBlack);
    analyse_events_level_menu_m3(game);
}

void analyse_events_level_menu_m(game_t *game)
{
    if (game->event.mouseMove.x <= game->s_level->button[0]->pos.x + 425
        && game->event.mouseMove.x >= game->s_level->button[0]->pos.x &&
        game->event.mouseMove.y <= game->s_level->button[0]->pos.y + 155
        && game->event.mouseMove.y >= game->s_level->button[0]->pos.y)
        sfText_setColor(game->s_level->txt[0]->txt, sfRed);
    else
        sfText_setColor(game->s_level->txt[0]->txt, sfBlack);
    if (game->event.mouseMove.x <= game->s_level->button[1]->pos.x + 425
        && game->event.mouseMove.x >= game->s_level->button[1]->pos.x &&
        game->event.mouseMove.y <= game->s_level->button[1]->pos.y + 155
        && game->event.mouseMove.y >= game->s_level->button[1]->pos.y)
        sfText_setColor(game->s_level->txt[1]->txt, sfRed);
    else
        sfText_setColor(game->s_level->txt[1]->txt, sfBlack);
    analyse_events_level_menu_m2(game);
}
