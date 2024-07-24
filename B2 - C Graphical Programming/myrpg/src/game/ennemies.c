/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** Ennemies
*/

#include "../../include/mystruct.h"

void dist_player_enemies(rpg_t *rpg, enemie_t *enemie)
{
    sfVector2f pos = sfSprite_getPosition(rpg->player->sprite);
    sfVector2f enemie_pos = sfSprite_getPosition(enemie->sprite->sprite);
    if (pos.x > enemie_pos.x - enemie->stat->range &&
    pos.x < enemie_pos.x + enemie->stat->range &&
    pos.y > enemie_pos.y - enemie->stat->range &&
    pos.y < enemie_pos.y + enemie->stat->range)
        enemie->target = rpg->player;
    else
        enemie->target = NULL;
}

void move_enemie2(rpg_t *rpg, enemie_t *enemie)
{
    sfVector2f pos = sfSprite_getPosition(enemie->sprite->sprite);
    sfVector2f target_pos = sfSprite_getPosition(enemie->target->sprite);
    int x = pos.x / 25 / 3;
    int y = pos.y / 25 / 3;
    if (pos.x > target_pos.x && rpg->map[y][x - 1] != 'X' &&
        rpg->map[y][x - 1] != '.')
        enemie->stat->vel_x = -enemie->stat->vel;
    else if (pos.x < target_pos.x && rpg->map[y][x + 1] != 'X' &&
        rpg->map[y][x + 1] != '.')
        enemie->stat->vel_x = enemie->stat->vel;
    if (pos.y > target_pos.y && rpg->map[y - 1][x] != 'X' &&
        rpg->map[y - 1][x] != '.')
        enemie->stat->vel_y = -enemie->stat->vel;
    else if (pos.y < target_pos.y && rpg->map[y + 1][x] != 'X' &&
        rpg->map[y + 1][x] != '.')
        enemie->stat->vel_y = enemie->stat->vel;
    enemie->sprite->pos.x += enemie->stat->vel_x;
    enemie->sprite->pos.y += enemie->stat->vel_y;
    sfSprite_setPosition(enemie->sprite->sprite, enemie->sprite->pos);
}

void move_enemie(rpg_t *rpg, enemie_t *enemie)
{
    sfVector2f pos = sfSprite_getPosition(enemie->sprite->sprite);
    sfVector2f player_pos = sfSprite_getPosition(rpg->player->sprite);
    if (player_pos.x < pos.x - enemie->stat->range || player_pos.x > pos.x +
        enemie->stat->range || player_pos.y < pos.y - enemie->stat->range ||
        player_pos.y > pos.y + enemie->stat->range) {
        enemie->target = NULL;
        return;
    }
    move_enemie2(rpg, enemie);
}

void enemies_target(rpg_t *rpg)
{
    enemie_t *tmp = rpg->enemies;
    while (tmp != NULL) {
        if (tmp->touched == 0 && tmp->target == NULL && tmp->stat->hp > 0)
            dist_player_enemies(rpg, tmp);
        if (tmp->touched == 0 && tmp->target != NULL && tmp->stat->hp > 0)
            move_enemie(rpg, tmp);
        tmp = tmp->next;
    }
}

void move_enemie_touched(rpg_t *rpg)
{
    enemie_t *tmp = rpg->enemies;
    sfTime time;
    float sec;
    while (tmp != NULL) {
        time = sfClock_getElapsedTime(tmp->clock);
        sec = time.microseconds / 1000000.0;
        if (tmp->touched == 1) {
            tmp->sprite->pos.x += tmp->stat->vel_x;
            tmp->sprite->pos.y += tmp->stat->vel_y;
            sfSprite_setPosition(tmp->sprite->sprite, tmp->sprite->pos);
        }
        if (sec >= 0.5 && tmp->touched == 1)
            tmp->touched = 0, tmp->stat->vel_x = 0, tmp->stat->vel_y = 0;
        tmp = tmp->next;
    }
}
