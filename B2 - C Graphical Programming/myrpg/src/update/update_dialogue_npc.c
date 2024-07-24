/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** Update Dialogue
*/

#include "../../include/mystruct.h"

void update_dialogue_fisherman(rpg_t *rpg)
{
    if (rpg->menu_id == 6 && (rpg->player_pos.x >= 3200 &&
    rpg->player_pos.y >= 500) && (rpg->player_pos.x <= 3600
    && rpg->player_pos.y <= 900)) {
        rpg->inventory[10].placement = 1;
        rpg->dialogue->time = sfClock_getElapsedTime(rpg->dialogue->clock);
        rpg->dialogue->seconds = rpg->dialogue->time.microseconds / 1000000.0;
        if (rpg->dialogue->seconds >= 0)
            sfRenderWindow_drawSprite(rpg->window,
            rpg->dialogue[3].sprt, NULL);
        if (rpg->dialogue->seconds >= 3)
            sfRenderWindow_drawSprite(rpg->window,
            rpg->dialogue[4].sprt, NULL);
        if (rpg->dialogue->seconds >= 6)
            sfRenderWindow_drawSprite(rpg->window,
            rpg->dialogue[5].sprt, NULL);
        if (rpg->dialogue->seconds >= 9)
            sfClock_restart(rpg->dialogue->clock);
    }
}

void update_dialogue_gunsmith(rpg_t *rpg)
{
    if (rpg->menu_id == 6 && (rpg->player_pos.x >= 1850 &&
    rpg->player_pos.y >= 890) && (rpg->player_pos.x <= 2250
    && rpg->player_pos.y <= 1290)) {
        rpg->dialogue->time = sfClock_getElapsedTime(rpg->dialogue->clock);
        rpg->dialogue->seconds = rpg->dialogue->time.microseconds / 1000000.0;
        if (rpg->dialogue->seconds >= 0)
            sfRenderWindow_drawSprite(rpg->window,
            rpg->dialogue[6].sprt, NULL);
        if (rpg->dialogue->seconds >= 3)
            sfRenderWindow_drawSprite(rpg->window,
            rpg->dialogue[7].sprt, NULL);
        if (rpg->dialogue->seconds >= 6)
            sfRenderWindow_drawSprite(rpg->window,
            rpg->dialogue[8].sprt, NULL);
        if (rpg->dialogue->seconds >= 9)
            sfClock_restart(rpg->dialogue->clock);
    }
}

void update_dialogue_butcher(rpg_t *rpg)
{
    if (rpg->menu_id == 6 && (rpg->player_pos.x >= 1550 &&
    rpg->player_pos.y >= 890) && (rpg->player_pos.x <= 1950
    && rpg->player_pos.y <= 1290)) {
        rpg->inventory[4].placement = 1;
        rpg->inventory[5].placement = 1;
        rpg->inventory[9].placement = 1;
        rpg->dialogue->time = sfClock_getElapsedTime(rpg->dialogue->clock);
        rpg->dialogue->seconds = rpg->dialogue->time.microseconds / 1000000.0;
        if (rpg->dialogue->seconds >= 0)
            sfRenderWindow_drawSprite(rpg->window,
            rpg->dialogue[9].sprt, NULL);
        if (rpg->dialogue->seconds >= 3)
            sfRenderWindow_drawSprite(rpg->window,
            rpg->dialogue[10].sprt, NULL);
        if (rpg->dialogue->seconds >= 6)
            sfRenderWindow_drawSprite(rpg->window,
            rpg->dialogue[11].sprt, NULL);
        if (rpg->dialogue->seconds >= 9)
            sfClock_restart(rpg->dialogue->clock);
    }
}

void update_dialogue_jeweler(rpg_t *rpg)
{
    if (rpg->menu_id == 6 && (rpg->player_pos.x >= 1240 &&
    rpg->player_pos.y >= 890) && (rpg->player_pos.x <= 1640
    && rpg->player_pos.y <= 1290)) {
        rpg->dialogue->time = sfClock_getElapsedTime(rpg->dialogue->clock);
        rpg->dialogue->seconds = rpg->dialogue->time.microseconds / 1000000.0;
        if (rpg->dialogue->seconds >= 0)
            sfRenderWindow_drawSprite(rpg->window,
            rpg->dialogue[12].sprt, NULL);
        if (rpg->dialogue->seconds >= 3)
            sfRenderWindow_drawSprite(rpg->window,
            rpg->dialogue[13].sprt, NULL);
        if (rpg->dialogue->seconds >= 6)
            sfRenderWindow_drawSprite(rpg->window,
            rpg->dialogue[14].sprt, NULL);
        if (rpg->dialogue->seconds >= 9)
            sfClock_restart(rpg->dialogue->clock);
    }
}
