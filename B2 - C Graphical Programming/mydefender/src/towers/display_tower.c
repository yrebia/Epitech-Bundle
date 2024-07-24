/*
** EPITECH PROJECT, 2022
** DISPLAY_TOWER
** File description:
** Function displaying towers
*/

#include "../../include/my.h"

void display_towers(t_game *game)
{
    t_tower *tmp = game->towers;
    while (tmp != 0) {
        sfTime time = sfClock_getElapsedTime(tmp->sprite->animation);
        float sec = time.microseconds / 1000000.0;
        if (sec > tmp->stats->ATKSPD) {
            init_bullet(game, tmp); sfClock_restart(tmp->sprite->animation);
        }
        if (tmp->target != 0) {
            float ac = tmp->sprite->pos.x - tmp->target->sprite->pos.x;
            float ab = tmp->target->sprite->pos.y - tmp->sprite->pos.y;
            double angle = atan(ac / ab); angle = angle * 180 / M_PI;
            (tmp->target->sprite->pos.y >= tmp->sprite->pos.y) ?
            angle += 180 : 0;
            sfSprite_setRotation(tmp->sprite->sprite, angle);
        }
        sfRenderWindow_drawSprite(game->window, tmp->sprite->sprite, NULL);
        tmp = tmp->next;
    }
}
