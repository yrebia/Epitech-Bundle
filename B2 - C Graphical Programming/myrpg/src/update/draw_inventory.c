/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** Update Inventory
*/

#include "../../include/mystruct.h"

void draw_inventory(rpg_t *rpg)
{
    for (int i = 3; i < 12; i++)
        if (rpg->inventory[i].placement == 1 && rpg->inventory_id == 1)
            sfRenderWindow_drawSprite(rpg->window,
            rpg->inventory[i].sprt, NULL);
}
