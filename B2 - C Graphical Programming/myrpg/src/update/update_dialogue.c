/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** Update Dialogue
*/

#include "../../include/mystruct.h"

void update_dialogue_sign(rpg_t *rpg)
{
    if (rpg->menu_id == 6 && (rpg->player_pos.x >= 930 &&
    rpg->player_pos.y >= 230) && (rpg->player_pos.x <= 1330
    && rpg->player_pos.y <= 630)) {
        rpg->dialogue->time = sfClock_getElapsedTime(rpg->dialogue->clock);
        rpg->dialogue->seconds = rpg->dialogue->time.microseconds / 1000000.0;
        if (rpg->dialogue->seconds >= 0)
            sfRenderWindow_drawSprite(rpg->window,
            rpg->dialogue[0].sprt, NULL);
        if (rpg->dialogue->seconds >= 3)
            sfRenderWindow_drawSprite(rpg->window,
            rpg->dialogue[1].sprt, NULL);
        if (rpg->dialogue->seconds >= 6)
            sfRenderWindow_drawSprite(rpg->window,
            rpg->dialogue[2].sprt, NULL);
        if (rpg->dialogue->seconds >= 9)
            sfClock_restart(rpg->dialogue->clock);
    }
}

void update_dialogue_test(rpg_t *rpg)
{
    if (rpg->menu_id == 6 && (rpg->player_pos.x >= 800 &&
    rpg->player_pos.y >= 250) && (rpg->player_pos.x <= 1200
    && rpg->player_pos.y <= 650)) {
        rpg->inventory[3].placement = 1;
        sfRenderWindow_drawSprite(rpg->window, rpg->dialogue[15].sprt, NULL);
    }
}

void update_dialogue(rpg_t *rpg)
{
    if (rpg->bg->map == 0 && rpg->pause_id == 0 &&
    rpg->menu_id == 6 && rpg->inventory_id == 0) {
        update_dialogue_sign(rpg);
        update_dialogue_fisherman(rpg);
        update_dialogue_gunsmith(rpg);
        update_dialogue_butcher(rpg);
        update_dialogue_jeweler(rpg);
    }

    if (rpg->bg->map == 3 && rpg->pause_id == 0 &&
    rpg->menu_id == 6 && rpg->inventory_id == 0)
        update_dialogue_test(rpg);
}
