/*
** EPITECH PROJECT, 2022
** INIT_BULLET
** File description:
** Function initializing bullets
*/

#include "../../include/my.h"

t_enemy *find_target(t_game *game, t_tower *tower)
{
    t_enemy *tmp = game->enemys;
    while (tmp != 0) {
        int hypot = sqrt(pow(tower->sprite->pos.x - tmp->sprite->pos.x, 2) +
        pow(tower->sprite->pos.y - tmp->sprite->pos.y, 2));
        if (tmp->dead != 1 && hypot <= tower->stats->RANGE)
            return (tmp);
        tmp = tmp->next;
    }
    return (0);
}

void init_bullet1(t_game *game, t_tower *tower)
{
    t_enemy *target = find_target(game, tower);
    if (target != 0) {
        tower->target = target;
        sfMusic_stop(game->music->shot), sfMusic_play(game->music->shot);
        t_bullet *bullet = malloc(sizeof(t_bullet));
        bullet->next = game->bullets;
        int enemyx = tower->target->sprite->pos.x;
        int enemyy = tower->target->sprite->pos.y;
        bullet->sprite = create_bullet("resources/projectile.png",
        tower->sprite->pos, enemyx, enemyy);
        bullet->stats = set_stats_t(10, 5, 100);
        bullet->target = tower->target;
        bullet->from = tower;
        game->bullets = bullet;
        return;
    }
}

void init_bullet(t_game *game, t_tower *tower)
{
    if (tower->target != 0) {
        int hypot = sqrt
        (pow(tower->sprite->pos.x - tower->target->sprite->pos.x, 2) +
        pow(tower->sprite->pos.y - tower->target->sprite->pos.y, 2));
        if (tower->target->dead != 1 && hypot <= tower->stats->RANGE) {
            sfMusic_stop(game->music->shot), sfMusic_play(game->music->shot);
            t_bullet *bullet = malloc(sizeof(t_bullet));
            bullet->next = game->bullets;
            int enemyx = tower->target->sprite->pos.x;
            int enemyy = tower->target->sprite->pos.y;
            bullet->sprite = create_bullet("resources/projectile.png",
            tower->sprite->pos, enemyx, enemyy);
            bullet->stats = set_stats_t(10, 5, 100);
            bullet->target = tower->target; bullet->from = tower;
            game->bullets = bullet; return;
        } else
            tower->target = 0;
    } init_bullet1(game, tower);
}
