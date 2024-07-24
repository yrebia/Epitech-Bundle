/*
** EPITECH PROJECT, 2022
** DISPLAY_BULLETS
** File description:
** Functions displaying bullets
*/

#include "../../include/my.h"

void display_bullets1(t_game *game, t_bullet *tmp, float angle)
{
    angle = atan2(tmp->target->sprite->pos.y -
    (tmp->sprite->pos.y - 18),
    tmp->target->sprite->pos.x - (tmp->sprite->pos.x - 18));
    tmp->sprite->velocity.x = cos(angle) * 4;
    tmp->sprite->velocity.y = sin(angle) * 4;
    tmp->sprite->pos.x += tmp->sprite->velocity.x;
    tmp->sprite->pos.y += tmp->sprite->velocity.y;
    sfSprite_setPosition(tmp->sprite->sprite, tmp->sprite->pos);
    sfRenderWindow_drawSprite(game->window, tmp->sprite->sprite, NULL);
}

void display_bullets(t_game *game)
{
    t_bullet *tmp = game->bullets; float angle = 0;
    while (tmp != 0) {
        if (tmp->touched != 1 && sqrt(pow(tmp->sprite->pos.x -
        tmp->target->sprite->pos.x, 2) + pow(tmp->sprite->pos.y -
        tmp->target->sprite->pos.y, 2)) < 50)
            tmp->touched = 1, tmp->target->stats->HP -= tmp->stats->ATK;
        else if (tmp->touched != 1) {
            display_bullets1(game, tmp, angle);
        }
        tmp = tmp->next;
    }
}
