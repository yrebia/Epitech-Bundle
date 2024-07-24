/*
** EPITECH PROJECT, 2021
** init hunter
** File description:
** init hunter
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

void set_images(game_t *game)
{
    sfSprite_setTexture(game->bg->sprite, game->bg->texture, sfTrue);
    sfSprite_setTexture(game->duck->sprite, game->duck->texture, sfTrue);
    sfSprite_setTexture(game->viseur->sprite, game->viseur->texture, sfTrue);
    sfSprite_setTexture(game->goal->sprite, game->goal->texture, sfTrue);
    sfSprite_setTexture(game->goal2->sprite, game->goal2->texture, sfTrue);
    sfSprite_setTexture(game->shot->sprite, game->shot->texture, sfTrue);
    sfSprite_setTexture(game->shot2->sprite, game->shot2->texture, sfTrue);
    sfSprite_setTextureRect(game->bg->sprite, game->bg->rect);
    sfSprite_setTextureRect(game->goal->sprite, game->goal->rect);
    sfSprite_setTextureRect(game->shot->sprite, game->shot->rect);
    sfSprite_setTextureRect(game->shot2->sprite, game->shot2->rect);
    sfSprite_setScale(game->bg->sprite, game->duck->scale);
    sfSprite_setScale(game->viseur->sprite, game->viseur->scale);
    sfSprite_setScale(game->goal->sprite, game->duck->scale);
    sfSprite_setScale(game->goal2->sprite, game->duck->scale);
    sfSprite_setScale(game->shot->sprite, game->duck->scale);
    sfSprite_setScale(game->shot2->sprite, game->duck->scale);
    sfSprite_setScale(game->duck->sprite, game->duck2->scale);
    sfSprite_setScale(game->duck2->sprite, game->duck2->scale);
    sfSprite_setScale(game->duck3->sprite, game->duck2->scale);
}

void set_text(game_t *game)
{
    text_t *best = malloc(sizeof(text_t));
    best->font = sfFont_createFromFile("txt/police.ttf");
    best->txt = sfText_create();
    sfText_setColor(best->txt, sfGreen);
    game->txt_bst = best;
    text_t *score = malloc(sizeof(text_t));
    score->font = sfFont_createFromFile("txt/police.ttf");
    score->txt = sfText_create();
    sfText_setColor(score->txt, sfGreen);
    game->score = score;
    text_t *level = malloc(sizeof(text_t));
    level->font = sfFont_createFromFile("txt/police.ttf");
    level->txt = sfText_create(), level->pos.x = 101, level->pos.y = 772;
    sfText_setColor(level->txt, sfGreen);
    game->text_level = level;
    set_images(game);
}

void set_duck2(game_t *game)
{
    image_t *duck3 = malloc(sizeof(image_t));
    duck3->texture = sfTexture_createFromFile("img/hunter.png", NULL);
    duck3->sprite = sfSprite_create(), duck3->pos.x = 200;
    duck3->pos.y = 200 + (rand() % 401);
    duck3->velocity.x = 2, duck3->velocity.y = -0.5, duck3->rect.top = 212;
    duck3->rect.left = 0, duck3->rect.width = 44, duck3->rect.height = 37;
    duck3->offset = 1, duck3->sens = 1;
    duck3->clock = sfClock_create();
    duck3->scale.x = 2, duck3->scale.y = 2, game->duck3 = duck3;
}

void set_duck(game_t *game)
{
    image_t *duck = malloc(sizeof(image_t));
    duck->texture = sfTexture_createFromFile("img/hunter.png", NULL);
    duck->sprite = sfSprite_create(), duck->pos.x = 100;
    duck->pos.y = 200 + (rand() % 401);
    duck->velocity.x = 2, duck->velocity.y = -0.5, duck->rect.top = 128;
    duck->rect.left = 2, duck->rect.width = 44, duck->rect.height = 37;
    duck->offset = 1, duck->sens = 1;
    duck->clock = sfClock_create();
    duck->scale.x = 4, duck->scale.y = 4, game->duck = duck;
    image_t *duck2 = malloc(sizeof(image_t));
    duck2->texture = sfTexture_createFromFile("img/hunter.png", NULL);
    duck2->sprite = sfSprite_create(), duck2->pos.x = 0;
    duck2->pos.y = 200 + (rand() % 401);
    duck2->velocity.x = 2, duck2->velocity.y = -0.5, duck2->rect.top = 170;
    duck2->rect.left = 0, duck2->rect.width = 44, duck2->rect.height = 37;
    duck2->offset = 2, duck2->sens = 1;
    duck2->clock = sfClock_create();
    duck2->scale.x = 2, duck2->scale.y = 2, game->duck2 = duck2;
}

void destroy(game_t *game)
{
    free(game->bg);
    free(game->duck);
    free(game->viseur);
    free(game->goal);
    free(game->goal2);
    free(game->shot);
    free(game->shot2);
    free(game->txt_bst);
    free(game->score);
    sfMusic_destroy(game->gunshot);
    sfMusic_destroy(game->game_over);
    sfRenderWindow_destroy(game->wind);
}
