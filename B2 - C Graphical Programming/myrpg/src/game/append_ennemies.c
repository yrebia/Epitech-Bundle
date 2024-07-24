/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** Append Ennemies
*/

#include "../../include/mystruct.h"

void append_enemies(rpg_t *rpg, int x, int y, int map)
{
    sprite_t *enemie = malloc(sizeof(sprite_t));
    enemie->texture = sfTexture_createFromFile("assets/enemies.png", NULL);
    enemie->sprite = sfSprite_create();
    sfSprite_setTexture(enemie->sprite, enemie->texture, sfTrue);
    enemie->pos.x = x * 25 * 3, enemie->pos.y = y * 25 * 3;
    sfSprite_setPosition(enemie->sprite, enemie->pos);
    stat_t *stat = malloc(sizeof(stat_t));
    if (rpg->map[y][x] == 'S') {
        enemie->scale.x = 2, enemie->scale.y = 2;
        rpg->map[y][x] = ' ', enemie->rect.top = 0, enemie->rect.left = 0;
        enemie->rect.width = 16, enemie->rect.height = 16, stat->atk = 10;
        stat->hp = 100, stat->range = 250, stat->vel = 2.5;
    }
    if (rpg->map[y][x] == 'O') {
        enemie->scale.x = 4, enemie->scale.y = 4, rpg->map[y][x] = ' ';
        enemie->rect.top = 290, enemie->rect.left = 192;
        enemie->rect.width = 16, enemie->rect.height = 16, stat->atk = 25;
        stat->hp = 100, stat->range = 200, stat->vel = 1.5;
    }
    if (rpg->map[y][x] == 'L') {
        enemie->scale.x = 3, enemie->scale.y = 3, rpg->map[y][x] = ' ';
        enemie->rect.top = 386, enemie->rect.left = 0, enemie->rect.width = 16;
        enemie->rect.height = 16, stat->atk = 10, stat->hp = 100, stat->range = 250;
        stat->vel = 2.5;
    }
    sfSprite_setScale(enemie->sprite, enemie->scale);
    sfSprite_setTextureRect(enemie->sprite, enemie->rect);
    enemie_t *tmp = malloc(sizeof(enemie_t));
    tmp->map = map, tmp->touched = 0, tmp->clock = sfClock_create();
    tmp->sprite = enemie, tmp->stat = stat;
    tmp->target = NULL, tmp->next = rpg->enemies, rpg->enemies = tmp;
}
