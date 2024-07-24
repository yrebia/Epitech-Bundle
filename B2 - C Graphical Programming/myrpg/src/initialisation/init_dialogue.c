/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** Initialisation
*/

#include "../../include/mystruct.h"

void init_dialogue(rpg_t *rpg)
{
    rpg->dialogue->seconds = 0;
    rpg->dialogue->clock = sfClock_create();
    rpg->loose = 0;
}
