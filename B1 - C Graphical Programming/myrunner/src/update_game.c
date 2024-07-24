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

void set_position_bg(game_t *game)
{
    sfSprite_setPosition(game->rock[0]->sprite, game->rock[0]->pos);
    sfSprite_setPosition(game->rock[1]->sprite, game->rock[1]->pos);
    sfSprite_setPosition(game->cloud[0]->sprite, game->cloud[0]->pos);
    sfSprite_setPosition(game->cloud[1]->sprite, game->cloud[1]->pos);
    sfSprite_setPosition(game->back[0]->sprite, game->back[0]->pos);
    sfSprite_setPosition(game->back[1]->sprite, game->back[1]->pos);
    sfSprite_setPosition(game->front[0]->sprite, game->front[0]->pos);
    sfSprite_setPosition(game->front[1]->sprite, game->front[1]->pos);
    sfSprite_setPosition(game->tree[0]->sprite, game->tree[0]->pos);
    sfSprite_setPosition(game->tree[1]->sprite, game->tree[1]->pos);
    sfSprite_setPosition(game->ground[0]->sprite, game->ground[0]->pos);
    sfSprite_setPosition(game->ground[1]->sprite, game->ground[1]->pos);
}

void draw_sprite_bg(game_t *game)
{
    sfRenderWindow_drawSprite(game->wind, game->sky->sprite, NULL);
    sfRenderWindow_drawSprite(game->wind, game->rock[0]->sprite, NULL);
    sfRenderWindow_drawSprite(game->wind, game->rock[1]->sprite, NULL);
    sfRenderWindow_drawSprite(game->wind, game->cloud[0]->sprite, NULL);
    sfRenderWindow_drawSprite(game->wind, game->cloud[1]->sprite, NULL);
    sfRenderWindow_drawSprite(game->wind, game->back[0]->sprite, NULL);
    sfRenderWindow_drawSprite(game->wind, game->back[1]->sprite, NULL);
    sfRenderWindow_drawSprite(game->wind, game->front[0]->sprite, NULL);
    sfRenderWindow_drawSprite(game->wind, game->front[1]->sprite, NULL);
    sfRenderWindow_drawSprite(game->wind, game->tree[0]->sprite, NULL);
    sfRenderWindow_drawSprite(game->wind, game->tree[1]->sprite, NULL);
    sfRenderWindow_drawSprite(game->wind, game->ground[0]->sprite, NULL);
    sfRenderWindow_drawSprite(game->wind, game->ground[1]->sprite, NULL);
}

void update_game2(game_t *game)
{
    if (game->level != -1 && game->level != 5)
        sfText_setString(game->score->txt,
            my_strcat(my_strcat("score : \0", to_c(game->points)), "%"));
    else
        sfText_setString(game->score->txt,
            my_strcat("score : \0", to_c(game->points)));
    set_position_bg(game), draw_sprite_bg(game);
    sfRenderWindow_drawText(game->wind, game->score->txt, NULL);
    sfSprite_setTextureRect(game->player->sprite, game->player->rect);
    sfSprite_setPosition(game->player->sprite, game->player->pos);
    sfRenderWindow_drawSprite(game->wind, game->player->sprite, NULL);
    sfSprite_setPosition(game->finish->sprite, game->finish->pos);
    sfRenderWindow_drawSprite(game->wind, game->finish->sprite, NULL);
    parallax_management(game), jump(game, game->player);
    if (game->player->is_jump == 0)
        time_gestion_run(game->player);
    else
        time_gestion_jump(game->player);
    display_enemy(game);
}

void update_game(game_t *game)
{
    sfTime time = sfClock_getElapsedTime(game->clock);
    float seconde = time.microseconds / 1000000.0;
    if (seconde > 0.1)
        game->time += 0.1, sfClock_restart(game->clock);
    if (game->level == -1 || game->level == 5)
        game->points = game->time;
    if (game->level == 1)
        game->points = (game->time * 100) / 22.75;
    if (game->level == 2)
        game->points = (game->time * 100) / 27.15;
    if (game->level == 3)
        game->points = (game->time * 100) / 31.75;
    if (game->level == 4)
        game->points = (game->time * 100) / 59.5;
    update_game2(game);
}

void update_shop(game_t *game)
{
    set_position_bg(game), draw_sprite_bg(game);
    sfSprite_setTextureRect(game->player->sprite, game->player->rect);
    sfSprite_setPosition(game->player->sprite, game->player->pos);
    sfRenderWindow_drawSprite(game->wind, game->player->sprite, NULL);
    sfSprite_setTextureRect(game->skin[0]->sprite, game->skin[0]->rect);
    sfSprite_setPosition(game->skin[0]->sprite, game->skin[0]->pos);
    sfRenderWindow_drawSprite(game->wind, game->skin[0]->sprite, NULL);
    sfSprite_setTextureRect(game->skin[1]->sprite, game->skin[1]->rect);
    sfSprite_setPosition(game->skin[1]->sprite, game->skin[1]->pos);
    sfRenderWindow_drawSprite(game->wind, game->skin[1]->sprite, NULL);
    sfSprite_setTextureRect(game->skin[2]->sprite, game->skin[2]->rect);
    sfSprite_setPosition(game->skin[2]->sprite, game->skin[2]->pos);
    sfRenderWindow_drawSprite(game->wind, game->skin[2]->sprite, NULL);
    sfRenderWindow_drawSprite(game->wind, game->s_level->home->sprite, NULL);
    parallax_management(game), time_gestion_idle(game->skin[0]);
    time_gestion_idle(game->skin[1]), time_gestion_idle(game->skin[2]);
    time_gestion_run(game->player);
}
