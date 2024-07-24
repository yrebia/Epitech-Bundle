/*
** EPITECH PROJECT, 2022
** CREATE_TOWER
** File description:
** Function creating tower
*/

#include "../../include/my.h"

t_sprite *create_tower(char *path, sfVector2f pos, int top, int left)
{
    t_sprite *sprt = malloc(sizeof(t_sprite));
    sprt->texture = sfTexture_createFromFile(path, NULL);
    sprt->sprite = sfSprite_create();
    sprt->pos = pos; sprt->rect.left = left;
    sprt->rect.top = top;
    sprt->rect.height = 65; sprt->rect.width = 63;
    sprt->scale = (sfVector2f) {1.25, 1.25};
    sfSprite_setOrigin(sprt->sprite, (sfVector2f) {31.5, 32.5});
    sfSprite_setScale(sprt->sprite, sprt->scale);
    sfSprite_setTextureRect(sprt->sprite, sprt->rect);
    sfSprite_setPosition(sprt->sprite, sprt->pos);
    sfSprite_move(sprt->sprite, (sfVector2f) {31.5, 32.5});
    sfSprite_setTexture(sprt->sprite, sprt->texture, sfFalse);
    return (sprt);
}

void append_tower(t_game *game, int x, int y, int type)
{
    int top = 1, left = 0, rad = 0;
    float atq = 0, atqspd = 0;
    (type == TOWER1) ? left = 2, atq = 30, atqspd = 0.6, rad = 200 :
    (type == TOWER2) ? left = 71, atq = 55, atqspd = 1, rad = 250 :
    (type == TOWER3) ? left = 137, atq = 120, atqspd = 1.5, rad = 150 :
    (type == TOWER4) ? left = 205, atq = 75, atqspd = 2.5, rad = 500 :
    (type == TOWER5) ? left = 274, atq = 200, atqspd = 4, rad = 1000 : 0;
    if (type >= 1 && type <= 5) {
        t_tower *tower = malloc(sizeof(t_tower)); tower->next = game->towers;
        tower->sprite = create_tower("resources/towers.png",
        (sfVector2f) {x, y}, top, left);
        tower->stats = set_stats_t(atq, atqspd, rad); tower->target = 0;
        game->towers = tower;
        game->towers->sprite->animation = sfClock_create();
    }
}
