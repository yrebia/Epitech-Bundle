/*
** EPITECH PROJECT, 2021
** time gestion
** File description:
** time gestion
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

void time_gestion_run(image_t *player)
{
    sfTime time = sfClock_getElapsedTime(player->clock);
    float seconds = time.microseconds / 1000000.0;
    if (seconds > 0.125) {
        player->rect.left = player->offset * 32;
        sfClock_restart(player->clock);
        if (player->offset == 5)
            player->offset = 0;
        player->offset += 1;
    }
}

void time_gestion_jump(image_t *player)
{
    sfTime time = sfClock_getElapsedTime(player->clock);
    float seconds = time.microseconds / 1000000.0;
    if (seconds > 0.3) {
        player->rect.left = player->offset * 32;
        sfClock_restart(player->clock);
        player->offset += 1;
    }
}

void time_gestion_idle(image_t *player)
{
    sfTime time = sfClock_getElapsedTime(player->clock);
    float seconds = time.microseconds / 1000000.0;
    if (seconds > 0.25) {
        player->rect.left = player->offset * 32;
        sfClock_restart(player->clock);
        if (player->offset == 3)
            player->offset = 0;
        player->offset += 1;
    }
}

void time_gestion_enemy(image_t *enemy, game_t *game)
{
    enemy->pos.x += enemy->velocity.x;
    if (enemy->pos.x < -150 && game->level == -1)
        enemy->pos.x = 2000, enemy->velocity.x -= 0.5;
    sfTime time = sfClock_getElapsedTime(enemy->clock);
    float seconds = time.microseconds / 1000000.0;
    if (seconds > 0.1) {
        enemy->rect.left = enemy->offset * 24 + 408;
        sfClock_restart(enemy->clock);
        if (enemy->offset == 6)
            enemy->offset = 0;
        enemy->offset += 1;
    }
}
