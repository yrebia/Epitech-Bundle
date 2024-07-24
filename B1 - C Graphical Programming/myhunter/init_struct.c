/*
** EPITECH PROJECT, 2021
** init_struct
** File description:
** init_struct
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

void set_struct3(game_t *game)
{
    image_t *shot = malloc(sizeof(image_t));
    shot->texture = sfTexture_createFromFile("img/hunter.png", NULL);
    shot->sprite = sfSprite_create(), shot->pos.x = 92, shot->pos.y = 860;
    shot->rect.top = 270, shot->rect.left = 498, shot->rect.width = 24;
    shot->rect.height = 8, game->shot = shot;
    image_t *shot2 = malloc(sizeof(image_t));
    shot2->texture = sfTexture_createFromFile("img/hunter.png", NULL);
    shot2->sprite = sfSprite_create(), shot2->pos.x = 92, shot2->pos.y = 824;
    shot2->rect.top = 261, shot2->rect.left = 498;
    shot2->rect.width = 8 * game->bullet;
    shot2->rect.height = 17, game->shot2 = shot2;
    set_text(game);
}

void set_struct2(game_t *game)
{
    image_t *viseur = malloc(sizeof(image_t));
    viseur->texture = sfTexture_createFromFile("img/viseur.png", NULL);
    viseur->sprite = sfSprite_create();
    viseur->pos.x = game->event.mouseMove.x - 30;
    viseur->pos.y = game->event.mouseMove.y - 30;
    viseur->scale.x = 0.05, viseur->scale.y = 0.05, game->viseur = viseur;
    image_t *goal = malloc(sizeof(image_t));
    goal->texture = sfTexture_createFromFile("img/hunter.png", NULL);
    goal->sprite = sfSprite_create(), goal->pos.x = 252, goal->pos.y = 821;
    goal->rect.top = 250, goal->rect.left = 526, goal->rect.width = 113;
    goal->rect.height = 18, game->goal = goal;
    image_t *goal2 = malloc(sizeof(image_t));
    goal2->texture = sfTexture_createFromFile("img/hunter.png", NULL);
    goal2->sprite = sfSprite_create(), goal2->rect.top = 270;
    goal2->rect.left = 526, goal2->rect.width = 32, goal2->rect.height = 18;
    game->goal2 = goal2;
    set_struct3(game);
}

void set_struct(game_t *game)
{
    sfVideoMode video_mode = {1024, 956, 32};
    game->wind = sfRenderWindow_create(video_mode, "DuckHunt", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(game->wind, 30);
    game->bullet = 3, game->sound = 1;
    game->points = 0, game->playing = 0, game->menu = 1, game->level = 1;
    game->gunshot = sfMusic_createFromFile("sound/gunshot.wav");
    game->best = my_getnbr(read_file("txt/score.txt"));
    game->game_over = sfMusic_createFromFile("sound/game_over.wav");
    image_t *bg = malloc(sizeof(image_t));
    bg->texture = sfTexture_createFromFile("img/hunter.png", NULL);
    bg->sprite = sfSprite_create();
    bg->rect.top = 6, bg->rect.left = 383, bg->rect.width = 256;
    bg->rect.height = 239, game->bg = bg;
    set_duck(game);
    set_duck2(game);
    set_struct2(game);
}
