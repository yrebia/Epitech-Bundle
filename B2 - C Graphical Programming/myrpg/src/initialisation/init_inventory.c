/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** Initialisation
*/

#include "../../include/mystruct.h"

void init_inventory(rpg_t *rpg)
{
    for (int i = 0; i < 12; i++)
        rpg->inventory[i].placement = 0;
    rpg->inventory[6].placement = 1;
    rpg->inventory[7].placement = 1;
    rpg->inventory[8].placement = 1;
    rpg->inventory[11].placement = 1;
}
