/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** Navigation
*/

#include "../../include/mystruct.h"

void click_song_active(rpg_t *rpg)
{
    if (rpg->event.type == sfEvtMouseButtonPressed && rpg->menu_id != 6) {
        if (rpg->event.mouseButton.button == sfMouseLeft)
            click_song(rpg);
    }
    if (rpg->event.key.code == sfKeyE && (rpg->menu_id == 6
    && rpg->inventory_id == 0) && rpg->event.type == sfEvtKeyReleased)
        rpg->inventory_id = 1;
    else if (rpg->event.key.code == sfKeyE && (rpg->menu_id == 6
    && rpg->inventory_id == 1) && rpg->event.type == sfEvtKeyReleased)
        rpg->inventory_id = 0;
}

void navigation_pause(rpg_t *rpg)
{
    if ((rpg->event.mouseButton.x >= 765 && rpg->event.mouseButton.y >= 300)
    && (rpg->event.mouseButton.x <= 1465 && rpg->event.mouseButton.y <= 400)
    && rpg->menu_id == 6 && rpg->pause_id == 1
    && rpg->event.type == sfEvtMouseButtonReleased)
        rpg->pause_id = 0;
    if ((rpg->event.mouseButton.x >= 765 && rpg->event.mouseButton.y >= 425)
    && (rpg->event.mouseButton.x <= 1465 && rpg->event.mouseButton.y <= 525)
    && rpg->menu_id == 6 && rpg->pause_id == 1
    && rpg->event.type == sfEvtMouseButtonReleased)
        rpg->pause_id = 0;
    if ((rpg->event.mouseButton.x >= 765 && rpg->event.mouseButton.y >= 550)
    && (rpg->event.mouseButton.x <= 1465 && rpg->event.mouseButton.y <= 650)
    && rpg->menu_id == 6 && rpg->pause_id == 1
    && rpg->event.type == sfEvtMouseButtonReleased)
        rpg->menu_id = 3;
    if ((rpg->event.mouseButton.x >= 610 && rpg->event.mouseButton.y >= 715)
    && (rpg->event.mouseButton.x <= 1310 && rpg->event.mouseButton.y <= 815)
    && rpg->menu_id == 3 && rpg->pause_id == 1
    && rpg->event.type == sfEvtMouseButtonReleased)
        rpg->pause_id = 0, rpg->menu_id = 6;
}

void navigation_pause2(rpg_t *rpg)
{
    if ((rpg->event.mouseButton.x >= 610 && rpg->event.mouseButton.y >= 920)
    && (rpg->event.mouseButton.x <= 1310 && rpg->event.mouseButton.y <= 1020)
    && rpg->menu_id == 5 && rpg->pause_id == 1
    && rpg->event.type == sfEvtMouseButtonReleased)
        rpg->pause_id = 0, rpg->menu_id = 6;
    if ((rpg->event.mouseButton.x >= 765 && rpg->event.mouseButton.y >= 675)
    && (rpg->event.mouseButton.x <= 1465 && rpg->event.mouseButton.y <= 775)
    && rpg->menu_id == 6 && rpg->pause_id == 1)
        rpg->menu_id = 1;
    if ((rpg->event.mouseButton.x >= 610 && rpg->event.mouseButton.y >= 715)
    && (rpg->event.mouseButton.x <= 1310 && rpg->event.mouseButton.y <= 815)
    && rpg->menu_id == 2 && rpg->pause_id == 1
    && rpg->event.type == sfEvtMouseButtonReleased)
        rpg->menu_id = 1;
    if ((rpg->event.mouseButton.x >= 610 && rpg->event.mouseButton.y >= 715)
    && (rpg->event.mouseButton.x <= 1310 && rpg->event.mouseButton.y <= 815)
    && rpg->menu_id == 3 && rpg->pause_id == 0
    && rpg->event.type == sfEvtMouseButtonReleased)
        rpg->menu_id = 1;
}

void back_main_menu(rpg_t *rpg)
{
    if ((rpg->event.mouseButton.x >= 610 && rpg->event.mouseButton.y >= 920)
    && (rpg->event.mouseButton.x <= 1310 && rpg->event.mouseButton.y <= 1020)
    && rpg->menu_id == 4 && rpg->event.type == sfEvtMouseButtonReleased)
        rpg->menu_id = 1;
    if ((rpg->event.mouseButton.x >= 610 && rpg->event.mouseButton.y >= 920)
    && (rpg->event.mouseButton.x <= 1310 && rpg->event.mouseButton.y <= 1020)
    && rpg->menu_id == 5 && rpg->pause_id == 0
    && rpg->event.type == sfEvtMouseButtonReleased)
        rpg->menu_id = 1;
    if ((rpg->event.mouseButton.x >= 760 && rpg->event.mouseButton.y >= 265)
    && (rpg->event.mouseButton.x <= 1160 && rpg->event.mouseButton.y <= 365)
    && rpg->menu_id == 2 && rpg->event.type == sfEvtMouseButtonReleased)
        rpg->menu_id = 6;
    if ((rpg->event.mouseButton.x >= 760 && rpg->event.mouseButton.y >= 265)
    && (rpg->event.mouseButton.x <= 1160 && rpg->event.mouseButton.y <= 365)
    && rpg->menu_id == 1 && rpg->event.type == sfEvtMouseButtonReleased)
        rpg->menu_id = 2;
}

void navigation_menu(rpg_t *rpg)
{
    if ((rpg->event.mouseButton.x >= 760 && rpg->event.mouseButton.y >= 415)
    && (rpg->event.mouseButton.x <= 1160 && rpg->event.mouseButton.y <= 515)
    && rpg->menu_id == 1 && rpg->event.type == sfEvtMouseButtonReleased)
        rpg->menu_id = 3;
    if ((rpg->event.mouseButton.x >= 760 && rpg->event.mouseButton.y >= 565)
    && (rpg->event.mouseButton.x <= 1160 && rpg->event.mouseButton.y <= 665)
    && rpg->menu_id == 1 && rpg->event.type == sfEvtMouseButtonReleased)
        rpg->menu_id = 4;
    if ((rpg->event.mouseButton.x >= 980 && rpg->event.mouseButton.y >= 565)
    && (rpg->event.mouseButton.x <= 1371 && rpg->event.mouseButton.y <= 665)
    && rpg->menu_id == 3 && rpg->event.type == sfEvtMouseButtonReleased)
        rpg->menu_id = 5;
    click_song_active(rpg);
    back_main_menu(rpg);
    navigation_pause(rpg);
    navigation_pause2(rpg);
}
