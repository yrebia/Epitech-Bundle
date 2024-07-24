/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** Text
*/

#include "../../../include/mystruct.h"

void create_text(rpg_t *rpg)
{
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 31; j++) {
            rpg->text[i][j].text = malloc(sizeof(rpg_t));
            rpg->text[i][j].text = sfText_create();
            rpg->text[i][j].police = sfFont_createFromFile
            ("assets/knight_of_light/Knight of Light.ttf");
            sfText_setCharacterSize(rpg->text[i][j].text, 120);
            sfText_setFont(rpg->text[i][j].text,  rpg->text[i][j].police);
            sfText_setColor(rpg->text[i][j].text, sfBlack);
        }
        for (int j = 8; j < 14; j++) sfText_setCharacterSize
        (rpg->text[i][j].text, 100);
        for (int j = 16; j < 31; j++) sfText_setCharacterSize
        (rpg->text[i][j].text, 100);
    }
    text_french(rpg);
    text_english(rpg);
    text_french_position(rpg);
    text_english_position(rpg);
}
