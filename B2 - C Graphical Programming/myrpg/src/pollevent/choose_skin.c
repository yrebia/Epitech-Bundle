/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** Choose Skin
*/

#include "../../include/mystruct.h"

void arrow_left_skin(rpg_t *rpg)
{
    if (rpg->skin == 0) {
        rpg->skin = 1, rpg->skin_player->rect.left = 55;
        sfSprite_setTextureRect
        (rpg->skin_player->sprite, rpg->skin_player->rect);
        rpg->player->texture = sfTexture_createFromFile
        ("assets/player_red.png", NULL);
        sfSprite_setTexture(rpg->player->sprite, rpg->player->texture, sfTrue);
    }
    else if (rpg->skin == 1) {
        rpg->skin = 0, rpg->skin_player->rect.left = 5;
        sfSprite_setTextureRect
        (rpg->skin_player->sprite, rpg->skin_player->rect);
        rpg->player->texture = sfTexture_createFromFile
        ("assets/player.png", NULL);
        sfSprite_setTexture(rpg->player->sprite, rpg->player->texture, sfTrue);
    }
}

void arrow_right_skin(rpg_t *rpg)
{
    if (rpg->skin == 0) {
        rpg->skin = 1, rpg->skin_player->rect.left = 55;
        sfSprite_setTextureRect
        (rpg->skin_player->sprite, rpg->skin_player->rect);
        rpg->player->texture = sfTexture_createFromFile
        ("assets/player_red.png", NULL);
        sfSprite_setTexture(rpg->player->sprite, rpg->player->texture, sfTrue);
    }
    else if (rpg->skin == 1) {
        rpg->skin = 0, rpg->skin_player->rect.left = 5;
        sfSprite_setTextureRect
        (rpg->skin_player->sprite, rpg->skin_player->rect);
        rpg->player->texture = sfTexture_createFromFile
        ("assets/player.png", NULL);
        sfSprite_setTexture(rpg->player->sprite, rpg->player->texture, sfTrue);
    }
}

void choose_skin(rpg_t *rpg)
{
    if (rpg->inventory_id == 1 &&
    rpg->event.key.code == sfMouseLeft &&
    rpg->event.type == sfEvtMouseButtonReleased) {
        if (rpg->event.mouseButton.x >= 516 &&
        rpg->event.mouseButton.y >= 688 &&
        rpg->event.mouseButton.x <= 596 && rpg->event.mouseButton.y <= 728) {
            arrow_left_skin(rpg);
        }
        if (rpg->event.mouseButton.x >= 661 &&
        rpg->event.mouseButton.y >= 690 &&
        rpg->event.mouseButton.x <= 743 && rpg->event.mouseButton.y <= 726) {
            arrow_right_skin(rpg);
        }
    }
}
