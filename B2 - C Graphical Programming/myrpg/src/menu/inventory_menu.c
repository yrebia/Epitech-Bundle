/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** Inventory Menu
*/

#include "../../include/mystruct.h"

void inventory_menu(rpg_t *rpg)
{
    rpg->menu[7][0].texture = sfTexture_createFromFile
    ("assets/inventory.png", NULL);
    rpg->menu[7][0].sprt = sfSprite_create();
    sfSprite_setTexture
    (rpg->menu[7][0].sprt, rpg->menu[7][0].texture, sfFalse);
}
