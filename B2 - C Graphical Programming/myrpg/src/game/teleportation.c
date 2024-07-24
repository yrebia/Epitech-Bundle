/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** Teleportation
*/

#include "../../include/mystruct.h"

void all_tp(rpg_t *rpg)
{
    sfVector2f pos = get_player_pos(rpg);
    int x = pos.x / 25 / 3;
    int y = pos.y / 25 / 3;
    if (y > 0 && rpg->map[y - 1][x] == ' ')
        rpg->map[y][x] = ' ', rpg->map[y - 1][x] = 'P';
    if (y > 0 && rpg->map[y - 1][x] == 'T' && rpg->bg->map == 0)
        change_map_forest(rpg);
    if (y > 0 && rpg->map[y - 1][x] == 'T' && rpg->bg->map == 1)
        change_map_spawn(rpg);
    if (y > 0 && rpg->map[y - 1][x] == 'D' && rpg->bg->map == 1)
        change_map_dungeon(rpg);
    if (y > 0 && rpg->map[y - 1][x] == 'M' && rpg->bg->map == 2)
        change_map_coridor(rpg);
}

void all_tp2(rpg_t *rpg)
{
    sfVector2f pos = get_player_pos(rpg);
    int x = pos.x / 25 / 3;
    int y = pos.y / 25 / 3;
    if (y > 0 && rpg->map[y][x + 1] == ' ')
        rpg->map[y][x] = ' ', rpg->map[y][x + 1] = 'P';
    if (y > 0 && rpg->map[y][x + 1] == 'E' && rpg->bg->map == 2)
        change_map_return_room(rpg);
    if (y > 0 && rpg->map[y][x + 1] == 'E' && rpg->bg->map == 3)
        change_map_room(rpg);
}

void all_tp3(rpg_t *rpg)
{
    sfVector2f pos = get_player_pos(rpg);
    int x = pos.x / 25 / 3;
    int y = pos.y / 25 / 3;
    if (y > 0 && rpg->map[y + 1][x] == 'M' && rpg->bg->map == 3)
        change_map_return_coridor(rpg);
    if (y > 0 && rpg->map[y + 1][x] == ' ')
        rpg->map[y][x] = ' ', rpg->map[y + 1][x] = 'P';
}

void all_tp4(rpg_t *rpg)
{
    sfVector2f pos = get_player_pos(rpg);
    int x = pos.x / 25 / 3;
    int y = pos.y / 25 / 3;
    if (y > 0 && rpg->map[y][x - 1] == ' ')
        rpg->map[y][x] = ' ', rpg->map[y][x - 1] = 'P';
    if (y > 0 && rpg->map[y][x - 1] == 'F' && rpg->bg->map == 2)
        change_map_return_forest(rpg);
}
