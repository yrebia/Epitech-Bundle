/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** Language
*/

#include "../../include/mystruct.h"

void change_language(rpg_t *rpg)
{
    if ((rpg->event.mouseButton.x >= 542 && rpg->event.mouseButton.y >= 565)
    && (rpg->event.mouseButton.x <= 941 && rpg->event.mouseButton.y <= 657)
    && rpg->menu_id == 3 && rpg->event.type == sfEvtMouseButtonReleased) {
        if (rpg->options.language == 1)
            rpg->options.language = 0;
        else if (rpg->options.language == 0)
            rpg->options.language = 1;
    }
}
