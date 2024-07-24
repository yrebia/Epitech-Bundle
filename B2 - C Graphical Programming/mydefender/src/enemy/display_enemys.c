/*
** EPITECH PROJECT, 2022
** DISPLAY_ENEMYS
** File description:
** Function displaying enemys
*/

#include "../../include/my.h"

void set_life(t_enemy *enemie)
{
    enemie->bg_life->pos = enemie->sprite->pos;
    enemie->life_bar->pos = enemie->sprite->pos;
    enemie->life_bar->pos.x += 2;
    enemie->life_bar->pos.y += 1;
    enemie->life_bar->scale.x = (0.1 * enemie->stats->HP) /
    enemie->stats->HP_max;
    sfSprite_setScale(enemie->life_bar->sprite, enemie->life_bar->scale);
    sfSprite_setTextureRect(enemie->life_bar->sprite, enemie->life_bar->rect);
    if (enemie->stats->HP <= enemie->stats->HP_max * (1. / 3.))
        sfSprite_setColor(enemie->life_bar->sprite, sfRed);
    else if (enemie->stats->HP <= enemie->stats->HP_max * (2. / 3.))
        sfSprite_setColor(enemie->life_bar->sprite,
        sfColor_fromRGB(255, 140, 0));
    else
        sfSprite_setColor(enemie->life_bar->sprite, sfGreen);
}

void display_enemys(t_game *game)
{
    t_enemy *tmp = game->enemys;
    while (tmp != 0) {
        if (tmp->stats->HP <= 0 && tmp->dead != 1)
            tmp->dead = 1, game->money += 50;
        if (tmp->dead != 1) {
            move_enemy(tmp, game);
            set_life(tmp);
            sfSprite_setPosition(tmp->sprite->sprite, tmp->sprite->pos);
            sfRenderWindow_drawSprite(game->window, tmp->sprite->sprite, NULL);
            sfSprite_setPosition(tmp->bg_life->sprite, tmp->bg_life->pos);
            sfRenderWindow_drawSprite
            (game->window, tmp->bg_life->sprite, NULL);
            sfSprite_setPosition(tmp->life_bar->sprite, tmp->life_bar->pos);
            sfRenderWindow_drawSprite
            (game->window, tmp->life_bar->sprite, NULL);
        } tmp = tmp->next;
    }
}
