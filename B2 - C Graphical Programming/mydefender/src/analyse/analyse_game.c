/*
** EPITECH PROJECT, 2022
** ANALYSE_GAME
** File description:
** Functions analyzing game
*/

#include "../../include/my.h"

void analyse_selection(t_game *game)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(game->window);
    int x = (pos.x - 420) / 67.5, y = pos.y / 67.5;
    if (x < 0 || x > 14 || y < 0 || y > 14) return;
    game->selection->pos.x = game->sprtmap[y][x]->pos.x;
    game->selection->pos.y = game->sprtmap[y][x]->pos.y;
    sfSprite_setPosition(game->selection->sprite, game->selection->pos);
    if (game->sprtmap[y][x]->state == GRASS)
        game->tilestate = GRASS, game->tower_menu = 0;
    if (game->sprtmap[y][x]->state == WALL)
        game->tilestate = WALL, game->tower_menu = 1,
        game->tower_pos = (sfVector2f) {x * 67.5 + 420, y * 67.5};
    if (game->sprtmap[y][x]->state == PATH)
        game->tilestate = PATH, game->tower_menu = 0;
    if (game->sprtmap[y][x]->state == CASTLE)
        game->tilestate = CASTLE, game->tower_menu = 0;
    if (game->sprtmap[y][x]->state == SPAWN)
        game->tilestate = SPAWN, game->tower_menu = 0;
}

void analyse_game(t_game *game)
{
    sfVector2i mp = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f pos = game->buttons[0]->pos;
    if (game->event.type == sfEvtMouseButtonPressed) analyse_selection(game);
    if (game->event.type == sfEvtMouseButtonReleased) {
        if (mp.x >= pos.x && mp.x <= (pos.x + 290) && mp.y >= pos.y
            && mp.y <= (pos.y + 98)) game->gamestate = MENU,
            sfMusic_stop(game->music->game), sfMusic_play(game->music->menu);
        pos = game->buttons[1]->pos;
        if (mp.x >= pos.x && mp.x <= (pos.x + 290) && mp.y >= pos.y
            && mp.y <= (pos.y + 98)) game->gamestate = PAUSE;
        pos = game->buttons[2]->pos;
        if (enemy_len(game) == 0 && mp.x >= pos.x && mp.x <= (pos.x + 290)
            && mp.y >= pos.y && mp.y <= (pos.y + 98)) game->wave_nbr += 1,
        game->tmp_spawn = 0, game->nbr_spawn *= 1.5, game->is_spawn = 1;
        (game->tower_menu == 1) ? analyse_towers(game) : 0;
    } if (game->event.type == sfEvtKeyPressed
        && sfKeyboard_isKeyPressed(sfKeyEscape) == TRUE)
        game->gamestate = PAUSE;
}
