/*
** EPITECH PROJECT, 2022
** CREATE_BULLETS
** File description:
** Function creating bullets
*/

#include "../../include/my.h"

t_sprite *create_bullet(char *path, sfVector2f pos, int velx, int vely)
{
    t_sprite *sprt = malloc(sizeof(t_sprite));
    sprt->texture = sfTexture_createFromFile(path, NULL);
    sprt->sprite = sfSprite_create();
    sprt->pos = pos; sprt->pos.x += 18; sprt->pos.y += 18;
    sprt->rect = (sfIntRect) {0, 0, 100, 100};
    float angle = atan2(vely - (pos.y - 18), velx - (pos.x - 18));
    sprt->velocity.x = cos(angle) * 4;
    sprt->velocity.y = sin(angle) * 4;
    sprt->scale = (sfVector2f) {0.25, 0.25};
    sfSprite_setScale(sprt->sprite, sprt->scale);
    sfSprite_setTextureRect(sprt->sprite, sprt->rect);
    sfSprite_setPosition(sprt->sprite, sprt->pos);
    sfSprite_setTexture(sprt->sprite, sprt->texture, sfFalse);
    return (sprt);
}
