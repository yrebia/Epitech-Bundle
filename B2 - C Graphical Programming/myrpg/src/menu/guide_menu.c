/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** Guide Menu
*/

#include "../../include/mystruct.h"

void button_guide_menu(rpg_t *rpg)
{
    rpg->menu[3][0].texture = sfTexture_createFromFile
    ("assets/history.png", NULL);
    rpg->menu[3][0].sprt = sfSprite_create();
    sfSprite_setTexture(rpg->menu[3][0].sprt,
    rpg->menu[3][0].texture, sfFalse);
    rpg->menu[3][1].texture = sfTexture_createFromFile
    ("assets/guide_fr.png", NULL);
    rpg->menu[3][1].sprt = sfSprite_create();
    sfSprite_setTexture(rpg->menu[3][1].sprt,
    rpg->menu[3][1].texture, sfFalse);
    rpg->menu[3][2].texture = sfTexture_createFromFile
    ("assets/guide_en.png", NULL);
    rpg->menu[3][2].sprt = sfSprite_create();
    sfSprite_setTexture(rpg->menu[3][2].sprt,
    rpg->menu[3][2].texture, sfFalse);
    rpg->menu[3][3].texture = sfTexture_createFromFile
    ("assets/buttons.png", NULL);
    rpg->menu[3][3].sprt = sfSprite_create();
    sfSprite_setTexture(rpg->menu[3][3].sprt,
    rpg->menu[3][3].texture, sfFalse);
}

void button_guide_menu_rect(rpg_t *rpg)
{
    rpg->menu[3][3].rect.top = 103;
    rpg->menu[3][3].rect.left = 0;
    rpg->menu[3][3].rect.width = 700;
    rpg->menu[3][3].rect.height = 100;
    sfSprite_setTextureRect(rpg->menu[3][3].sprt,
    rpg->menu[3][3].rect);
    sfSprite_setPosition(rpg->menu[3][3].sprt,
    (sfVector2f) {610, 920});
}

void init_title(rpg_t *rpg)
{
    rpg->title = malloc(sizeof(sprite_t));
    rpg->title->texture = sfTexture_createFromFile
    ("assets/medieval_quest.png", NULL);
    rpg->title->sprite = sfSprite_create();
    sfSprite_setTexture(rpg->title->sprite, rpg->title->texture, sfFalse);
    sfSprite_setPosition(rpg->title->sprite, (sfVector2f) {700, 0});
    rpg->title->scale.x = 1.9;
    rpg->title->scale.y = 1.9;
    sfSprite_setScale(rpg->title->sprite, rpg->title->scale);
}
