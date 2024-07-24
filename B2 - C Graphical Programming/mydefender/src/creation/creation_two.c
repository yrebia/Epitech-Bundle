/*
** EPITECH PROJECT, 2022
** CREATION_TWO
** File description:
** Functions for creation
*/

#include "../../include/my.h"

t_sprite *create_borders(char *path, int x)
{
    t_sprite *sprt = malloc(sizeof(t_sprite));

    sprt->pos = (sfVector2f) {348 + x * 1156, -40};
    sprt->texture = sfTexture_createFromFile(path, NULL);
    sprt->sprite = sfSprite_create();
    sprt->scale = (sfVector2f) {1 * ((x == 1) ? -1 : 1), 13};
    sfSprite_setPosition(sprt->sprite, sprt->pos);
    sfSprite_setTexture(sprt->sprite, sprt->texture, sfFalse);
    sfSprite_setScale(sprt->sprite, sprt->scale);
    return (sprt);
}
