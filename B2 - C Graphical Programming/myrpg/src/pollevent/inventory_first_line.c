/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** Inventory
*/

#include "../../include/mystruct.h"

void inventory_second_case(rpg_t *rpg)
{
    if ((rpg->event.mouseButton.x >= 1050 && rpg->event.mouseButton.y >= 320)
    && (rpg->event.mouseButton.x <= 1180 && rpg->event.mouseButton.y <= 445)
    && rpg->menu_id == 6 && rpg->inventory_id == 1
    && rpg->event.type == sfEvtMouseButtonReleased &&
    rpg->inventory[4].placement == 1) {
        if (rpg->player->hp + 10 >= 100) rpg->player->hp = 100;
        else
            rpg->player->hp += 10;
        rpg->inventory[4].placement = 0;
    }
}

void inventory_third_case(rpg_t *rpg)
{
    if ((rpg->event.mouseButton.x >= 1200 && rpg->event.mouseButton.y >= 320)
    && (rpg->event.mouseButton.x <= 1330 && rpg->event.mouseButton.y <= 445)
    && rpg->menu_id == 6 && rpg->inventory_id == 1
    && rpg->event.type == sfEvtMouseButtonReleased &&
    rpg->inventory[5].placement == 1) {
        if (rpg->player->hp + 10 >= 100) rpg->player->hp = 100;
        else
            rpg->player->hp += 10;
        rpg->inventory[5].placement = 0;
    }
}
