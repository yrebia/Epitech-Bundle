/*
** EPITECH PROJECT, 2022
** init menu
** File description:
** init menu
*/

#include "../include/my.h"

void init_skin(image_t *skin)
{
    skin->scale.x = 5, skin->scale.y = 5;
    sfSprite_setScale(skin->sprite, skin->scale);
    skin->rect.left = 0, skin->rect.top = 0;
    skin->rect.height = 32, skin->rect.width = 32;
    skin->offset = 1, skin->clock = sfClock_create();
    skin->j_clock = sfClock_create(), skin->is_jump = 0;
}

void set_position_menu2(game_t *game)
{
    sfSprite_setPosition(game->s_level->home->sprite,
        game->s_level->home->pos);
    sfSprite_setPosition(game->s_menu->button[0]->sprite,
        game->s_menu->button[0]->pos);
    sfSprite_setPosition(game->s_menu->button[1]->sprite,
        game->s_menu->button[1]->pos);
}

void set_position_menu(game_t *game)
{
    sfSprite_setPosition(game->s_level->button[0]->sprite,
        game->s_level->button[0]->pos);
    sfSprite_setPosition(game->s_level->button[1]->sprite,
        game->s_level->button[1]->pos);
    sfSprite_setPosition(game->s_level->button[2]->sprite,
        game->s_level->button[2]->pos);
    sfSprite_setPosition(game->s_level->button[3]->sprite,
        game->s_level->button[3]->pos);
    sfSprite_setPosition(game->s_menu->sound[0]->sprite,
        game->s_menu->sound[0]->pos);
    sfSprite_setPosition(game->s_menu->sound[1]->sprite,
        game->s_menu->sound[1]->pos);
    sfSprite_setPosition(game->s_menu->screen[0]->sprite,
        game->s_menu->screen[0]->pos);
    sfSprite_setPosition(game->s_menu->screen[1]->sprite,
        game->s_menu->screen[1]->pos);
    sfSprite_setPosition(game->s_menu->exit->sprite,
        game->s_menu->exit->pos);
    set_position_menu2(game);
}

void init_level_menu(game_t *game)
{
    level_t *level_m = malloc(sizeof(level_t));
    level_m->button[0] = create_img("asset/menu/button.png", 0, 400, 200);
    level_m->button[1] = create_img("asset/menu/button.png", 0, 1000, 200);
    level_m->button[2] = create_img("asset/menu/button.png", 0, 400, 500);
    level_m->button[3] = create_img("asset/menu/button.png", 0, 1000, 500);
    level_m->home = create_img("asset/menu/home.png", 0, 50, 50);
    level_m->home->scale.x = 0.2, level_m->home->scale.y = 0.2;
    sfSprite_setScale(level_m->home->sprite, level_m->home->scale);
    if (game->bonus == 1)
        level_m->button[5] = create_img("asset/menu/button.png", 0, 700, 800);
    else if (game->bonus == -1)
        level_m->button[4] = create_img("asset/menu/button.png", 0, 700, 800);
    game->s_level = level_m;
    if (game->bonus == -1)
        sfSprite_setPosition(game->s_level->button[4]->sprite,
            game->s_level->button[4]->pos);
    else if (game->bonus == 1)
        sfSprite_setPosition(game->s_level->button[5]->sprite,
            game->s_level->button[5]->pos);
}

void init_menu(game_t *game)
{
    menu_t *menu = malloc(sizeof(menu_t));
    menu->button[0] = create_img("asset/menu/button.png", 0, 700, 600);
    menu->button[1] = create_img("asset/menu/button.png", 0, 700, 350);
    menu->sound[0] = create_img("asset/menu/sound_on.png", 0, 1750, 50);
    menu->sound[1] = create_img("asset/menu/sound_off.png", 0, 1745, 55);
    menu->screen[0] = create_img("asset/menu/screen.png", 0, 1550, 50);
    menu->screen[1] = create_img("asset/menu/full_screen.png", 0, 1550, 50);
    menu->exit = create_img("asset/menu/exit.png", 0, 50, 50);
    menu->sound[0]->scale.x = 0.05, menu->sound[0]->scale.y = 0.05;
    menu->sound[1]->scale.x = 0.2, menu->sound[1]->scale.y = 0.2;
    menu->screen[0]->scale.x = 0.6, menu->screen[0]->scale.y = 0.6;
    menu->screen[1]->scale.x = 0.2, menu->screen[1]->scale.y = 0.2;
    menu->exit->scale.x = 0.2, menu->exit->scale.y = 0.2;
    sfSprite_setScale(menu->sound[0]->sprite, menu->sound[0]->scale);
    sfSprite_setScale(menu->sound[1]->sprite, menu->sound[1]->scale);
    sfSprite_setScale(menu->screen[0]->sprite, menu->screen[0]->scale);
    sfSprite_setScale(menu->screen[1]->sprite, menu->screen[1]->scale);
    sfSprite_setScale(menu->exit->sprite, menu->exit->scale);
    game->s_menu = menu;
    init_level_menu(game), set_position_menu(game);
}
