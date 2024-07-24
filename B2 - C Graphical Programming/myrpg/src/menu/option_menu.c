/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** Option Menu
*/

#include "../../include/mystruct.h"

void position_option_menu(rpg_t *rpg)
{
    sfSprite_setPosition(rpg->menu[2][0].sprt, (sfVector2f) {549, 265});
    sfSprite_setPosition(rpg->menu[2][1].sprt, (sfVector2f) {549, 415});
    sfSprite_setPosition(rpg->menu[2][2].sprt, (sfVector2f) {549, 565});
    sfSprite_setPosition(rpg->menu[2][3].sprt, (sfVector2f) {980, 265});
    sfSprite_setPosition(rpg->menu[2][4].sprt, (sfVector2f) {980, 415});
    sfSprite_setPosition(rpg->menu[2][5].sprt, (sfVector2f) {980, 565});
    sfSprite_setPosition(rpg->menu[2][6].sprt, (sfVector2f) {610, 715});
}

void button_option_menu(rpg_t *rpg)
{
    for (int i = 0; i < 7; i++) {
        rpg->menu[2][i].texture = sfTexture_createFromFile
        ("assets/buttons.png", NULL);
        rpg->menu[2][i].sprt = sfSprite_create();
        sfSprite_setTexture(rpg->menu[2][i].sprt,
        rpg->menu[2][i].texture, sfFalse);
        rpg->menu[2][i].rect.top = 0;
        rpg->menu[2][i].rect.left = 0;
        rpg->menu[2][i].rect.width = 400;
        rpg->menu[2][i].rect.height = 100;
        sfSprite_setTextureRect(rpg->menu[2][i].sprt,
        rpg->menu[2][i].rect);
    }
    rpg->menu[2][6].rect.top = 103;
    rpg->menu[2][6].rect.left = 0;
    rpg->menu[2][6].rect.width = 700;
    rpg->menu[2][6].rect.height = 100;
    sfSprite_setTextureRect(rpg->menu[2][6].sprt,
    rpg->menu[2][6].rect);
    position_option_menu(rpg);
}
