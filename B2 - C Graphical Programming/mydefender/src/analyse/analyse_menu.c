/*
** EPITECH PROJECT, 2022
** ANALYSE_MENU
** File description:
** Function analyzing the menu
*/

#include "../../include/my.h"

void analyse_menu4(t_game *game, int pass, sfVector2i mouse_pos)
{
    for (int i = 0; i < 4; i++) {
        if (game->event.type == sfEvtMouseButtonReleased)
            sfText_setColor(game->menu->texts[i]->text,
            sfColor_fromRGB(60, 60, 60));
    }
    if (pass == 0)
        game->menu->hover = 0;
    if (mouse_pos.x >= 0 && mouse_pos.x <= 20
        && mouse_pos.y >= 0 && mouse_pos.y <= 20)
        if (game->event.type == sfEvtMouseButtonPressed)
            game->menu->menustate = WELCOME;

    if (game->menu->menustate == PLAY)
        analyse_play(game, mouse_pos);
}

void analyse_menu3(t_game *game, int pass, sfVector2i mouse_pos)
{
    if (mouse_pos.x >= (game->menu->texts[3]->pos.x - 95)
        && mouse_pos.x <= (game->menu->texts[3]->pos.x + 505)
        && mouse_pos.y >= (game->menu->texts[3]->pos.y - 55)
        && mouse_pos.y <= (game->menu->texts[3]->pos.y + 100)) {
        game->menu->hover = 1; pass = 1;
        sfSprite_setPosition(game->menu->selection[0]->sprite,
        (sfVector2f) {210, 730});
        if (game->event.type == sfEvtMouseButtonPressed)
            sfText_setColor(game->menu->texts[3]->text, sfWhite);
        if (game->event.type == sfEvtMouseButtonReleased)
            destroy_music_sfx(game), sfRenderWindow_close(game->window);
    }
    analyse_menu4(game, pass, mouse_pos);
}

void analyse_menu2(t_game *game, int pass, sfVector2i mouse_pos)
{
    if (mouse_pos.x >= (game->menu->texts[2]->pos.x - 95)
    && mouse_pos.x <= (game->menu->texts[2]->pos.x + 505)
    && mouse_pos.y >= (game->menu->texts[2]->pos.y - 55)
    && mouse_pos.y <= (game->menu->texts[2]->pos.y + 100)) {
        game->menu->hover = 1; pass = 1;
        sfSprite_setPosition(game->menu->selection[0]->sprite,
        (sfVector2f) {210, 540});
        if (game->event.type == sfEvtMouseButtonPressed)
            sfText_setColor(game->menu->texts[2]->text, sfWhite);
        if (game->event.type == sfEvtMouseButtonReleased)
            game->menu->menustate = HTP;
    }
    analyse_menu3(game, pass, mouse_pos);
}

void analyse_menu1(t_game *game, int pass, sfVector2i mouse_pos)
{
    if (mouse_pos.x >= (game->menu->texts[1]->pos.x - 95)
    && mouse_pos.x <= (game->menu->texts[1]->pos.x + 505)
    && mouse_pos.y >= (game->menu->texts[1]->pos.y - 55)
    && mouse_pos.y <= (game->menu->texts[1]->pos.y + 120)) {
        game->menu->hover = 1; pass = 1;
        sfSprite_setPosition(game->menu->selection[0]->sprite,
        (sfVector2f) {210, 350});
        if (game->event.type == sfEvtMouseButtonPressed)
            sfText_setColor(game->menu->texts[1]->text, sfWhite);
        if (game->event.type == sfEvtMouseButtonReleased)
            game->menu->menustate = OPTIONS;
    }
    analyse_menu2(game, pass, mouse_pos);
}

void analyse_menu(t_game *game)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window);
    int pass = 0;
    if (mouse_pos.x >= (game->menu->texts[0]->pos.x - 95)
    && mouse_pos.x <= (game->menu->texts[0]->pos.x + 505)
    && mouse_pos.y >= (game->menu->texts[0]->pos.y - 55)
    && mouse_pos.y <= (game->menu->texts[0]->pos.y + 120)) {
        game->menu->hover = 1; pass = 1;
        sfSprite_setPosition(game->menu->selection[0]->sprite,
        (sfVector2f) {210, 160});
        if (game->event.type == sfEvtMouseButtonPressed)
            sfText_setColor(game->menu->texts[0]->text, sfWhite);
        if (game->event.type == sfEvtMouseButtonReleased)
            game->menu->menustate = PLAY;
    }
    analyse_menu1(game, pass, mouse_pos);
    if (game->menu->menustate == OPTIONS)
        analyse_option(game);
    return;
}
