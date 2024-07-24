/*
** EPITECH PROJECT, 2022
** analyse menu
** File description:
** analyse menu
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

void analyse_events_menu_m2(game_t *game)
{
    if (game->event.mouseMove.x <= game->s_menu->button[0]->pos.x + 425
        && game->event.mouseMove.x >= game->s_menu->button[0]->pos.x &&
        game->event.mouseMove.y <= game->s_menu->button[0]->pos.y + 155
        && game->event.mouseMove.y >= game->s_menu->button[0]->pos.y)
        sfText_setColor(game->s_menu->skin_select->txt, sfRed);
    else
        sfText_setColor(game->s_menu->skin_select->txt, sfBlack);
}

void analyse_events_menu_m(game_t *game)
{
    if (game->win != 0 && game->event.mouseMove.x <=
        game->s_menu->button[1]->pos.x + 425
        && game->event.mouseMove.x >= game->s_menu->button[1]->pos.x &&
        game->event.mouseMove.y <= game->s_menu->button[1]->pos.y + 155
        && game->event.mouseMove.y >= game->s_menu->button[1]->pos.y)
        sfText_setColor(game->s_menu->lvl_select->txt, sfRed);
    else
        sfText_setColor(game->s_menu->lvl_select->txt, sfBlack);
    if (game->win == 0 && game->event.mouseMove.x <=
        game->s_menu->button[1]->pos.x + 425
        && game->event.mouseMove.x >= game->s_menu->button[1]->pos.x &&
        game->event.mouseMove.y <= game->s_menu->button[1]->pos.y + 155
        && game->event.mouseMove.y >= game->s_menu->button[1]->pos.y)
        sfText_setColor(game->s_menu->resume->txt, sfRed);
    else
        sfText_setColor(game->s_menu->resume->txt, sfBlack);
    analyse_events_menu_m2(game);
}

void analyse_events_menu2(game_t *game)
{
    if (game->event.mouseButton.x <= game->s_menu->exit->pos.x + 100
        && game->event.mouseButton.x >= game->s_menu->exit->pos.x &&
        game->event.mouseButton.y <= game->s_menu->exit->pos.y + 100
        && game->event.mouseButton.y >= game->s_menu->exit->pos.y)
        sfRenderWindow_close(game->wind);
}

void analyse_events_menu(game_t *game)
{
    if (game->event.mouseButton.button == sfMouseLeft) {
        if (game->win != 0 && game->event.mouseButton.x <=
            game->s_menu->button[1]->pos.x + 425
            && game->event.mouseButton.x >= game->s_menu->button[1]->pos.x &&
            game->event.mouseButton.y <= game->s_menu->button[1]->pos.y + 155
            && game->event.mouseButton.y >= game->s_menu->button[1]->pos.y)
            sfText_setColor(game->s_menu->lvl_select->txt, sfBlue);
        if (game->win == 0 && game->event.mouseButton.x <=
            game->s_menu->button[1]->pos.x + 425
            && game->event.mouseButton.x >= game->s_menu->button[1]->pos.x &&
            game->event.mouseButton.y <= game->s_menu->button[1]->pos.y + 155
            && game->event.mouseButton.y >= game->s_menu->button[1]->pos.y)
            sfText_setColor(game->s_menu->resume->txt, sfBlue);
        if (game->event.mouseButton.x <= game->s_menu->button[0]->pos.x + 425
            && game->event.mouseButton.x >= game->s_menu->button[0]->pos.x &&
            game->event.mouseButton.y <= game->s_menu->button[0]->pos.y + 155
            && game->event.mouseButton.y >= game->s_menu->button[0]->pos.y)
            sfText_setColor(game->s_menu->skin_select->txt, sfBlue);
        analyse_events_menu2(game);
    }
}
