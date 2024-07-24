/*
** EPITECH PROJECT, 2022
** analyse menu and game
** File description:
** analyse menu and game
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

void analyse_events_menu_r4(game_t *game)
{
    if (game->win == 0 && game->event.mouseButton.x <=
        game->s_menu->button[1]->pos.x + 425
        && game->event.mouseButton.x >= game->s_menu->button[1]->pos.x &&
        game->event.mouseButton.y <= game->s_menu->button[1]->pos.y + 155
        && game->event.mouseButton.y >= game->s_menu->button[1]->pos.y) {
        sfText_setColor(game->s_menu->resume->txt, sfBlack), game->menu = 0;
        game->play = 1;
    }
}

void analyse_events_menu_r3(game_t *game)
{
    if (game->sound == 0 && game->event.mouseButton.x <=
        game->s_menu->sound[0]->pos.x + 100
        && game->event.mouseButton.x >= game->s_menu->sound[0]->pos.x &&
        game->event.mouseButton.y <= game->s_menu->sound[0]->pos.y + 100
        && game->event.mouseButton.y >= game->s_menu->sound[0]->pos.y) {
        game->sound = 1, sfMusic_setVolume(game->music, 50);
        sfMusic_setVolume(game->jump, 100), sfMusic_setVolume(game->dead, 100);
        sfMusic_setVolume(game->win_sfx, 100);
    } else if (game->sound == 1 && game->event.mouseButton.x <=
        game->s_menu->sound[1]->pos.x + 100
        && game->event.mouseButton.x >= game->s_menu->sound[1]->pos.x &&
        game->event.mouseButton.y <= game->s_menu->sound[1]->pos.y + 100
        && game->event.mouseButton.y >= game->s_menu->sound[1]->pos.y) {
        game->sound = 0, sfMusic_setVolume(game->music, 0);
        sfMusic_setVolume(game->jump, 0), sfMusic_setVolume(game->dead, 0);
        sfMusic_setVolume(game->win_sfx, 0);
    }
    analyse_events_menu_r4(game);
}

void analyse_events_menu_r2(game_t *game)
{
    if (game->screen == 1 && game->event.mouseButton.x <=
        game->s_menu->screen[0]->pos.x + 100
        && game->event.mouseButton.x >= game->s_menu->screen[0]->pos.x &&
        game->event.mouseButton.y <= game->s_menu->screen[0]->pos.y + 100
        && game->event.mouseButton.y >= game->s_menu->screen[0]->pos.y) {
        game->screen = 0;
        sfVideoMode v_mode = {1920, 1080, 32};
        sfRenderWindow_destroy(game->wind);
        game->wind = sfRenderWindow_create(v_mode, "MyRunner", sfClose, NULL);
        sfRenderWindow_setFramerateLimit(game->wind, 30);
    } else if (game->screen == 0 && game->event.mouseButton.x <=
        game->s_menu->screen[1]->pos.x + 100
        && game->event.mouseButton.x >= game->s_menu->screen[1]->pos.x &&
        game->event.mouseButton.y <= game->s_menu->screen[1]->pos.y + 100
        && game->event.mouseButton.y >= game->s_menu->screen[1]->pos.y) {
        game->screen = 1;
        sfVideoMode v_mode = {1920, 1080, 32};
        sfRenderWindow_destroy(game->wind);
        game->wind = sfRenderWindow_create(v_mode, "MyRunner", sfClose |
            sfFullscreen, NULL);
        sfRenderWindow_setFramerateLimit(game->wind, 30);
    }
    analyse_events_menu_r3(game);
}

void analyse_events_menu_r(game_t *game)
{
    if (game->event.mouseButton.button == sfMouseLeft) {
        if (game->event.mouseButton.x <= game->s_menu->button[0]->pos.x + 425
            && game->event.mouseButton.x >= game->s_menu->button[0]->pos.x &&
            game->event.mouseButton.y <= game->s_menu->button[0]->pos.y + 155
            && game->event.mouseButton.y >= game->s_menu->button[0]->pos.y) {
            sfText_setColor(game->s_menu->skin_select->txt, sfBlack);
            game->menu = 0, game->shop = 1;
        }
        if (game->win != 0 && game->event.mouseButton.x <=
            game->s_menu->button[1]->pos.x + 425
            && game->event.mouseButton.x >= game->s_menu->button[1]->pos.x &&
            game->event.mouseButton.y <= game->s_menu->button[1]->pos.y + 155
            && game->event.mouseButton.y >= game->s_menu->button[1]->pos.y) {
            sfText_setColor(game->s_menu->lvl_select->txt, sfBlack);
            game->menu = 0, game->level_menu = 1;
        }
        analyse_events_menu_r2(game);
    }
}

void analyse_events_game(game_t *game)
{
    if (game->event.key.code == sfKeySpace && game->player->is_jump == 0) {
        game->player->is_jump = 1, game->player->offset = 0;
        sfMusic_stop(game->jump), sfMusic_play(game->jump);
        sfClock_restart(game->player->clock);
        if (game->activ_skin == 0)
            change_skin(game, "asset/player1/jump.png");
        if (game->activ_skin == 1)
            change_skin(game, "asset/player2/jump.png");
        if (game->activ_skin == 2)
            change_skin(game, "asset/player3/jump.png");
    }
}
