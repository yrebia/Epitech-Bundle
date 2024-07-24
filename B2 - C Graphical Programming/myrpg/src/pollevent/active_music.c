/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** Active Muisic
*/

#include "../../include/mystruct.h"

void active_music(rpg_t *rpg)
{
    if ((rpg->event.mouseButton.x >= 971 && rpg->event.mouseButton.y >= 415)
    && (rpg->event.mouseButton.x <= 1371 && rpg->event.mouseButton.y <= 515)
    && rpg->menu_id == 3 && rpg->event.type == sfEvtMouseButtonReleased) {
        if (rpg->options.music == false) {
            sfMusic_play(rpg->musics.music_menu);
            rpg->options.music = true;
            sfText_setString(rpg->text[0][11].text, "MUSIQUE: ON\0");
            sfText_setString(rpg->text[1][11].text, "MUSIC: ON\0");
            return;
        }
        if (rpg->options.music == true) {
            sfMusic_stop(rpg->musics.music_menu);
            rpg->options.music = false;
            sfText_setString(rpg->text[0][11].text, "MUSIQUE: OFF\0");
            sfText_setString(rpg->text[1][11].text, "MUSIC: OFF\0");
            return;
        }
    }
}

void set_camera(rpg_t *rpg)
{
    if (rpg->loading == 0 && rpg->loose == 0) {
        sfVector2f pos = rpg->player->pos;
        if (pos.x - 960 < 0)
            pos.x = 960;
        if (pos.x + 100 > 2890)
            pos.x = 2790;
        if (pos.y - 540 < 0)
            pos.y = 540;
        if (pos.y + 100 > 3280)
            pos.y = 3180;
        sfView_setCenter(rpg->view, pos);
        sfRenderWindow_setView(rpg->window, rpg->view);
        set_life_bar(rpg, pos);
    }
}
