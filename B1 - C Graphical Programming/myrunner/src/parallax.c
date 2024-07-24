/*
** EPITECH PROJECT, 2021
** parallax
** File description:
** parallax
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

void parallax(image_t *image1, image_t *image2)
{
    image1->pos.x += image1->velocity.x;
    image2->pos.x += image2->velocity.x;
    if (image1->pos.x <= -1920)
        image1->pos.x = 1920;
    if (image2->pos.x <= -1920)
        image2->pos.x = 1920;
}

void restart_skin(game_t *game)
{
    if (game->activ_skin == 0)
        change_skin(game, "asset/player1/run.png");
    if (game->activ_skin == 1)
        change_skin(game, "asset/player2/run.png");
    if (game->activ_skin == 2)
        change_skin(game, "asset/player3/run.png");
}

void fall(game_t *game, image_t *player)
{
    sfTime time = sfClock_getElapsedTime(player->j_clock);
    float seconds = time.microseconds / 1000000.0;
    if (seconds < 0.15)
        player->pos.y += 5;
    else if (seconds < 0.35)
        player->pos.y += 10;
    else
        player->pos.y += 20;
    if (player->pos.y >= 715) {
        sfClock_restart(player->j_clock), player->is_jump = 0;
        restart_skin(game);
    }
}

void jump(game_t *game, image_t *player)
{
    if (player->is_jump == 0)
        sfClock_restart(player->j_clock);
    if (player->is_jump == 1) {
        sfTime time = sfClock_getElapsedTime(player->j_clock);
        float seconds = time.microseconds / 1000000.0;
        if (seconds < 0.15)
            player->pos.y -= 25;
        else if (seconds < 0.35)
            player->pos.y -= 12.5;
        else
            player->pos.y -= 5;
        if (seconds > 0.45)
            sfClock_restart(player->j_clock), player->is_jump = -1;
    }
    if (player->is_jump == -1)
    fall(game, player);
}

void parallax_management(game_t *game)
{
    parallax(game->rock[0], game->rock[1]);
    parallax(game->cloud[0], game->cloud[1]);
    parallax(game->back[0], game->back[1]);
    parallax(game->front[0], game->front[1]);
    parallax(game->tree[0], game->tree[1]);
    parallax(game->ground[0], game->ground[1]);
}
