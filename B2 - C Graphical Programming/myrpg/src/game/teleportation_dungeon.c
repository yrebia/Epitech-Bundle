/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** Teleportation
*/

#include "../../include/mystruct.h"

void change_map_coridor(rpg_t *rpg)
{
    sfVector2f pos = get_player_pos(rpg);
    int x = pos.x / 25 / 3;
    int y = pos.y / 25 / 3;
    rpg->loading = 1;
    rpg->map[y][x] = ' ', rpg->map[y - 1][x] = 'P';
    char *map = load_file("assets/map/dungeon_coridor.txt");
    rpg->map = make_map_from_str(map);
    rpg->bg->map = 3;
    rpg->bg->texture = sfTexture_createFromFile
    ("assets/map/dungeon.png", NULL);
    sfSprite_setTexture(rpg->bg->sprite, rpg->bg->texture, sfTrue);
    rpg->bg2->texture = sfTexture_createFromFile
    ("assets/map/dungeon_clock2.png", NULL);
    sfSprite_setTexture(rpg->bg2->sprite, rpg->bg2->texture, sfTrue);
    rpg->bg3->texture = sfTexture_createFromFile
    ("assets/map/dungeon_clock3.png", NULL);
    sfSprite_setTexture(rpg->bg3->sprite, rpg->bg3->texture, sfTrue);
}

void change_map_return_coridor(rpg_t *rpg)
{
    sfVector2f pos = get_player_pos(rpg);
    int x = pos.x / 25 / 3;
    int y = pos.y / 25 / 3;
    rpg->loading = 1;
    rpg->map[y][x] = ' ', rpg->map[y + 1][x] = 'P';
    char *map = load_file("assets/map/dungeon_back_doridor.txt");
    rpg->map = make_map_from_str(map);
    rpg->bg->map = 2;
    rpg->bg->texture = sfTexture_createFromFile
    ("assets/map/dungeon.png", NULL);
    sfSprite_setTexture(rpg->bg->sprite, rpg->bg->texture, sfTrue);
    rpg->bg2->texture = sfTexture_createFromFile
    ("assets/map/dungeon_clock2.png", NULL);
    sfSprite_setTexture(rpg->bg2->sprite, rpg->bg2->texture, sfTrue);
    rpg->bg3->texture = sfTexture_createFromFile
    ("assets/map/dungeon_clock3.png", NULL);
    sfSprite_setTexture(rpg->bg3->sprite, rpg->bg3->texture, sfTrue);
}

void change_map_room(rpg_t *rpg)
{
    sfVector2f pos = get_player_pos(rpg);
    int x = pos.x / 25 / 3;
    int y = pos.y / 25 / 3;
    rpg->loading = 1;
    rpg->map[y][x] = ' ', rpg->map[y][x + 1] = 'P';
    char *map = load_file("assets/map/dungeon_room.txt");
    rpg->map = make_map_from_str(map);
    rpg->bg->map = 3;
    rpg->bg->texture = sfTexture_createFromFile
    ("assets/map/dungeon.png", NULL);
    sfSprite_setTexture(rpg->bg->sprite, rpg->bg->texture, sfTrue);
    rpg->bg2->texture = sfTexture_createFromFile
    ("assets/map/dungeon_clock2.png", NULL);
    sfSprite_setTexture(rpg->bg2->sprite, rpg->bg2->texture, sfTrue);
    rpg->bg3->texture = sfTexture_createFromFile
    ("assets/map/dungeon_clock3.png", NULL);
    sfSprite_setTexture(rpg->bg3->sprite, rpg->bg3->texture, sfTrue);
}

void change_map_return_room(rpg_t *rpg)
{
    sfVector2f pos = get_player_pos(rpg);
    int x = pos.x / 25 / 3;
    int y = pos.y / 25 / 3;
    rpg->loading = 1;
    rpg->map[y][x] = ' ', rpg->map[y][x + 1] = 'P';
    char *map = load_file("assets/map/dungeon_back_room.txt");
    rpg->map = make_map_from_str(map);
    rpg->bg->map = 2;
    rpg->bg->texture = sfTexture_createFromFile
    ("assets/map/dungeon.png", NULL);
    sfSprite_setTexture(rpg->bg->sprite, rpg->bg->texture, sfTrue);
    rpg->bg2->texture = sfTexture_createFromFile
    ("assets/map/dungeon_clock2.png", NULL);
    sfSprite_setTexture(rpg->bg2->sprite, rpg->bg2->texture, sfTrue);
    rpg->bg3->texture = sfTexture_createFromFile
    ("assets/map/dungeon_clock3.png", NULL);
    sfSprite_setTexture(rpg->bg3->sprite, rpg->bg3->texture, sfTrue);
}

void change_map_return_forest(rpg_t *rpg)
{
    sfVector2f pos = get_player_pos(rpg);
    int x = pos.x / 25 / 3;
    int y = pos.y / 25 / 3;
    rpg->loading = 1;
    rpg->map[y][x] = ' ', rpg->map[y][x - 1] = 'P';
    char *map = load_file("assets/map/map_forest_new.txt");
    rpg->map = make_map_from_str(map);
    rpg->bg->map = 1;
    rpg->bg->texture = sfTexture_createFromFile
    ("assets/map/map_forest.png", NULL);
    sfSprite_setTexture(rpg->bg->sprite, rpg->bg->texture, sfTrue);
    rpg->bg2->texture = sfTexture_createFromFile
    ("assets/map/map_forest2.png", NULL);
    sfSprite_setTexture(rpg->bg2->sprite, rpg->bg2->texture, sfTrue);
    rpg->bg3->texture = sfTexture_createFromFile
    ("assets/map/map_forest3.png", NULL);
    sfSprite_setTexture(rpg->bg3->sprite, rpg->bg3->texture, sfTrue);
}