/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** Change Map
*/

#include "../../include/mystruct.h"

void change_map_spawn(rpg_t *rpg)
{
    sfVector2f pos = get_player_pos(rpg);
    int x = pos.x / 25 / 3;
    int y = pos.y / 25 / 3;
    rpg->loading = 1;
    rpg->map[y][x] = ' ', rpg->map[y - 1][x] = 'P';
    char *map = load_file("assets/map/map_spawn_new.txt");
    rpg->map = make_map_from_str(map);
    rpg->bg->map = 0;
    rpg->bg->texture = sfTexture_createFromFile
    ("assets/map/map_spawn.png", NULL);
    sfSprite_setTexture(rpg->bg->sprite, rpg->bg->texture, sfTrue);
    rpg->bg2->texture = sfTexture_createFromFile
    ("assets/map/map_spawn2.png", NULL);
    sfSprite_setTexture(rpg->bg2->sprite, rpg->bg2->texture, sfTrue);
    rpg->bg3->texture = sfTexture_createFromFile
    ("assets/map/map_spawn3.png", NULL);
    sfSprite_setTexture(rpg->bg3->sprite, rpg->bg3->texture, sfTrue);
}

void change_map_dungeon(rpg_t *rpg)
{
    sfVector2f pos = get_player_pos(rpg);
    int x = pos.x / 25 / 3;
    int y = pos.y / 25 / 3;
    rpg->loading = 1;
    rpg->map[y][x] = ' ', rpg->map[y - 1][x] = 'P';
    char *map = load_file("assets/map/dungeon.txt");
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

void change_map_forest(rpg_t *rpg)
{
    sfVector2f pos = get_player_pos(rpg);
    int x = pos.x / 25 / 3;
    int y = pos.y / 25 / 3;
    rpg->map[y][x] = ' ', rpg->map[y - 1][x] = 'P';
    char *map = load_file("assets/map/map_forest.txt");
    rpg->map = make_map_from_str(map);
    rpg->loading = 1;
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

void set_life_bar(rpg_t *rpg, sfVector2f pos)
{
    if (rpg->player->hp <= 0) rpg->player->hp = 0;
    rpg->life_bar->pos.x = pos.x - 190, rpg->life_bar->pos.y = pos.y + 350;
    rpg->life_bar_back->pos.x = pos.x - 200;
    rpg->life_bar_back->pos.y = pos.y + 345;
    sfSprite_setPosition(rpg->life_bar->sprite, rpg->life_bar->pos);
    sfSprite_setPosition(rpg->life_bar_back->sprite, rpg->life_bar_back->pos);
    rpg->life_bar->scale.x = (rpg->player->hp / 100.0) * 1.015;
    sfSprite_setScale(rpg->life_bar->sprite, rpg->life_bar->scale);
    if (rpg->player->hp <= 33)
        sfSprite_setColor(rpg->life_bar->sprite, sfRed);
    else if (rpg->player->hp <= 66)
        sfSprite_setColor(rpg->life_bar->sprite, sfColor_fromRGB(255, 140, 0));
    else
        sfSprite_setColor(rpg->life_bar->sprite, sfGreen);
}
