/*
** EPITECH PROJECT, 2022
** GENERATE_MAP
** File description:
** Function generating maps
*/

#include "../include/my.h"

t_sprite *create_tile(char *path, int x, int y, int state)
{
    t_sprite *sprt = malloc(sizeof(t_sprite));

    sprt->state = state;
    sprt->pos = (sfVector2f) {420 + x * 67.5, y * 67.5};
    sprt->texture = sfTexture_createFromFile(path, NULL);
    sprt->sprite = sfSprite_create();
    sprt->scale = (sfVector2f) {0.9375, 0.9375};
    sfSprite_setScale(sprt->sprite, sprt->scale);
    sfSprite_setPosition(sprt->sprite, sprt->pos);
    sfSprite_setTexture(sprt->sprite, sprt->texture, sfFalse);
    return (sprt);
}

void generate_map(t_game *game)
{
    int i = 0, y = 0; t_sprite ***test = malloc(sizeof(t_sprite **) * 15);
    for (int i = 0; i < 15; i++) test[i] = malloc(sizeof(t_sprite *) * 15);
    while (y < 15) { for (int x = 0; x < 15; x++) {
            (game->smap[i] == ' ') ? test[y][x] =
            create_tile("resources/Tile.png", x, y, GRASS) : 0;
            (game->smap[i] == '.') ? test[y][x] =
            create_tile("resources/PATH.png", x, y, PATH) : 0;
            (game->smap[i] == '#') ? test[y][x] =
            create_tile("resources/Wall.png", x, y, WALL) : 0;
            (game->smap[i] == '0') ? test[y][x] =
            create_tile("resources/SPAWN.png", x, y, SPAWN) : 0;
            (game->smap[i] == '0') ? game->spawn_pos.x = x * 67.5 + 386.5 : 0;
            (game->smap[i] == '0') ? game->spawn_pos.y = y * 67.5 - 33.5 : 0;
            (game->smap[i] == '1') ? test[y][x] =
            create_tile("resources/Castle.png", x, y, 2) : 0;
            i++;
        } i++, y++;
    } game->sprtmap = test;
}
