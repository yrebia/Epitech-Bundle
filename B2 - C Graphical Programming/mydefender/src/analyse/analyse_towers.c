/*
** EPITECH PROJECT, 2022
** ANALYSE_TOWERS
** File description:
** Functions analyzing towers
*/

#include "../../include/my.h"

void analyse_towers2(t_game *game, sfVector2i mp, int x, int y)
{
    int tx = game->towmenu[0][4]->pos.x, ty = game->towmenu[0][4]->pos.y;
    if (game->money >= game->tower_prices[4] && mp.x >= tx && mp.x <= tx + 105
        && mp.y >= ty && mp.y <= ty + 105)
        append_tower(game, game->tower_pos.x, game->tower_pos.y, TOWER5),
        game->tower_menu = 0, game->sprtmap[y][x]->state = USED,
        game->money -= game->tower_prices[4];
}

void analyse_towers1(t_game *game, sfVector2i mp, int x, int y)
{
    int tx = game->towmenu[0][2]->pos.x, ty = game->towmenu[0][2]->pos.y;
    if (game->money >= game->tower_prices[2] && mp.x >= tx && mp.x <= tx + 105
        && mp.y >= ty && mp.y <= ty + 105)
        append_tower(game, game->tower_pos.x, game->tower_pos.y, TOWER3),
        game->tower_menu = 0, game->sprtmap[y][x]->state = USED,
        game->money -= game->tower_prices[2];
    tx = game->towmenu[0][3]->pos.x, ty = game->towmenu[0][3]->pos.y;
    if (game->money >= game->tower_prices[3] && mp.x >= tx && mp.x <= tx + 105
        && mp.y >= ty && mp.y <= ty + 105)
        append_tower(game, game->tower_pos.x, game->tower_pos.y, TOWER4),
        game->tower_menu = 0, game->sprtmap[y][x]->state = USED,
        game->money -= game->tower_prices[3];
    analyse_towers2(game, mp, x, y);
}

void analyse_towers(t_game *game)
{
    sfVector2i mp = sfMouse_getPositionRenderWindow(game->window);
    int x = (game->tower_pos.x - 420) / 67.5, y = game->tower_pos.y / 67.5;
    int tx = game->towmenu[0][0]->pos.x, ty = game->towmenu[0][0]->pos.y;
    if (game->money >= game->tower_prices[0] && mp.x >= tx && mp.x <= tx + 105
        && mp.y >= ty && mp.y <= ty + 105)
        append_tower(game, game->tower_pos.x, game->tower_pos.y, TOWER1),
        game->tower_menu = 0, game->sprtmap[y][x]->state = USED,
        game->money -= game->tower_prices[0];
    tx = game->towmenu[0][1]->pos.x, ty = game->towmenu[0][1]->pos.y;
    if (game->money >= game->tower_prices[1] && mp.x >= tx && mp.x <= tx + 105
        && mp.y >= ty && mp.y <= ty + 105)
        append_tower(game, game->tower_pos.x, game->tower_pos.y, TOWER2),
        game->tower_menu = 0, game->sprtmap[y][x]->state = USED,
        game->money -= game->tower_prices[1];
    analyse_towers1(game, mp, x, y);
}
