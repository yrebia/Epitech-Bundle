/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** Change Volume
*/

#include "../../include/mystruct.h"

void volume_value(rpg_t *rpg, int value)
{
    rpg->options.volume = value;
    sfMusic_setVolume(rpg->musics.music_menu, value);
    char *volume = my_strcat("VOLUME: ", int_to_char(value));
    sfText_setString(rpg->text[0][10].text, volume);
    sfText_setString(rpg->text[1][10].text, volume);
}

void volume_switch_a(rpg_t *rpg)
{
    switch (rpg->options.volume) {
        case 90:
            volume_value(rpg, 100);
            break;
        case 80:
            volume_value(rpg, 90);
            break;
        case 70:
            volume_value(rpg, 80);
            break;
        case 60:
            volume_value(rpg, 70);
            break;
        case 50:
            volume_value(rpg, 60);
            break;
        case 40:
            volume_value(rpg, 50);
            break;
    }
}

void volume_switch_b(rpg_t *rpg)
{
    switch (rpg->options.volume) {
        case 30:
            volume_value(rpg, 40);
            break;
        case 20:
            volume_value(rpg, 30);
            break;
        case 10:
            volume_value(rpg, 20);
            break;
        case 0:
            volume_value(rpg, 10);
            break;
        case 100:
            volume_value(rpg, 0);
            break;
    }
}

void change_volume(rpg_t *rpg)
{
    if ((rpg->event.mouseButton.x >= 549 && rpg->event.mouseButton.y >= 415)
    && (rpg->event.mouseButton.x <= 949 && rpg->event.mouseButton.y <= 515)
    && rpg->menu_id == 3 && rpg->event.type == sfEvtMouseButtonReleased) {
        volume_switch_a(rpg);
        volume_switch_b(rpg);
    }
}
