/*
** EPITECH PROJECT, 2022
** map
** File description:
** map
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "../include/my.h"

enemy_t *create_enemy(char *filepath, int vel, int x, int y)
{
    enemy_t *tmp = malloc(sizeof(enemy_t));
    sfVector2f origin;
    origin.x = 24, origin.y = 0;
    tmp->image = create_img(filepath, vel, x, y);
    tmp->image->scale.x = -7, tmp->image->scale.y = 7;
    sfSprite_setScale(tmp->image->sprite, tmp->image->scale);
    sfSprite_setOrigin(tmp->image->sprite, origin);
    tmp->image->rect.left = 408, tmp->image->rect.top = 0;
    tmp->image->rect.height = 24, tmp->image->rect.width = 24;
    tmp->image->offset = 1, tmp->image->clock = sfClock_create();
    return (tmp);
}

void init_enemy2(game_t *game, int i, enemy_t *enemy, enemy_t *tmp)
{
    int j = 0;
    while (game->map[i] != '\n') {
        if (game->map[i] == '1') {
            tmp = create_enemy("asset/enemy/blue.png", -12, (1920 + (j * 150)),
            730), tmp->next = enemy, enemy = tmp;
        }
        if (game->map[i] == '2') {
            tmp = create_enemy("asset/enemy/green.png", -12, (1920 + (j * 150)),
            730), tmp->next = enemy, enemy = tmp;
        }
        if (game->map[i] == '3') {
            tmp = create_enemy("asset/enemy/red.png", -12, (1920 + (j * 150)),
            730), tmp->next = enemy, enemy = tmp;
        }
        if (game->map[i] == '4')
            tmp = create_enemy("asset/enemy/yellow.png", -12, (1920 + (j *
            150)), 730), tmp->next = enemy, enemy = tmp;
        i++, j++;
    }
    game->enemys = enemy;
}

void init_enemy(game_t *game, char *filepath)
{
    int i = 0;
    enemy_t *enemy = malloc(sizeof(enemy_t));
    enemy_t *tmp;
    enemy = 0;
    if (load_file_in_mem(filepath, game) == 84)
        return;
    while (game->map[i] != '\n') {
        if (game->map[i] == '|')
            game->finish->pos.x = 1920 + (i * 150) - 50;
        i++;
    }
    i++;
    init_enemy2(game, i, enemy, tmp);
}

void init_enemy_infini(game_t *game)
{
    game->finish->pos.x = -500;
    enemy_t *enemy = malloc(sizeof(enemy_t));
    enemy_t *tmp;
    enemy = 0;
    tmp = create_enemy("asset/enemy/blue.png", -12, 2000, 730);
    tmp->next = enemy;
    enemy = tmp;
    tmp = create_enemy("asset/enemy/red.png", -12, 2500, 730);
    tmp->next = enemy;
    enemy = tmp;
    tmp = create_enemy("asset/enemy/green.png", -12, 2950, 730);
    tmp->next = enemy;
    enemy = tmp;
    tmp = create_enemy("asset/enemy/yellow.png", -12, 3500, 730);
    tmp->next = enemy;
    enemy = tmp;
    game->enemys = enemy;
}

void display_enemy(game_t *game)
{
    enemy_t *tmp = game->enemys;
    while (tmp != 0) {
        time_gestion_enemy(tmp->image, game);
        sfSprite_setTextureRect(tmp->image->sprite, tmp->image->rect);
        sfSprite_setPosition(tmp->image->sprite, tmp->image->pos);
        sfRenderWindow_drawSprite(game->wind, tmp->image->sprite, NULL);
        if (tmp->image->pos.x < game->player->pos.x + 100 && tmp->image->pos.x
            + 50 > game->player->pos.x && game->player->pos.y + 100 >
            tmp->image->pos.y) {
            sfMusic_stop(game->dead), sfMusic_play(game->dead);
            end_game(game, -1);
        }
        if (game->level != -1 && game->player->pos.x >
            game->finish->pos.x + 50) {
            sfMusic_stop(game->win_sfx), sfMusic_play(game->win_sfx);
            end_game(game, 1);
        }
        tmp = tmp->next;
    }
    game->finish->pos.x -= 12;
}
