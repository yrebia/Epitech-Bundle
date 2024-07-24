/*
** EPITECH PROJECT, 2022
** ANIMATE_ENEMY
** File description:
** Function animating the enemys
*/

#include "../../include/my.h"

void animate_enemy(t_enemy *enemys)
{
    int max = 72;

    while (enemys) {
        enemys->sprite->time =
        sfClock_getElapsedTime(enemys->sprite->animation);
        enemys->sprite->seconds =
        enemys->sprite->time.microseconds / 1000000.0;
        if (enemys->sprite->seconds > 0.25) {
            (enemys->sprite->rect.left >= max) ?
                enemys->sprite->rect.left = 0 : 0;
            (!(enemys->sprite->rect.left >= max)) ?
                enemys->sprite->rect.left += 24 : 0;
            sfClock_restart(enemys->sprite->animation);
        }
        sfSprite_setTextureRect(enemys->sprite->sprite, enemys->sprite->rect);
        enemys = enemys->next;
    }
}
