/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** Initialisation
*/

#include "../../include/mystruct.h"

void init_ennemies_loop(rpg_t *rpg, int x, int y)
{
    while (rpg->map[y][x] != '\0') {
            if (rpg->map[y][x] == 'S' || rpg->map[y][x] == 'O'
            || rpg->map[y][x] == 'L')
                append_enemies(rpg, x, y, 0);
            x++;
        }
}

void init_ennemies_second_loop(rpg_t *rpg, char **map2, int x, int y)
{
    while (map2[y][x] != '\0') {
            if (map2[y][x] == 'S' || map2[y][x] == 'O' || map2[y][x] == 'L')
                append_enemies(rpg, x, y, 1);
            x++;
        }
}

void init_enemies(rpg_t *rpg)
{
    int x = 0;
    int y = 0;
    rpg->enemies = NULL;
    char *map_txt = load_file("assets/map/map_forest.txt");
    char **map2 = make_map_from_str(map_txt);
    while (rpg->map[y] != 0) {
        init_ennemies_loop(rpg, x, y);
        y++, x = 0;
    }
    y = 0, x = 0;
    while (map2[y] != 0) {
        init_ennemies_second_loop(rpg, map2, x, y);
        y++, x = 0;
    }
}
