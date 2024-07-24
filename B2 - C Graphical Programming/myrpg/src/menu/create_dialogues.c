/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** Create Dialogues
*/

#include "../../include/mystruct.h"

void rect_dialogue(rpg_t *rpg)
{
    rpg->dialogue[0].rect.top = 0, rpg->dialogue[0].rect.left = 0;
    rpg->dialogue[1].rect.top = 0, rpg->dialogue[1].rect.left = 506;
    rpg->dialogue[2].rect.top = 0, rpg->dialogue[2].rect.left = 1012;
    rpg->dialogue[3].rect.top = 147, rpg->dialogue[3].rect.left = 0;
    rpg->dialogue[4].rect.top = 147, rpg->dialogue[4].rect.left = 506;
    rpg->dialogue[5].rect.top = 147, rpg->dialogue[5].rect.left = 1012;
    rpg->dialogue[6].rect.top = 294, rpg->dialogue[6].rect.left = 0;
    rpg->dialogue[7].rect.top = 294, rpg->dialogue[7].rect.left = 506;
    rpg->dialogue[8].rect.top = 294, rpg->dialogue[8].rect.left = 1012;
    rpg->dialogue[9].rect.top = 588, rpg->dialogue[9].rect.left = 0;
    rpg->dialogue[10].rect.top = 588, rpg->dialogue[10].rect.left = 506;
    rpg->dialogue[11].rect.top = 588, rpg->dialogue[11].rect.left = 101;
    rpg->dialogue[12].rect.top = 441, rpg->dialogue[12].rect.left = 0;
    rpg->dialogue[13].rect.top = 441, rpg->dialogue[13].rect.left = 506;
    rpg->dialogue[14].rect.top = 441, rpg->dialogue[14].rect.left = 1012;
    rpg->dialogue[15].rect.top = 882, rpg->dialogue[15].rect.left = 0;
}

void position_dialogue(rpg_t *rpg)
{
    sfSprite_setPosition(rpg->dialogue[0].sprt, (sfVector2f) {1130, 430});
    sfSprite_setPosition(rpg->dialogue[1].sprt, (sfVector2f) {1130, 430});
    sfSprite_setPosition(rpg->dialogue[2].sprt, (sfVector2f) {1130, 430});
    sfSprite_setPosition(rpg->dialogue[3].sprt, (sfVector2f) {3400, 700});
    sfSprite_setPosition(rpg->dialogue[4].sprt, (sfVector2f) {3400, 700});
    sfSprite_setPosition(rpg->dialogue[5].sprt, (sfVector2f) {3400, 700});
    sfSprite_setPosition(rpg->dialogue[6].sprt, (sfVector2f) {2050, 1090});
    sfSprite_setPosition(rpg->dialogue[7].sprt, (sfVector2f) {2050, 1090});
    sfSprite_setPosition(rpg->dialogue[8].sprt, (sfVector2f) {2050, 1090});
    sfSprite_setPosition(rpg->dialogue[9].sprt, (sfVector2f) {1750, 1090});
    sfSprite_setPosition(rpg->dialogue[10].sprt, (sfVector2f) {1750, 1090});
    sfSprite_setPosition(rpg->dialogue[11].sprt, (sfVector2f) {1750, 1090});
    sfSprite_setPosition(rpg->dialogue[12].sprt, (sfVector2f) {1440, 1090});
    sfSprite_setPosition(rpg->dialogue[13].sprt, (sfVector2f) {1440, 1090});
    sfSprite_setPosition(rpg->dialogue[14].sprt, (sfVector2f) {1440, 1090});
    sfSprite_setPosition(rpg->dialogue[15].sprt, (sfVector2f) {1000, 450});
}

void create_dialogues(rpg_t *rpg)
{
    for (int i = 0; i < 16; i++) {
        rpg->dialogue[i].texture = sfTexture_createFromFile
        ("assets/dialogue.png", NULL);
        rpg->dialogue[i].sprt = sfSprite_create();
        sfSprite_setTexture
        (rpg->dialogue[i].sprt, rpg->dialogue[i].texture, sfFalse);
        sfSprite_scale(rpg->dialogue[i].sprt, (sfVector2f) {0.7, 0.7});
        rpg->dialogue[i].rect.width = 501;
        rpg->dialogue[i].rect.height = 142;
    }
    rect_dialogue(rpg);
    for (int i = 0; i < 16; i++)
        sfSprite_setTextureRect
        (rpg->dialogue[i].sprt, rpg->dialogue[i].rect);
    position_dialogue(rpg);
}
