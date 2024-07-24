/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** Update Main Menu
*/

#include "../../include/mystruct.h"

void update_main_menu(rpg_t *rpg)
{
    if (rpg->menu_id == 1) {
        for (int i = 0; i < 4; i++)
            sfRenderWindow_drawSprite(rpg->window, rpg->menu[0][i].sprt, NULL),
            sfRenderWindow_drawText
            (rpg->window, rpg->text[rpg->options.language][i].text, NULL);
    }
    if (rpg->menu_id == 2) {
        for (int i = 0; i < 4; i++)
            sfRenderWindow_drawSprite(rpg->window, rpg->menu[1][i].sprt, NULL);
        for (int i = 4; i < 8; i++)
            sfRenderWindow_drawText
            (rpg->window, rpg->text[rpg->options.language][i].text, NULL);
    }
    if (rpg->menu_id == 3) {
        for (int i = 0; i < 7; i++)
            sfRenderWindow_drawSprite(rpg->window, rpg->menu[2][i].sprt, NULL);
        for (int i = 8; i < 15; i++)
            sfRenderWindow_drawText
            (rpg->window, rpg->text[rpg->options.language][i].text, NULL);
    }
}

void update_guide_menu(rpg_t *rpg)
{
    if (rpg->menu_id == 4) {
        sfRenderWindow_drawSprite(rpg->window, rpg->menu[3][0].sprt, NULL);
        if (rpg->options.language == 0)
            sfRenderWindow_drawSprite(rpg->window, rpg->menu[3][1].sprt, NULL);
        else if (rpg->options.language == 1)
            sfRenderWindow_drawSprite(rpg->window, rpg->menu[3][2].sprt, NULL);
        sfRenderWindow_drawSprite(rpg->window, rpg->menu[3][3].sprt, NULL);
        sfRenderWindow_drawText
        (rpg->window, rpg->text[rpg->options.language][15].text, NULL);
    }
}

void update_keys_menu(rpg_t *rpg)
{
    if (rpg->menu_id == 5) {
        for (int i = 0; i < 12; i++)
            sfRenderWindow_drawSprite(rpg->window, rpg->menu[5][i].sprt, NULL);
        for (int i = 16; i < 27; i++)
            sfRenderWindow_drawText
            (rpg->window, rpg->text[rpg->options.language][i].text, NULL);
    }
}
