/*
** EPITECH PROJECT, 2022
** init text
** File description:
** init text
*/

#include "../include/my.h"

void init_text5(game_t *game)
{
    text_t *level2 = malloc(sizeof(text_t));
    level2->font = sfFont_createFromFile("asset/menu/police.ttf");
    level2->txt = sfText_create();
    sfText_setColor(level2->txt, sfBlack);
    sfText_setFont(level2->txt, level2->font);
    sfText_setCharacterSize(level2->txt, 25);
    level2->pos.x = 1140, level2->pos.y = 265;
    sfText_setPosition(level2->txt, level2->pos);
    text_t *level3 = malloc(sizeof(text_t));
    level3->font = sfFont_createFromFile("asset/menu/police.ttf");
    level3->txt = sfText_create();
    sfText_setColor(level3->txt, sfBlack);
    sfText_setFont(level3->txt, level3->font);
    sfText_setCharacterSize(level3->txt, 25);
    level3->pos.x = 540, level3->pos.y = 565;
    sfText_setPosition(level3->txt, level3->pos);
    game->s_level->txt[2] = level3, game->s_level->txt[1] = level2;
    sfText_setString(game->s_level->txt[1]->txt, "Level 2");
    sfText_setString(game->s_level->txt[2]->txt, "Level 3");
    init_text6(game);
}

void init_text4(game_t *game)
{
    text_t *skin = malloc(sizeof(text_t));
    skin->font = sfFont_createFromFile("asset/menu/police.ttf");
    skin->txt = sfText_create();
    sfText_setColor(skin->txt, sfBlack);
    skin->pos.x = 755, skin->pos.y = 665;
    sfText_setFont(skin->txt, skin->font);
    sfText_setCharacterSize(skin->txt, 25);
    sfText_setPosition(skin->txt, skin->pos);
    text_t *level1 = malloc(sizeof(text_t));
    level1->font = sfFont_createFromFile("asset/menu/police.ttf");
    level1->txt = sfText_create();
    sfText_setColor(level1->txt, sfBlack);
    sfText_setFont(level1->txt, level1->font);
    sfText_setCharacterSize(level1->txt, 25);
    level1->pos.x = 540, level1->pos.y = 265;
    sfText_setPosition(level1->txt, level1->pos);
    game->s_level->txt[0] = level1, game->s_menu->skin_select = skin;
    sfText_setString(game->s_menu->skin_select->txt, "Chose your skin");
    sfText_setString(game->s_level->txt[0]->txt, "Level 1");
    init_text5(game);
}

void init_text3(game_t *game)
{
    text_t *level = malloc(sizeof(text_t));
    level->font = sfFont_createFromFile("asset/menu/police.ttf");
    level->txt = sfText_create();
    sfText_setColor(level->txt, sfBlack);
    level->pos.x = 750, level->pos.y = 415;
    sfText_setFont(level->txt, level->font);
    sfText_setCharacterSize(level->txt, 25);
    sfText_setPosition(level->txt, level->pos);
    text_t *resume = malloc(sizeof(text_t));
    resume->font = sfFont_createFromFile("asset/menu/police.ttf");
    resume->txt = sfText_create();
    sfText_setColor(resume->txt, sfBlack);
    resume->pos.x = 800, resume->pos.y = 415;
    sfText_setFont(resume->txt, resume->font);
    sfText_setCharacterSize(resume->txt, 25);
    sfText_setPosition(resume->txt, resume->pos);
    game->s_menu->resume = resume, game->s_menu->lvl_select = level;
    sfText_setString(game->s_menu->lvl_select->txt, "Chose your level");
    sfText_setString(game->s_menu->resume->txt, "Resume game");
    init_text4(game);
}

void init_text2(game_t *game)
{
    text_t *lose = malloc(sizeof(text_t));
    lose->font = sfFont_createFromFile("asset/menu/police.ttf");
    lose->txt = sfText_create();
    sfText_setColor(lose->txt, sfBlack);
    lose->pos.x = 725, lose->pos.y = 100;
    sfText_setFont(lose->txt, lose->font);
    sfText_setCharacterSize(lose->txt, 50);
    sfText_setPosition(lose->txt, lose->pos);
    text_t *win = malloc(sizeof(text_t));
    win->font = sfFont_createFromFile("asset/menu/police.ttf");
    win->txt = sfText_create();
    sfText_setColor(win->txt, sfBlack);
    win->pos.x = 750, win->pos.y = 100;
    sfText_setFont(win->txt, win->font);
    sfText_setCharacterSize(win->txt, 50);
    sfText_setPosition(win->txt, win->pos);
    game->s_menu->title[3] = win, game->s_menu->title[2] = lose;
    sfText_setString(game->s_menu->title[2]->txt, "YOU LOSE");
    sfText_setString(game->s_menu->title[3]->txt, "YOU WIN");
    init_text3(game);
}

void init_text(game_t *game)
{
    text_t *title = malloc(sizeof(text_t));
    title->font = sfFont_createFromFile("asset/menu/police.ttf");
    title->txt = sfText_create();
    sfText_setColor(title->txt, sfBlack);
    title->pos.x = 675, title->pos.y = 100;
    sfText_setFont(title->txt, title->font);
    sfText_setCharacterSize(title->txt, 50);
    sfText_setPosition(title->txt, title->pos);
    text_t *pause = malloc(sizeof(text_t));
    pause->font = sfFont_createFromFile("asset/menu/police.ttf");
    pause->txt = sfText_create();
    sfText_setColor(pause->txt, sfBlack);
    pause->pos.x = 780, pause->pos.y = 100;
    sfText_setFont(pause->txt, pause->font);
    sfText_setCharacterSize(pause->txt, 50);
    sfText_setPosition(pause->txt, pause->pos);
    game->s_menu->title[1] = pause, game->s_menu->title[0] = title;
    sfText_setString(game->s_menu->title[0]->txt, "RUNNER GAME");
    sfText_setString(game->s_menu->title[1]->txt, "PAUSE");
    init_text2(game);
}
