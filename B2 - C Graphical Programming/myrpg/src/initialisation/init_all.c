/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** Initialisation
*/

#include "../../include/mystruct.h"

void init_event(rpg_t *rpg)
{
    sfImage *image = sfImage_createFromFile("assets/map/map_spawn.png");
    const sfUint8 *pixel = sfImage_getPixelsPtr(image);
    sfRenderWindow_setIcon(rpg->window, 100, 100, pixel);
    rpg->bg = malloc(sizeof(sprite_t));
    rpg->bg->texture =
    sfTexture_createFromFile("assets/map/map_spawn.png", NULL);
    rpg->bg->sprite = sfSprite_create();
    sfSprite_setTexture(rpg->bg->sprite, rpg->bg->texture, sfTrue);
    rpg->bg->pos.x = 0, rpg->bg->pos.y = 0;
    sfSprite_setPosition(rpg->bg->sprite, rpg->bg->pos);
    rpg->bg->scale.x = 3, rpg->bg->scale.y = 3;
    sfSprite_setScale(rpg->bg->sprite, rpg->bg->scale);
    rpg->bg2 = malloc(sizeof(sprite_t));
    rpg->bg2->texture = sfTexture_createFromFile
    ("assets/map/map_spawn2.png", NULL);
    rpg->bg2->sprite = sfSprite_create();
    sfSprite_setTexture(rpg->bg2->sprite, rpg->bg2->texture, sfTrue);
    rpg->bg2->pos.x = 0, rpg->bg2->pos.y = 0;
    sfSprite_setPosition(rpg->bg2->sprite, rpg->bg2->pos);
}

void init_options(rpg_t *rpg)
{
    rpg->event.mouseButton.x = 0, rpg->event.mouseButton.y = 0;
    rpg->options.fullscreen = true, rpg->options.fps = 60;
    rpg->options.volume = 50, rpg->options.music = true;
    rpg->options.language = 0, rpg->skin = 0;
    rpg->state = 4, rpg->menu_id = 0, rpg->pause_id = 0;
    rpg->inventory_id = 0, rpg->loading = 0, init_event(rpg);
    inside_map(rpg), rect_and_scale_player(rpg);
    rpg->player->is_attacking = 0, rpg->player->animation = sfClock_create();
    rpg->bg->animation = sfClock_create();
    rpg->player->attack = sfClock_create(), rpg->bg->map = 0;
    rpg->life_bar = malloc(sizeof(sprite_t));
    rpg->life_bar->texture = sfTexture_createFromFile
    ("assets/life_bar.png", NULL);
    rpg->life_bar->sprite = sfSprite_create();
    sfSprite_setTexture(rpg->life_bar->sprite, rpg->life_bar->texture, sfTrue);
    rpg->life_bar->rect.left = 30, rpg->life_bar->rect.top = 250;
}

void init_all(rpg_t *rpg)
{
    init_options(rpg);
    rpg->life_bar->rect.height = 1000, rpg->life_bar->rect.width = 1000;
    sfSprite_setTextureRect(rpg->life_bar->sprite, rpg->life_bar->rect);
    rpg->life_bar->scale.x = 1.015, rpg->life_bar->scale.y = 0.5;
    sfSprite_setScale(rpg->life_bar->sprite, rpg->life_bar->scale);
    sfSprite_setColor(rpg->life_bar->sprite, sfColor_fromRGB(124, 252, 0));
    rpg->life_bar_back = malloc(sizeof(sprite_t));
    rpg->life_bar_back->texture = sfTexture_createFromFile
    ("assets/life_bar.png", NULL);
    rpg->life_bar_back->sprite = sfSprite_create();
    sfSprite_setTexture(rpg->life_bar_back->sprite,
    rpg->life_bar_back->texture, sfTrue);
    rpg->life_bar_back->rect.left = 20, rpg->life_bar_back->rect.top = 250;
    rpg->life_bar_back->rect.height = 1000;
    rpg->life_bar_back->rect.width = 1000;
    sfSprite_setTextureRect
    (rpg->life_bar_back->sprite, rpg->life_bar_back->rect);
    rpg->life_bar_back->scale.x = 1.025, rpg->life_bar_back->scale.y = 0.66;
    sfSprite_setScale(rpg->life_bar_back->sprite, rpg->life_bar_back->scale);
    sfSprite_setColor(rpg->life_bar_back->sprite, sfBlack);
}

void inside_map(rpg_t *rpg)
{
    rpg->bg2->scale.x = 3;
    rpg->bg2->scale.y = 3;
    sfSprite_setScale(rpg->bg2->sprite, rpg->bg2->scale);
    rpg->bg3 = malloc(sizeof(sprite_t));
    rpg->bg3->texture = sfTexture_createFromFile
    ("assets/map/map_spawn3.png", NULL);
    rpg->bg3->sprite = sfSprite_create();
    sfSprite_setTexture(rpg->bg3->sprite, rpg->bg3->texture, sfTrue);
    rpg->bg3->pos.x = 0, rpg->bg3->pos.y = 0;
    sfSprite_setPosition(rpg->bg3->sprite, rpg->bg3->pos);
    rpg->bg3->scale.x = 3;
    rpg->bg3->scale.y = 3;
    sfSprite_setScale(rpg->bg3->sprite, rpg->bg3->scale);
    rpg->player = malloc(sizeof(sprite_t));
    rpg->player->hp = 100, rpg->player->touched = 0;
    rpg->player->texture = sfTexture_createFromFile("assets/player.png", NULL);
    rpg->player->sprite = sfSprite_create();
    sfSprite_setTexture(rpg->player->sprite, rpg->player->texture, sfTrue);
    rpg->player->pos.x = 0, rpg->player->pos.y = 0;
    sfSprite_setPosition(rpg->player->sprite, rpg->player->pos);
}

void rect_and_scale_player(rpg_t *rpg)
{
    rpg->player->scale.x = 2;
    rpg->player->scale.y = 2;
    sfSprite_setScale(rpg->player->sprite, rpg->player->scale);
    rpg->player->rect.top = 16;
    rpg->player->rect.left = 15;
    rpg->player->rect.width = 40;
    rpg->player->rect.height = 37;
    sfSprite_setTextureRect(rpg->player->sprite, rpg->player->rect);
    sfFloatRect tmp = {0, 0, 1920, 1080};
    rpg->view = sfView_createFromRect(tmp);
}
