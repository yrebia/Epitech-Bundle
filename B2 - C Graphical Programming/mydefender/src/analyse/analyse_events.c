/*
** EPITECH PROJECT, 2022
** ANALYSE_EVENTS
** File description:
** Function analyzing events
*/

#include "../../include/my.h"

void analyse_pause1(t_game *game, sfVector2i mouse_pos)
{
    if (game->event.type == sfEvtMouseButtonPressed) {
        if (mouse_pos.x >= game->pause->buttons[3]->pos.x
            && mouse_pos.x <= (game->pause->buttons[3]->pos.x + 290)
            && mouse_pos.y >= game->pause->buttons[3]->pos.y
            && mouse_pos.y <= (game->pause->buttons[3]->pos.y + 98))
            destroy_music_sfx(game), sfRenderWindow_close(game->window);
    }
}

void analyse_pause(t_game *game)
{
    if (game->event.type == sfEvtKeyPressed
        && sfKeyboard_isKeyPressed(sfKeyEscape) == TRUE)
        game->gamestate = GAME, sfMusic_stop(game->music->menu),
        sfMusic_play(game->music->game);
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window);
    if (game->event.type == sfEvtMouseButtonPressed) {
        if (mouse_pos.x >= game->pause->buttons[0]->pos.x
            && mouse_pos.x <= (game->pause->buttons[0]->pos.x + 290)
            && mouse_pos.y >= game->pause->buttons[0]->pos.y
            && mouse_pos.y <= (game->pause->buttons[0]->pos.y + 98))
            game->gamestate = GAME;
        if (mouse_pos.x >= game->pause->buttons[2]->pos.x
            && mouse_pos.x <= (game->pause->buttons[2]->pos.x + 290)
            && mouse_pos.y >= game->pause->buttons[2]->pos.y
            && mouse_pos.y <= (game->pause->buttons[2]->pos.y + 98))
            game->gamestate = MENU, sfMusic_stop(game->music->game),
            sfMusic_play(game->music->menu);
    } analyse_pause1(game, mouse_pos);
}

void analyse_events(t_game *game)
{
    if (game->event.type == sfEvtClosed)
        destroy_music_sfx(game), sfRenderWindow_close(game->window);
    if (game->event.key.code == sfKeyDelete)
        destroy_music_sfx(game), sfRenderWindow_close(game->window);
    if (game->gamestate == MENU) {
        analyse_menu(game);
        return;
    }
    if (game->gamestate == GAME) {
        analyse_game(game);
        return;
    }
    if (game->gamestate == PAUSE) {
        analyse_pause(game);
        return;
    }
}
