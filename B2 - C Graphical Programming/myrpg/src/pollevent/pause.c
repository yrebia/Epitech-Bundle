/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** Pause
*/

#include "../../include/mystruct.h"

void pause_menu(rpg_t *rpg)
{
    if (rpg->event.key.code == sfKeyEscape && (rpg->menu_id == 6
    && rpg->pause_id == 0) && rpg->event.type == sfEvtKeyReleased)
        rpg->pause_id = 1;

    else if (rpg->event.key.code == sfKeyEscape && (rpg->menu_id == 6
    && rpg->pause_id == 1) && rpg->event.type == sfEvtKeyReleased)
        rpg->pause_id = 0;
}

void loose_game(rpg_t *rpg)
{
    if (rpg->loose != 0) {
        if (rpg->event.key.code == sfKeySpace &&
        rpg->event.type == sfEvtKeyReleased) {
            rpg->menu_id = 1;
            rpg->loose = 0;
        }
    }
}
