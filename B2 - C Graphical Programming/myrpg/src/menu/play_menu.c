/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** Play Menu
*/

#include "../../include/mystruct.h"

void position_play_menu(rpg_t *rpg)
{
    sfSprite_setPosition(rpg->menu[1][0].sprt, (sfVector2f) {760, 265});
    sfSprite_setPosition(rpg->menu[1][1].sprt, (sfVector2f) {760, 415});
    sfSprite_setPosition(rpg->menu[1][2].sprt, (sfVector2f) {760, 565});
    sfSprite_setPosition(rpg->menu[1][3].sprt, (sfVector2f) {610, 715});
}

void button_play_menu(rpg_t *rpg)
{
    for (int i = 0; i < 4; i++) {
        rpg->menu[1][i].texture = sfTexture_createFromFile(
            "assets/buttons.png", NULL);
        rpg->menu[1][i].sprt = sfSprite_create();
        sfSprite_setTexture(rpg->menu[1][i].sprt,
        rpg->menu[1][i].texture, sfFalse);
        rpg->menu[1][i].rect.top = 0;
        rpg->menu[1][i].rect.left = 0;
        rpg->menu[1][i].rect.width = 400;
        rpg->menu[1][i].rect.height = 100;
        sfSprite_setTextureRect(rpg->menu[1][i].sprt,
        rpg->menu[1][i].rect);
    }
    rpg->menu[1][3].rect.top = 103;
    rpg->menu[1][3].rect.left = 0;
    rpg->menu[1][3].rect.width = 700;
    rpg->menu[1][3].rect.height = 100;
    sfSprite_setTextureRect(rpg->menu[1][3].sprt,
    rpg->menu[1][3].rect);
    position_play_menu(rpg);
}
