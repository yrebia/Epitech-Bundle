/*
** EPITECH PROJECT, 2021
** init menu
** File description:
** init menu
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Export.h>
#include <SFML/System/Time.h>
#include <SFML/Window/Event.h>
#include <SFML/Audio.h>
#include <stddef.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

void set_menu4(menu_t *menu)
{
    image_t *exit = malloc(sizeof(image_t));
    exit->texture = sfTexture_createFromFile("img/exit.png", NULL);
    exit->sprite = sfSprite_create();
    exit->pos.x = 30, exit->pos.y = 30;
    exit->scale.x = 0.1, exit->scale.y = 0.1;
    menu->exit = exit;
    sfSprite_setTexture(menu->exit->sprite, menu->exit->texture, sfTrue);
    sfSprite_setScale(menu->exit->sprite, menu->exit->scale);
    sfSprite_setPosition(menu->exit->sprite, menu->exit->pos);
}

void set_menu3(menu_t *menu)
{
    image_t *sound_off = malloc(sizeof(image_t));
    sound_off->texture = sfTexture_createFromFile("img/sound_off.png", NULL);
    sound_off->sprite = sfSprite_create(), sound_off->pos.x = 950;
    sound_off->pos.y = 30;
    sound_off->rect.top = 0, sound_off->rect.left = 100;
    sound_off->rect.width = 500;
    sound_off->rect.height = 500, sound_off->scale.x = 0.1;
    sound_off->scale.y = 0.1;
    menu->sound_off = sound_off;
    sfSprite_setTexture(menu->sound_off->sprite, menu->sound_off->texture,
        sfTrue);
    sfSprite_setTextureRect(menu->sound_off->sprite, menu->sound_off->rect);
    sfSprite_setScale(menu->sound_off->sprite, menu->sound_off->scale);
    sfSprite_setPosition(menu->sound_off->sprite, menu->sound_off->pos);
    set_menu4(menu);
}

void set_menu2(menu_t *menu)
{
    image_t *sound_on = malloc(sizeof(image_t));
    sound_on->texture = sfTexture_createFromFile("img/sound_on.png", NULL);
    sound_on->sprite = sfSprite_create(), sound_on->pos.x = 950;
    sound_on->pos.y = 30;
    sound_on->rect.top = 0, sound_on->rect.left = 0;
    sound_on->rect.width = 2000;
    sound_on->rect.height = 2000, sound_on->scale.x = 0.02;
    sound_on->scale.y = 0.02;
    menu->sound_on = sound_on;
    sfSprite_setTexture(menu->sound_on->sprite, menu->sound_on->texture,
        sfTrue);
    sfSprite_setTextureRect(menu->sound_on->sprite, menu->sound_on->rect);
    sfSprite_setScale(menu->sound_on->sprite, menu->sound_on->scale);
    sfSprite_setPosition(menu->sound_on->sprite, menu->sound_on->pos);
    set_menu3(menu);
}

void set_menu(menu_t *menu)
{
    image_t *bg = malloc(sizeof(image_t));
    bg->texture = sfTexture_createFromFile("img/bg.png", NULL);
    bg->sprite = sfSprite_create();
    bg->rect.top = 0, bg->rect.left = 250, bg->rect.width = 1024;
    bg->rect.height = 956, bg->scale.x = 1, bg->scale.y = 1, menu->bg = bg;
    sfSprite_setTexture(menu->bg->sprite, menu->bg->texture, sfTrue);
    sfSprite_setTextureRect(menu->bg->sprite, menu->bg->rect);
    sfSprite_setScale(menu->bg->sprite, menu->bg->scale);
    image_t *play = malloc(sizeof(image_t));
    play->texture = sfTexture_createFromFile("img/play.png", NULL);
    play->sprite = sfSprite_create(), play->pos.x = 370, play->pos.y = 500;
    play->rect.top = 30, play->rect.left = 50, play->rect.width = 310;
    play->rect.height = 180, play->scale.x = 1, play->scale.y = 1;
    menu->play = play;
    sfSprite_setTexture(menu->play->sprite, menu->play->texture, sfTrue);
    sfSprite_setTextureRect(menu->play->sprite, menu->play->rect);
    sfSprite_setScale(menu->play->sprite, menu->play->scale);
    sfSprite_setPosition(menu->play->sprite, menu->play->pos);
    set_menu2(menu);
}
