/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** Inventory
*/

#include "../../include/mystruct.h"

void inventory_seventh_case(rpg_t *rpg)
{
    if ((rpg->event.mouseButton.x >= 900 && rpg->event.mouseButton.y >= 620)
    && (rpg->event.mouseButton.x <= 1030 && rpg->event.mouseButton.y <= 745)
    && rpg->menu_id == 6 && rpg->inventory_id == 1
    && rpg->event.type == sfEvtMouseButtonReleased &&
    rpg->inventory[9].placement == 1) {
        if (rpg->player->hp + 10 >= 100) rpg->player->hp = 100;
        else
            rpg->player->hp += 10;
        rpg->inventory[9].placement = 0;
    }
}

void inventory_eighth_case(rpg_t *rpg)
{
    if ((rpg->event.mouseButton.x >= 1050 && rpg->event.mouseButton.y >= 620)
    && (rpg->event.mouseButton.x <= 1180 && rpg->event.mouseButton.y <= 745)
    && rpg->menu_id == 6 && rpg->inventory_id == 1
    && rpg->event.type == sfEvtMouseButtonReleased &&
    rpg->inventory[10].placement == 1) {
        if (rpg->player->hp + 10 >= 100) rpg->player->hp = 100;
        else
            rpg->player->hp += 10;
        rpg->inventory[10].placement = 0;
    }
}

void inventory_ninth_case(rpg_t *rpg)
{
    if ((rpg->event.mouseButton.x >= 1200 && rpg->event.mouseButton.y >= 620)
    && (rpg->event.mouseButton.x <= 1330 && rpg->event.mouseButton.y <= 745)
    && rpg->menu_id == 6 && rpg->inventory_id == 1
    && rpg->event.type == sfEvtMouseButtonReleased &&
    rpg->inventory[11].placement == 1) {
        if (rpg->player->hp + 10 >= 100) rpg->player->hp = 100;
        else
            rpg->player->hp += 10;
        rpg->inventory[11].placement = 0;
    }
}
