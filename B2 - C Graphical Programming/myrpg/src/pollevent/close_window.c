/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** Close Window
*/

#include "../../include/mystruct.h"

void setting_close_window(rpg_t *rpg)
{
    sfMusic_destroy(rpg->musics.music_menu);
    sfMusic_destroy(rpg->musics.run_song);
    sfMusic_destroy(rpg->musics.click_song);
    sfRenderWindow_close(rpg->window);
}

void close_window(rpg_t *rpg)
{
    if (rpg->event.type == sfEvtClosed) setting_close_window(rpg);

    if (rpg->event.key.code == sfKeyEscape && (rpg->menu_id == 1 ||
    rpg->menu_id == 2 || rpg->menu_id == 3 || rpg->menu_id == 4
    || rpg->menu_id == 5)) setting_close_window(rpg);

    if ((rpg->event.mouseButton.x >= 760 && rpg->event.mouseButton.y >= 715)
    && (rpg->event.mouseButton.x <= 1160 && rpg->event.mouseButton.y <= 815)
    && rpg->menu_id == 1 && rpg->event.type == sfEvtMouseButtonReleased)
        setting_close_window(rpg);
}
