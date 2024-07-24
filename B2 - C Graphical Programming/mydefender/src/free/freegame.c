/*
** EPITECH PROJECT, 2022
** FREEGAME
** File description:
** Function freeing game structure
*/

#include "../../include/my.h"

void free_sprite(t_sprite *sprite)
{
    sfClock_destroy(sprite->animation);
    sfClock_destroy(sprite->movement);
    sfTexture_destroy(sprite->texture);
    sfSprite_destroy(sprite->sprite);
    free(sprite->rect);
    free(sprite->pos);
    free(sprite->scale);
    free(sprite->velocity);
    free(sprite);
}

void free_enemys(t_enemy *enemys)
{
    t_enemy *tmp = malloc(sizeof(t_enemy));

    while (enemys) {
        free_sprite(enemys->sprite);
        tmp = enemys->next;
        free(enemys);
        enemys = tmp;
    }

    free(tmp);
}

void free_towers(t_tower *towers)
{
    t_tower *tmp = malloc(sizeof(t_tower));

    while (towers) {
        free_sprite(towers->sprite);
        tmp = towers->next;
        free(towers);
        towers = tmp;
    }

    free(tmp);
}

void free_game(t_game *game)
{
    free(game->smap);
    free_enemys(game->enemys);
    free_towers(game->towers);
    free(game->event);
    sfRenderWindow_destroy(game->window);
}
