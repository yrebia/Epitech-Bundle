/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** Pause Menu
*/

#include "../../include/mystruct.h"

void position_pause_menu(rpg_t *rpg)
{
    sfSprite_setPosition(rpg->menu[6][0].sprt, (sfVector2f) {0, 0});
    sfSprite_setPosition(rpg->menu[6][1].sprt, (sfVector2f) {765, 300});
    sfSprite_setPosition(rpg->menu[6][2].sprt, (sfVector2f) {765, 425});
    sfSprite_setPosition(rpg->menu[6][3].sprt, (sfVector2f) {765, 550});
    sfSprite_setPosition(rpg->menu[6][4].sprt, (sfVector2f) {765, 675});
}

void button_pause_menu(rpg_t *rpg)
{
    rpg->menu[6][0].texture = sfTexture_createFromFile
    ("assets/pause_menu.png", NULL);
    rpg->menu[6][0].sprt = sfSprite_create();
    sfSprite_setTexture(rpg->menu[6][0].sprt,
    rpg->menu[6][0].texture, sfFalse);

    for (int i = 1; i < 5; i++) {
        rpg->menu[6][i].texture = sfTexture_createFromFile
        ("assets/buttons.png", NULL);
        rpg->menu[6][i].sprt = sfSprite_create();
        sfSprite_setTexture(rpg->menu[6][i].sprt,
        rpg->menu[6][i].texture, sfFalse);
        rpg->menu[6][i].rect.top = 0;
        rpg->menu[6][i].rect.left = 0;
        rpg->menu[6][i].rect.width = 400;
        rpg->menu[6][i].rect.height = 100;
        sfSprite_setTextureRect(rpg->menu[6][i].sprt,
        rpg->menu[6][i].rect);
    }
    position_pause_menu(rpg);
}
