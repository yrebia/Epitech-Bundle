/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** State Main Menu
*/

#include "../../../include/mystruct.h"

void state_main_menu(rpg_t *rpg)
{
    if ((rpg->event.mouseMove.x >= 760 && rpg->event.mouseMove.y >= 265)
    && (rpg->event.mouseMove.x <= 1160 && rpg->event.mouseMove.y <= 365)
    && rpg->menu_id == 2) {

    }
}

void state_main_menu0(rpg_t *rpg)
{
    if ((rpg->event.mouseMove.x >= 760 && rpg->event.mouseMove.y >= 265)
    && (rpg->event.mouseMove.x <= 1160 && rpg->event.mouseMove.y <= 365)
    && rpg->menu_id == 1) {
        rpg->menu[0][0].texture = sfTexture_createFromFile
        ("assets/buttons_grey.png", NULL);
        sfSprite_setTexture
        (rpg->menu[0][0].sprt, rpg->menu[0][0].texture, sfFalse);
    } else {
        rpg->menu[0][0].texture = sfTexture_createFromFile
        ("assets/buttons.png", NULL);
        sfSprite_setTexture
        (rpg->menu[0][0].sprt, rpg->menu[0][0].texture, sfFalse);
    }
}

void state_main_menu1(rpg_t *rpg)
{
    if ((rpg->event.mouseMove.x >= 760 && rpg->event.mouseMove.y >= 415)
    && (rpg->event.mouseMove.x <= 1160 && rpg->event.mouseMove.y <= 515)
    && rpg->menu_id == 1) {
        rpg->menu[0][1].texture = sfTexture_createFromFile
        ("assets/buttons_grey.png", NULL);
        sfSprite_setTexture
        (rpg->menu[0][1].sprt, rpg->menu[0][1].texture, sfFalse);
    } else {
        rpg->menu[0][1].texture = sfTexture_createFromFile
        ("assets/buttons.png", NULL);
        sfSprite_setTexture
        (rpg->menu[0][1].sprt, rpg->menu[0][1].texture, sfFalse);
    }
}

void state_main_menu2(rpg_t *rpg)
{
    if ((rpg->event.mouseMove.x >= 760 && rpg->event.mouseMove.y >= 565)
    && (rpg->event.mouseMove.x <= 1160 && rpg->event.mouseMove.y <= 665)
    && rpg->menu_id == 1) {
        rpg->menu[0][2].texture = sfTexture_createFromFile
        ("assets/buttons_grey.png", NULL);
        sfSprite_setTexture
        (rpg->menu[0][2].sprt, rpg->menu[0][2].texture, sfFalse);
    } else {
        rpg->menu[0][2].texture = sfTexture_createFromFile
        ("assets/buttons.png", NULL);
        sfSprite_setTexture
        (rpg->menu[0][2].sprt, rpg->menu[0][2].texture, sfFalse);
    }
}

void state_main_menu3(rpg_t *rpg)
{
    if ((rpg->event.mouseMove.x >= 980 && rpg->event.mouseMove.y >= 565)
    && (rpg->event.mouseMove.x <= 1371 && rpg->event.mouseMove.y <= 665)
    && rpg->menu_id == 3) {
        rpg->menu[2][0].texture = sfTexture_createFromFile
        ("assets/buttons_grey.png", NULL);
        sfSprite_setTexture
        (rpg->menu[2][0].sprt, rpg->menu[2][0].texture, sfFalse);
    } else {
        rpg->menu[2][0].texture = sfTexture_createFromFile
        ("assets/buttons.png", NULL);
        sfSprite_setTexture
        (rpg->menu[2][0].sprt, rpg->menu[2][0].texture, sfFalse);
    }
}
