/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** Update Menu
*/

#include "../../include/mystruct.h"

void update_menu(rpg_t *rpg)
{
    rpg->parallax->time =
        sfClock_getElapsedTime(rpg->parallax->clock);
        rpg->parallax->seconds =
        rpg->parallax->time.microseconds / 1000000.0;
        move_sky_parallax(rpg);
        move_moon_parallax(rpg);
    for (int i = 0; i < 4; i++)
        sfRenderWindow_drawSprite(rpg->window, rpg->parallax[i].sprt, NULL);

    update_main_menu(rpg);
    update_guide_menu(rpg);
    update_keys_menu(rpg);
}
