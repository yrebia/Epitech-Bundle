/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** Movement
*/

#include "../../include/mystruct.h"

void move_left(rpg_t *rpg)
{
    rpg->state = 1;
    rpg->player->rect.top = 100;
    sfSprite_setTextureRect(rpg->player->sprite, rpg->player->rect);
    rpg->player->rect.left += 40;
    if (rpg->player->rect.left >= 175) {
        rpg->player->rect.left = 15;
    }
    sfSprite_setTextureRect(rpg->player->sprite, rpg->player->rect);
    if (rpg->player_pos.x == rpg->player->pos.x &&
    rpg->player_pos.y == rpg->player->pos.y) {
        all_tp4(rpg);
    }
}

void move_right(rpg_t *rpg)
{
    rpg->state = 3;
    rpg->player->rect.top = 140;
    sfSprite_setTextureRect(rpg->player->sprite, rpg->player->rect);
    rpg->player->rect.left += 40;
    if (rpg->player->rect.left >= 175) {
        rpg->player->rect.left = 15;
    }
    sfSprite_setTextureRect(rpg->player->sprite, rpg->player->rect);
    if (rpg->player_pos.x == rpg->player->pos.x &&
    rpg->player_pos.y == rpg->player->pos.y) {
        all_tp2(rpg);
    }
}

void move_up(rpg_t *rpg)
{
    rpg->state = 2;
    rpg->player->rect.top = 60;
    sfSprite_setTextureRect(rpg->player->sprite, rpg->player->rect);
    rpg->player->rect.left += 40;
    if (rpg->player->rect.left >= 135) {
        rpg->player->rect.left = 55;
    }
    sfSprite_setTextureRect(rpg->player->sprite, rpg->player->rect);
    if (rpg->player_pos.x == rpg->player->pos.x &&
    rpg->player_pos.y == rpg->player->pos.y) {
        all_tp(rpg);
    }
}

void move_down(rpg_t *rpg)
{
    rpg->state = 4;
    rpg->player->rect.top = 17;
    sfSprite_setTextureRect(rpg->player->sprite, rpg->player->rect);
    rpg->player->rect.left += 40;
    if (rpg->player->rect.left >= 135) {
        rpg->player->rect.left = 55;
    }
    sfSprite_setTextureRect(rpg->player->sprite, rpg->player->rect);
    if (rpg->player_pos.x == rpg->player->pos.x &&
    rpg->player_pos.y == rpg->player->pos.y) {
        all_tp3(rpg);
    }
}
