/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** Keys Menu
*/

#include "../../include/mystruct.h"

void position_keys_menu(rpg_t *rpg)
{
    sfSprite_setPosition(rpg->menu[5][0].sprt, (sfVector2f) {0, 0});
    sfSprite_setPosition(rpg->menu[5][1].sprt, (sfVector2f) {360, 150});
    sfSprite_setPosition(rpg->menu[5][2].sprt, (sfVector2f) {360, 280});
    sfSprite_setPosition(rpg->menu[5][3].sprt, (sfVector2f) {360, 410});
    sfSprite_setPosition(rpg->menu[5][4].sprt, (sfVector2f) {360, 540});
    sfSprite_setPosition(rpg->menu[5][5].sprt, (sfVector2f) {360, 670});
    sfSprite_setPosition(rpg->menu[5][6].sprt, (sfVector2f) {1170, 150});
    sfSprite_setPosition(rpg->menu[5][7].sprt, (sfVector2f) {1170, 280});
    sfSprite_setPosition(rpg->menu[5][8].sprt, (sfVector2f) {1170, 410});
    sfSprite_setPosition(rpg->menu[5][9].sprt, (sfVector2f) {1170, 540});
    sfSprite_setPosition(rpg->menu[5][10].sprt, (sfVector2f) {1170, 670});
    sfSprite_setPosition(rpg->menu[5][11].sprt, (sfVector2f) {610, 920});
}

void button_keys_menu(rpg_t *rpg)
{
    rpg->menu[5][0].texture = sfTexture_createFromFile
    ("assets/parallax/keys_menu.png", NULL);
    rpg->menu[5][0].sprt = sfSprite_create();
    sfSprite_setTexture(rpg->menu[5][0].sprt,
        rpg->menu[5][0].texture, sfFalse);

    for (int i = 1; i < 6; i++) {
        rpg->menu[5][i].texture = sfTexture_createFromFile
        ("assets/buttons.png", NULL);
        rpg->menu[5][i].sprt = sfSprite_create();
        sfSprite_setTexture(rpg->menu[5][i].sprt,
        rpg->menu[5][i].texture, sfFalse);

        rpg->menu[5][i].rect.top = 103;
        rpg->menu[5][i].rect.left = 0;
        rpg->menu[5][i].rect.width = 700;
        rpg->menu[5][i].rect.height = 100;
        sfSprite_setTextureRect(rpg->menu[5][i].sprt,
        rpg->menu[5][i].rect);
    }
}

void button_keys_menu2(rpg_t *rpg)
{
    for (int i = 6; i < 11; i++) {
        rpg->menu[5][i].texture = sfTexture_createFromFile
        ("assets/buttons.png", NULL);
        rpg->menu[5][i].sprt = sfSprite_create();
        sfSprite_setTexture(rpg->menu[5][i].sprt,
        rpg->menu[5][i].texture, sfFalse);
        rpg->menu[5][i].rect.top = 0;
        rpg->menu[5][i].rect.left = 0;
        rpg->menu[5][i].rect.width = 400;
        rpg->menu[5][i].rect.height = 100;
        sfSprite_setTextureRect(rpg->menu[5][i].sprt,
        rpg->menu[5][i].rect);
    }
}

void button_keys_menu3(rpg_t *rpg)
{
    rpg->menu[5][11].texture = sfTexture_createFromFile
    ("assets/buttons.png", NULL);
    rpg->menu[5][11].sprt = sfSprite_create();
    sfSprite_setTexture(rpg->menu[5][11].sprt,
    rpg->menu[5][11].texture, sfFalse);
    rpg->menu[5][11].rect.top = 103;
    rpg->menu[5][11].rect.left = 0;
    rpg->menu[5][11].rect.width = 700;
    rpg->menu[5][11].rect.height = 100;
    sfSprite_setTextureRect(rpg->menu[5][11].sprt,
    rpg->menu[5][11].rect);
    position_keys_menu(rpg);
}

void create_loose_menu(rpg_t *rpg)
{
    rpg->menu[8][0].texture = sfTexture_createFromFile
    ("assets/loose_screen.png", NULL);
    rpg->menu[8][0].sprt = sfSprite_create();
    sfSprite_setTexture(rpg->menu[8][0].sprt,
    rpg->menu[8][0].texture, sfFalse);
    rpg->menu[9][0].texture = sfTexture_createFromFile
    ("assets/win_screen.png", NULL);
    rpg->menu[9][0].sprt = sfSprite_create();
    sfSprite_setTexture(rpg->menu[9][0].sprt,
    rpg->menu[9][0].texture, sfFalse);
}
