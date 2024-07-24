/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** Size & FPS
*/

#include "../../include/mystruct.h"

void change_to_fullscreen(rpg_t *rpg)
{
    sfRenderWindow_destroy(rpg->window);
    sfVideoMode mode = {1920, 1080, 32};
    rpg->window = sfRenderWindow_create(mode,
    "RPG", sfClose, NULL);
    sfRenderWindow_setMouseCursorVisible(rpg->window, sfFalse);
    rpg->options.fullscreen = false;
    sfText_setString(rpg->text[0][8].text, "FENETRE\0");
    sfText_setPosition(rpg->text[0][8].text, (sfVector2f) {630, 250});
    sfText_setString(rpg->text[1][8].text, "WINDOWED\0");
    sfText_setPosition(rpg->text[1][8].text, (sfVector2f) {600, 250});
    return;
}

void change_to_windowed(rpg_t *rpg)
{
    sfRenderWindow_destroy(rpg->window);
    sfVideoMode mode = {1920, 1080, 32};
    rpg->window = sfRenderWindow_create(mode,
    "RPG", sfClose | sfFullscreen, NULL);
    sfRenderWindow_setMouseCursorVisible(rpg->window, sfFalse);
    rpg->options.fullscreen = true;
    sfText_setString(rpg->text[0][8].text, "PLEIN ECRAN\0");
    sfText_setPosition(rpg->text[0][8].text, (sfVector2f) {570, 250});
    sfText_setString(rpg->text[1][8].text, "FULLSCREEN\0");
    sfText_setPosition(rpg->text[1][8].text, (sfVector2f) {570, 250});
    return;
}

void change_size(rpg_t *rpg)
{
    if ((rpg->event.mouseButton.x >= 549 && rpg->event.mouseButton.y >= 265)
    && (rpg->event.mouseButton.x <= 949 && rpg->event.mouseButton.y <= 365)
    && rpg->menu_id == 3 && rpg->event.type == sfEvtMouseButtonReleased) {
        if (rpg->options.fullscreen == true) {
            change_to_fullscreen(rpg);
        }
        else if (rpg->options.fullscreen == false) {
            change_to_windowed(rpg);
        }
    }
}

void set_str_fps(rpg_t *rpg)
{
    if (rpg->options.fps > 30 && rpg->options.fps <= 60) {
        rpg->options.fps += 60;
        sfText_setString(rpg->text[0][9].text, "FPS: 120\0");
        sfText_setString(rpg->text[1][9].text, "FPS: 120\0");
        return;
    }
    if (rpg->options.fps <= 30) {
        rpg->options.fps += 30;
        sfText_setString(rpg->text[0][9].text, "FPS: 60\0");
        sfText_setString(rpg->text[1][9].text, "FPS: 60\0");
        return;
    }
    if (rpg->options.fps >= 120) {
        rpg->options.fps = 30;
        sfText_setString(rpg->text[0][9].text, "FPS: 30\0");
        sfText_setString(rpg->text[1][9].text, "FPS: 30\0");
        return;
    }
}

void change_fps(rpg_t *rpg)
{
    if ((rpg->event.mouseButton.x >= 971 && rpg->event.mouseButton.y >= 265)
    && (rpg->event.mouseButton.x <= 1371 && rpg->event.mouseButton.y <= 365)
    && rpg->menu_id == 3 && rpg->event.type == sfEvtMouseButtonReleased) {
        set_str_fps(rpg);
        sfRenderWindow_setFramerateLimit(rpg->window,
        rpg->options.fps);
    }
}
