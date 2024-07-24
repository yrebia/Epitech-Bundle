/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** Create Sprite
*/

#include "../../include/mystruct.h"

void position_sprite(rpg_t *rpg)
{
    sfSprite_setPosition(rpg->inventory[3].sprt, (sfVector2f) {930, 340});
    sfSprite_setPosition(rpg->inventory[4].sprt, (sfVector2f) {1080, 340});
    sfSprite_setPosition(rpg->inventory[5].sprt, (sfVector2f) {1230, 340});
    sfSprite_setPosition(rpg->inventory[6].sprt, (sfVector2f) {930, 490});
    sfSprite_setPosition(rpg->inventory[7].sprt, (sfVector2f) {1080, 490});
    sfSprite_setPosition(rpg->inventory[8].sprt, (sfVector2f) {1230, 490});
    sfSprite_setPosition(rpg->inventory[9].sprt, (sfVector2f) {930, 640});
    sfSprite_setPosition(rpg->inventory[10].sprt, (sfVector2f) {1080, 640});
    sfSprite_setPosition(rpg->inventory[11].sprt, (sfVector2f) {1230, 640});
}

void create_sprite(rpg_t *rpg)
{
    rpg->inventory[3].texture = sfTexture_createFromFile
    ("assets/food/beer.png", NULL);
    rpg->inventory[4].texture = sfTexture_createFromFile
    ("assets/food/boar.png", NULL);
    rpg->inventory[5].texture = sfTexture_createFromFile
    ("assets/food/chickenleg.png", NULL);
    rpg->inventory[6].texture = sfTexture_createFromFile
    ("assets/food/cookie.png", NULL);
    rpg->inventory[7].texture = sfTexture_createFromFile
    ("assets/food/eggs.png", NULL);
    rpg->inventory[8].texture = sfTexture_createFromFile
    ("assets/food/potato.png", NULL);
    rpg->inventory[9].texture = sfTexture_createFromFile
    ("assets/food/roll.png", NULL);
}

void create_sprite2(rpg_t *rpg)
{
    rpg->inventory[10].texture = sfTexture_createFromFile
    ("assets/food/saki.png", NULL);
    rpg->inventory[11].texture = sfTexture_createFromFile
    ("assets/food/sardines.png", NULL);
    for (int i = 3; i < 12; i++) {
        rpg->inventory[i].sprt = sfSprite_create();
        sfSprite_setTexture(rpg->inventory[i].sprt,
        rpg->inventory[i].texture, sfFalse);
        sfSprite_scale(rpg->inventory[i].sprt, (sfVector2f) {5, 5});
    }
    position_sprite(rpg);
}

void create_loading(rpg_t *rpg)
{
    rpg->waiting = malloc(sizeof(sprite_t));
    rpg->waiting->texture = sfTexture_createFromFile
    ("assets/loading.png", NULL);
    rpg->waiting->sprite = sfSprite_create();
    sfSprite_setTexture(rpg->waiting->sprite,
    rpg->waiting->texture, sfFalse);
}
