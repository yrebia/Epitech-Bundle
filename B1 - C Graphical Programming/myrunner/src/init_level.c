/*
** EPITECH PROJECT, 2022
** init level
** File description:
** init level
*/

#include "../include/my.h"

void init_level(game_t *game)
{
    game->sky = create_img("asset/level1/sky.png", 0, 0, 0);
    game->rock[0] = create_img("asset/level1/rock.png", -0.5, 0, 25);
    game->rock[1] = create_img("asset/level1/rock.png", -0.5, 1920, 25);
    game->cloud[0] = create_img("asset/level1/cloud.png", -0.8, 0, 0);
    game->cloud[1] = create_img("asset/level1/cloud.png", -0.8, 1920, 0);
    game->back[0] = create_img("asset/level1/back.png", -1, 0, 0);
    game->back[1] = create_img("asset/level1/back.png", -1, 1920, 0);
    game->front[0] = create_img("asset/level1/front.png", -2, 0, 0);
    game->front[1] = create_img("asset/level1/front.png", -2, 1920, 0);
    game->ground[0] = create_img("asset/level1/ground.png", -12, 0, 0);
    game->ground[1] = create_img("asset/level1/ground.png", -12, 1920, 0);
    game->tree[0] = create_img("asset/level1/tree.png", -4, 0, 0);
    game->tree[1] = create_img("asset/level1/tree.png", -4, 1920, 0);
    game->player = create_img("asset/player1/run.png", 0, 100, 715);
    game->skin[0] = create_img("asset/player1/idle.png", 0, 850, 300);
    game->skin[1] = create_img("asset/player2/idle.png", 0, 700, 600);
    game->skin[2] = create_img("asset/player3/idle.png", 0, 1000, 600);
    game->finish = create_img("asset/level1/end.png", 0, -500, 400);
    init_music(game);
}

void init(game_t *game)
{
    sfVideoMode v_mode = {1920, 1080, 32};
    game->wind = sfRenderWindow_create(v_mode, "MyRunner", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(game->wind, 30);
    init_level(game), init_menu(game), game->activ_skin = 0;
    init_skin(game->player), init_skin(game->skin[0]);
    init_skin(game->skin[1]), init_skin(game->skin[2]);
    game->play = 0, game->shop = 0, game->menu = 1, game->sound = 1;
    game->screen = 0, game->error = 0;
    game->level_menu = 0, game->enemys = 0, game->clock = sfClock_create();
    game->level = 0, game->win = 5, game->time = 0;
    text_t *score = malloc(sizeof(text_t));
    score->font = sfFont_createFromFile("asset/menu/police.ttf");
    score->txt = sfText_create();
    sfText_setColor(score->txt, sfBlack);
    score->pos.x = 850, score->pos.y = 25;
    sfText_setFont(score->txt, score->font);
    sfText_setCharacterSize(score->txt, 25);
    sfText_setPosition(score->txt, score->pos);
    game->score = score, init_text(game);
}
