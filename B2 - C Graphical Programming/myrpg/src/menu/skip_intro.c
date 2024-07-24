/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** Skip Intro
*/

#include "../../include/mystruct.h"

void set_press(rpg_t *rpg)
{
    for (int i = 0; i < 2; i++) {
        rpg->text_start[i].text = malloc(sizeof(rpg_t));
        rpg->text_start[i].text = sfText_create();
        rpg->text_start[i].police = sfFont_createFromFile
        ("assets/knight_of_light/Knight of Light.ttf");
        sfText_setCharacterSize(rpg->text_start[i].text, 80);
        sfText_setFont(rpg->text_start[i].text, rpg->text_start[i].police);
        sfText_setColor(rpg->text_start[i].text, sfBlack);
    }
    rpg->text_start[0].pos.x = 700, rpg->text_start[0].pos.y = -200;
    rpg->text_start[1].pos.x = 625, rpg->text_start[1].pos.y = -200;
    sfText_setPosition(rpg->text_start[0].text, rpg->text_start[0].pos);
    sfText_setPosition(rpg->text_start[1].text, rpg->text_start[1].pos);
    sfText_setString(rpg->text_start[0].text, "My RPG\0");
    sfText_setString(rpg->text_start[1].text, "Press Space To Continue\0");
}

void move_txt(rpg_t *rpg)
{
    if (rpg->text_start->seconds > 0.01) {
        if (rpg->text_start[0].pos.y < 400) {
            rpg->text_start[0].pos.y += 5;
            sfText_setPosition
            (rpg->text_start[0].text, rpg->text_start[0].pos);
        }
    }
}
