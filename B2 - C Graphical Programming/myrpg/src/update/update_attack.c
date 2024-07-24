/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** Update Attack
*/

#include "../../include/mystruct.h"

void attack_anim_left(rpg_t *rpg)
{
    rpg->player->time =
    sfClock_getElapsedTime(rpg->player->attack);
    rpg->player->seconds =
    rpg->player->time.microseconds / 1000000.0;
    if (rpg->player->is_attacking == 1) {
        if (rpg->player->seconds >= 0.1 && rpg->player->rect.left >= 215) {
            sfSprite_setTextureRect(rpg->player->sprite, rpg->player->rect);
            rpg->player->rect.left += 40;
            if (rpg->player->rect.left >= 375) {
                rpg->player->rect.left = 15, rpg->player->is_attacking = 0;
                sfSprite_setTextureRect(rpg->player->sprite,
                rpg->player->rect);
            }
            sfClock_restart(rpg->player->attack);
        }
    }
}

void attack_anim_up(rpg_t *rpg)
{
    if (rpg->player->is_attacking == 2) {
        if (rpg->player->seconds >= 0.15 && rpg->player->rect.left >= 135) {
            sfSprite_setTextureRect(rpg->player->sprite, rpg->player->rect);
            rpg->player->rect.left += 40;
            if (rpg->player->rect.left >= 295) {
                rpg->player->rect.left = 15, rpg->player->is_attacking = 0;
                sfSprite_setTextureRect(rpg->player->sprite,
                rpg->player->rect);
            }
            sfClock_restart(rpg->player->attack);
        }
    }
    attack_anim_left(rpg);
}

void attack_anim_right(rpg_t *rpg)
{
    if (rpg->player->is_attacking == 3) {
        if (rpg->player->seconds >= 0.1 && rpg->player->rect.left >= 215) {
            sfSprite_setTextureRect(rpg->player->sprite, rpg->player->rect);
            rpg->player->rect.left += 40;
            if (rpg->player->rect.left >= 375) {
                rpg->player->rect.left = 15, rpg->player->is_attacking = 0;
                sfSprite_setTextureRect(rpg->player->sprite,
                rpg->player->rect);
            }
            sfClock_restart(rpg->player->attack);
        }
    }
    attack_anim_up(rpg);
}

void attack_anim_down(rpg_t *rpg)
{
    if (rpg->player->is_attacking == 4) {
        if (rpg->player->seconds >= 0.15 && rpg->player->rect.left >= 135) {
            sfSprite_setTextureRect(rpg->player->sprite, rpg->player->rect);
            rpg->player->rect.left += 40;
            if (rpg->player->rect.left >= 295) {
                rpg->player->rect.left = 15, rpg->player->is_attacking = 0;
                sfSprite_setTextureRect(rpg->player->sprite,
                rpg->player->rect);
            }
            sfClock_restart(rpg->player->attack);
        }
    }
    attack_anim_right(rpg);
}
