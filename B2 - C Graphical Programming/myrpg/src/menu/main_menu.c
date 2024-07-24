/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** Main Menu
*/

#include "../../include/mystruct.h"

void position_main_menu(rpg_t *rpg)
{
    sfSprite_setPosition(rpg->menu[0][0].sprt, (sfVector2f) {760, 265});
    sfSprite_setPosition(rpg->menu[0][1].sprt, (sfVector2f) {760, 415});
    sfSprite_setPosition(rpg->menu[0][2].sprt, (sfVector2f) {760, 565});
    sfSprite_setPosition(rpg->menu[0][3].sprt, (sfVector2f) {760, 715});
}

void button_main_menu(rpg_t *rpg)
{
    for (int i = 0; i < 4; i++) {
        rpg->menu[0][i].texture = sfTexture_createFromFile
        ("assets/buttons.png", NULL);
        rpg->menu[0][i].sprt = sfSprite_create();
        sfSprite_setTexture(rpg->menu[0][i].sprt,
        rpg->menu[0][i].texture, sfFalse);

        rpg->menu[0][i].rect.top = 0;
        rpg->menu[0][i].rect.left = 0;
        rpg->menu[0][i].rect.width = 400;
        rpg->menu[0][i].rect.height = 100;
        sfSprite_setTextureRect(rpg->menu[0][i].sprt,
        rpg->menu[0][i].rect);
    }
    position_main_menu(rpg);
}
