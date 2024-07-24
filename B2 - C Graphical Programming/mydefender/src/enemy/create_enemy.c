/*
** EPITECH PROJECT, 2022
** CREATE_ENEMY
** File description:
** Function creating enemys
*/

#include "../../include/my.h"

t_sprite *create_enemy(char *path, sfVector2f pos, int state, float vel)
{
    t_sprite *sprt = malloc(sizeof(t_sprite));
    sprt->texture = sfTexture_createFromFile(path, NULL);
    sprt->sprite = sfSprite_create(), sprt->state = state;
    sprt->velocity = (sfVector2f) {0, 0};
    sprt->scale = (sfVector2f) {2.5, 2.5};
    sprt->pos = pos, sprt->pos.y += 20;
    sprt->fastest = vel, sprt->offset = 24;
    sprt->rect.left = 0, sprt->rect.top = 0;
    sprt->rect.height = 24, sprt->rect.width = 24;
    sfSprite_setScale(sprt->sprite, sprt->scale);
    sfSprite_setTextureRect(sprt->sprite, sprt->rect);
    sfSprite_setPosition(sprt->sprite, sprt->pos);
    sfSprite_setTexture(sprt->sprite, sprt->texture, sfFalse);
    return (sprt);
}

t_sprite *create_life(char *path, sfVector2f pos, int c)
{
    t_sprite *sprt = malloc(sizeof(t_sprite));
    sprt->texture = sfTexture_createFromFile(path, NULL);
    sprt->sprite = sfSprite_create(),sprt->pos = pos;
    sfColor color;
    if (c == 0) sprt->scale = (sfVector2f) {0.11, 0.13}, color = sfBlack;
    else
        sprt->scale = (sfVector2f) {0.1, 0.1},
        color = sfColor_fromRGB(124, 252, 0);
    sprt->rect.left = 15, sprt->rect.top = 250;
    sprt->rect.height = 1000, sprt->rect.width = 1000;
    sfSprite_setScale(sprt->sprite, sprt->scale);
    sfSprite_setTextureRect(sprt->sprite, sprt->rect);
    sfSprite_setPosition(sprt->sprite, sprt->pos);
    sfSprite_setColor(sprt->sprite, color);
    sfSprite_setTexture(sprt->sprite, sprt->texture, sfFalse);
    return (sprt);
}

void append_enemys(t_game *game)
{
    t_enemy *enemy = malloc(sizeof(t_enemy)); enemy->next = game->enemys;
    float type = rand() % 5 + 1; char *path = NULL;
    (type == 1) ? path = "resources/Terminator.png",
    enemy->stats = set_stats_e(350, 200) : (type == 2) ?
    path = "resources/PurpleMage.png", enemy->stats = set_stats_e(250, 100) :
    (type == 3) ? path = "resources/CowboyCrab.png",
    enemy->stats = set_stats_e(100, 80) :
    (type == 4) ? path = "resources/WhiteFox.png",
    enemy->stats = set_stats_e(75, 50) :
    (type == 5) ? path = "resources/FastSquirrel.png",
    enemy->stats = set_stats_e(50, 100) : 0;
    enemy->dead = 0;
    enemy->sprite = create_enemy(path, game->spawn_pos, type, type / 2);
    enemy->bg_life = create_life("resources/life_bar.png",
    enemy->sprite->pos, 0);
    enemy->life_bar = create_life("resources/life_bar.png",
    enemy->sprite->pos, 1);
    game->enemys = enemy; game->enemys->sprite->animation = sfClock_create();
}

void start_wave(t_game *game)
{
    sfTime time = sfClock_getElapsedTime(game->spawn_clock);
    float sec = time.microseconds / 1000000.0;
    if (game->tmp_spawn < game->nbr_spawn && sec > 0.5)
        append_enemys(game), game->tmp_spawn++,
        sfClock_restart(game->spawn_clock);
    if (game->tmp_spawn == game->nbr_spawn)
        game->is_spawn = 0;
}

int enemy_len(t_game *game)
{
    int i = 0;
    t_enemy *tmp = game->enemys;
    while (tmp != 0) {
        if (tmp->dead != 1)
            i++;
        tmp = tmp->next;
    }
    return (i);
}
