/*
** EPITECH PROJECT, 2021
** update
** File description:
** update
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

void update_menu2(game_t *game)
{
    if (game->sound == 1)
        sfRenderWindow_drawSprite(game->wind, game->s_menu->sound[0]->sprite,
        NULL);
    else
        sfRenderWindow_drawSprite(game->wind, game->s_menu->sound[1]->sprite,
        NULL);
    if (game->screen == 1)
        sfRenderWindow_drawSprite(game->wind, game->s_menu->screen[0]->sprite,
        NULL);
    else
        sfRenderWindow_drawSprite(game->wind, game->s_menu->screen[1]->sprite,
        NULL);
    sfRenderWindow_drawSprite(game->wind, game->s_menu->exit->sprite,
        NULL);
}

void update_menu(game_t *game)
{
    draw_sprite_bg(game);
    sfRenderWindow_drawSprite(game->wind, game->s_menu->button[0]->sprite,
        NULL);
    sfRenderWindow_drawSprite(game->wind, game->s_menu->button[1]->sprite,
        NULL);
    if (game->win != 0)
        sfRenderWindow_drawText(game->wind, game->s_menu->lvl_select->txt,
            NULL);
    else
        sfRenderWindow_drawText(game->wind, game->s_menu->resume->txt, NULL);
    sfRenderWindow_drawText(game->wind, game->s_menu->skin_select->txt, NULL);
    if (game->win == 5)
        sfRenderWindow_drawText(game->wind, game->s_menu->title[0]->txt, NULL);
    if (game->win == 0)
        sfRenderWindow_drawText(game->wind, game->s_menu->title[1]->txt, NULL);
    if (game->win == -1)
        sfRenderWindow_drawText(game->wind, game->s_menu->title[2]->txt, NULL);
    if (game->win == 1)
        sfRenderWindow_drawText(game->wind, game->s_menu->title[3]->txt, NULL);
    update_menu2(game);
}

void draw_text_level_menu(game_t *game)
{
    sfRenderWindow_drawText(game->wind, game->s_level->txt[0]->txt, NULL);
    sfRenderWindow_drawText(game->wind, game->s_level->txt[1]->txt, NULL);
    sfRenderWindow_drawText(game->wind, game->s_level->txt[2]->txt, NULL);
    sfRenderWindow_drawText(game->wind, game->s_level->txt[3]->txt, NULL);
    sfRenderWindow_drawText(game->wind, game->s_level->score[0]->txt, NULL);
    sfRenderWindow_drawText(game->wind, game->s_level->score[1]->txt, NULL);
    sfRenderWindow_drawText(game->wind, game->s_level->score[2]->txt, NULL);
    sfRenderWindow_drawText(game->wind, game->s_level->score[3]->txt, NULL);
}

void update_level_menu(game_t *game)
{
    draw_sprite_bg(game);
    sfRenderWindow_drawSprite(game->wind, game->s_level->home->sprite, NULL);
    sfRenderWindow_drawSprite(game->wind, game->s_level->button[0]->sprite,
        NULL);
    sfRenderWindow_drawSprite(game->wind, game->s_level->button[1]->sprite,
        NULL);
    sfRenderWindow_drawSprite(game->wind, game->s_level->button[2]->sprite,
        NULL);
    sfRenderWindow_drawSprite(game->wind, game->s_level->button[3]->sprite,
        NULL);
    if (game->bonus == -1) {
        sfRenderWindow_drawSprite(game->wind, game->s_level->button[4]->sprite,
            NULL);
        sfRenderWindow_drawText(game->wind, game->s_level->txt[4]->txt, NULL);
    } else if (game->bonus == 1) {
        sfRenderWindow_drawSprite(game->wind, game->s_level->button[5]->sprite,
            NULL);
        sfRenderWindow_drawText(game->wind, game->s_level->txt[5]->txt, NULL);
    }
    draw_text_level_menu(game);
}
