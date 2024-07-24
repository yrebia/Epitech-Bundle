/*
** EPITECH PROJECT, 2022
** PATHFINDING
** File description:
** Function managing the pathfinding of the enemys
*/

#include "../../include/my.h"

void move_enemy3(t_sprite *enemy, t_game *game, int x, int y)
{
    if (enemy->velocity.y > 0 && y < 15
        && (game->sprtmap[y + 1][x]->state != PATH
            && game->sprtmap[y + 1][x]->state != CASTLE)) {
        enemy->velocity.y = 0;
        if (x < 15 && game->sprtmap[y][x + 1]->state == PATH)
            enemy->velocity.x = enemy->fastest;
        else
            enemy->velocity.x = -enemy->fastest;
    }
    if (enemy->velocity.y < 0 && y > 0
        && (game->sprtmap[y - 1][x]->state != PATH
            && game->sprtmap[y - 1][x]->state != CASTLE)) {
        enemy->velocity.y = 0;
        if (x < 15 && game->sprtmap[y][x + 1]->state == PATH)
            enemy->velocity.x = enemy->fastest;
        else
            enemy->velocity.x = -enemy->fastest;
    }
}

void move_enemy2(t_sprite *enemy, t_game *game, int x, int y)
{
    if (enemy->velocity.x > 0 && x < 15
        && (game->sprtmap[y][x + 1]->state != PATH
            && game->sprtmap[y][x + 1]->state != CASTLE)) {
        enemy->velocity.x = 0;
        if (y < 15 && game->sprtmap[y + 1][x]->state == PATH)
            enemy->velocity.y = enemy->fastest;
        else
            enemy->velocity.y = -enemy->fastest;
    }
    if (enemy->velocity.x < 0 && x > 0
        && (game->sprtmap[y][x - 1]->state != PATH
            && game->sprtmap[y][x - 1]->state != CASTLE)) {
        enemy->velocity.x = 0;
        if (y < 15 && game->sprtmap[y + 1][x]->state == PATH)
            enemy->velocity.y = enemy->fastest;
        else
            enemy->velocity.y = -enemy->fastest;
    }
    move_enemy3(enemy, game, x, y);
}

void move_enemy1(t_sprite *enemy, t_game *game, int x, int y)
{
    if (enemy->velocity.x == 0 && enemy->velocity.y == 0) {
        if (x < 15 && game->sprtmap[y][x + 1]->state == PATH)
            enemy->velocity.x = enemy->fastest;
        if (x > 0 && game->sprtmap[y][x - 1]->state == PATH)
            enemy->velocity.x = -enemy->fastest;
        if (y < 15 && game->sprtmap[y + 1][x]->state == PATH)
            enemy->velocity.y = enemy->fastest;
        if (y > 0 && game->sprtmap[y - 1][x]->state == PATH)
            enemy->velocity.y = -enemy->fastest;
    }

    enemy->pos.x += enemy->velocity.x, enemy->pos.y += enemy->velocity.y;

    move_enemy2(enemy, game, x, y);
}

void move_enemy(t_enemy *enemy, t_game *game)
{
    int x = 0, y = 0;
    if (enemy->sprite->velocity.x == 0 && enemy->sprite->velocity.y == 0)
        x = (enemy->sprite->pos.x - 400) / 67.5,
        y = (enemy->sprite->pos.y + 30) / 67.5;
    if (enemy->sprite->velocity.x > 0) x = (enemy->sprite->pos.x - 420) / 67.5,
        y = (enemy->sprite->pos.y + 30) / 67.5;
    if (enemy->sprite->velocity.x < 0) x = (enemy->sprite->pos.x - 360) / 67.5,
        y = (enemy->sprite->pos.y + 30) / 67.5;
    if (enemy->sprite->velocity.y < 0) x = (enemy->sprite->pos.x - 400) / 67.5,
        y = (enemy->sprite->pos.y + 70) / 67.5;
    if (enemy->sprite->velocity.y > 0) x = (enemy->sprite->pos.x - 400) / 67.5,
        y = (enemy->sprite->pos.y + 10) / 67.5;
    if (game->sprtmap[y][x]->state == CASTLE) {
        game->lives--, enemy->dead = 1; return;
    }
    move_enemy1(enemy->sprite, game, x, y);
}
