/*
** EPITECH PROJECT, 2021
** init destroy
** File description:
** init destroy
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
#include "../include/my.h"

void set_string_text(game_t *game)
{
    sfText_setString(game->s_level->txt[5]->txt, "Your level");
    sfText_setString(game->s_level->score[0]->txt,
        my_strcat(my_strcat("Best score : ", read_file(game,
        "asset/level1/best.txt")), "%"));
    sfText_setString(game->s_level->score[1]->txt,
        my_strcat(my_strcat("Best score : ", read_file(game,
        "asset/level2/best.txt")), "%"));
    sfText_setString(game->s_level->score[2]->txt,
        my_strcat(my_strcat("Best score : ", read_file(game,
        "asset/level3/best.txt")), "%"));
    sfText_setString(game->s_level->score[3]->txt,
        my_strcat(my_strcat("Best score : ", read_file(game,
        "asset/level4/best.txt")), "%"));
}

void final_init_text(game_t *game)
{
    text_t *score4 = malloc(sizeof(text_t));
    score4->font = sfFont_createFromFile("asset/menu/police.ttf");
    score4->txt = sfText_create();
    sfText_setColor(score4->txt, sfBlack);
    sfText_setFont(score4->txt, score4->font);
    sfText_setCharacterSize(score4->txt, 20);
    score4->pos.x = 1080, score4->pos.y = 665;
    sfText_setPosition(score4->txt, score4->pos);
    game->s_level->score[3] = score4;
    set_string_text(game);
}

void init_text8(game_t *game)
{
    text_t *score2 = malloc(sizeof(text_t));
    score2->font = sfFont_createFromFile("asset/menu/police.ttf");
    score2->txt = sfText_create();
    sfText_setColor(score2->txt, sfBlack);
    sfText_setFont(score2->txt, score2->font);
    sfText_setCharacterSize(score2->txt, 20);
    score2->pos.x = 1080, score2->pos.y = 365;
    sfText_setPosition(score2->txt, score2->pos);
    game->s_level->score[1] = score2;
    text_t *score3 = malloc(sizeof(text_t));
    score3->font = sfFont_createFromFile("asset/menu/police.ttf");
    score3->txt = sfText_create();
    sfText_setColor(score3->txt, sfBlack);
    sfText_setFont(score3->txt, score3->font);
    sfText_setCharacterSize(score3->txt, 20);
    score3->pos.x = 480, score3->pos.y = 665;
    sfText_setPosition(score3->txt, score3->pos);
    game->s_level->score[2] = score3;
    final_init_text(game);
}

void init_text7(game_t *game)
{
    text_t *level6 = malloc(sizeof(text_t));
    level6->font = sfFont_createFromFile("asset/menu/police.ttf");
    level6->txt = sfText_create();
    sfText_setColor(level6->txt, sfBlack);
    sfText_setFont(level6->txt, level6->font);
    sfText_setCharacterSize(level6->txt, 25);
    level6->pos.x = 810, level6->pos.y = 865;
    sfText_setPosition(level6->txt, level6->pos);
    game->s_level->txt[5] = level6;
    text_t *score1 = malloc(sizeof(text_t));
    score1->font = sfFont_createFromFile("asset/menu/police.ttf");
    score1->txt = sfText_create();
    sfText_setColor(score1->txt, sfBlack);
    sfText_setFont(score1->txt, score1->font);
    sfText_setCharacterSize(score1->txt, 20);
    score1->pos.x = 480, score1->pos.y = 365;
    sfText_setPosition(score1->txt, score1->pos);
    game->s_level->score[0] = score1;
    init_text8(game);
}

void init_text6(game_t *game)
{
    text_t *level4 = malloc(sizeof(text_t));
    level4->font = sfFont_createFromFile("asset/menu/police.ttf");
    level4->txt = sfText_create();
    sfText_setColor(level4->txt, sfBlack);
    sfText_setFont(level4->txt, level4->font);
    sfText_setCharacterSize(level4->txt, 25);
    level4->pos.x = 1140, level4->pos.y = 565;
    sfText_setPosition(level4->txt, level4->pos);
    text_t *level5 = malloc(sizeof(text_t));
    level5->font = sfFont_createFromFile("asset/menu/police.ttf");
    level5->txt = sfText_create();
    sfText_setColor(level5->txt, sfBlack);
    sfText_setFont(level5->txt, level5->font);
    sfText_setCharacterSize(level5->txt, 25);
    level5->pos.x = 810, level5->pos.y = 865;
    sfText_setPosition(level5->txt, level5->pos);
    game->s_level->txt[4] = level5, game->s_level->txt[3] = level4;
    sfText_setString(game->s_level->txt[3]->txt, "Level 4");
    sfText_setString(game->s_level->txt[4]->txt, "Infini mode");
    init_text7(game);
}
