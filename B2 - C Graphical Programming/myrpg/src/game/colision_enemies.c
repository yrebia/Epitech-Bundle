/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** Create Game
*/

#include "../../include/mystruct.h"

int colision(sprite_t *player, sprite_t *enemie)
{
    if (sqrt(pow(enemie->pos.x - player->pos.x, 2) + pow(enemie->pos.y -
        player->pos.y, 2)) < 45)
        return (1);
    return (0);
}

void colision_enemies(rpg_t *rpg)
{
    enemie_t *tmp = rpg->enemies;
    while (tmp != NULL) {
        if (colision(rpg->player, tmp->sprite) == 1 && tmp->touched == 0 &&
            tmp->stat->hp > 0 && tmp->map == rpg->bg->map) {
            rpg->player->hp -= tmp->stat->atk;
            tmp->touched = 1, sfClock_restart(tmp->clock);
            tmp->stat->vel_x *= -1, tmp->stat->vel_y *= -1;
        }
        tmp = tmp->next;
    }
}

void display_enemies(rpg_t *rpg)
{
    enemie_t *tmp = rpg->enemies;
    while (tmp != NULL) {
        if (tmp->map == rpg->bg->map && tmp->stat->hp > 0)
            sfRenderWindow_drawSprite(rpg->window, tmp->sprite->sprite, NULL);
        tmp = tmp->next;
    }
}
