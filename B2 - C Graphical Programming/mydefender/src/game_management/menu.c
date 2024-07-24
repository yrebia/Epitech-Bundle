/*
** EPITECH PROJECT, 2022
** MENU
** File description:
** Function initializing menu
*/

#include "../../include/my.h"

void update_option3(t_game *game)
{
    if (game->option->fps == 30) {
        sfRenderWindow_drawText(game->window,
        game->option->texts[4]->text, NULL);
        sfRenderWindow_drawText(game->window,
        game->option->texts[5]->text, NULL);
    } else {
        sfRenderWindow_drawText(game->window,
        game->option->texts[4]->text, NULL);
        sfRenderWindow_drawText(game->window,
        game->option->texts[6]->text, NULL);
    }
}

void update_option2(t_game *game)
{
    if (game->option->screen == 1) {
        sfRenderWindow_drawText(game->window,
        game->option->texts[2]->text, NULL);
        sfRenderWindow_drawSprite(game->window,
        game->option->img[2]->sprite, NULL);
    } else {
        sfRenderWindow_drawText(game->window,
        game->option->texts[3]->text, NULL);
        sfRenderWindow_drawSprite(game->window,
        game->option->img[3]->sprite, NULL);
    }
    update_option3(game);
    sfRenderWindow_drawSprite(game->window,
        game->option->selection->sprite, NULL);
}

void update_option(t_game *game)
{
    if (game->menu->menustate == OPTIONS) {
        if (game->option->sound == 1) {
            sfRenderWindow_drawText(game->window,
            game->option->texts[0]->text, NULL);
            sfRenderWindow_drawSprite(game->window,
            game->option->img[0]->sprite, NULL);
        } else {
            sfRenderWindow_drawText(game->window,
            game->option->texts[1]->text, NULL);
            sfRenderWindow_drawSprite(game->window,
            game->option->img[1]->sprite, NULL);
        }
        update_option2(game);
    }
}

void main_menu1(t_game *game)
{
    if (game->menu->menustate == HTP)
        sfRenderWindow_drawText(game->window,
        game->menu->texts[6]->text, NULL);
    if (game->menu->menustate == WELCOME)
        sfRenderWindow_drawText(game->window,
        game->menu->texts[7]->text, NULL);
    if (game->menu->menustate == PLAY) {
        for (int i = 0; i < 9; i++)
            sfRenderWindow_drawText(game->window,
            game->menu->levels[i]->text, NULL);
    }
    if (game->menu->lvlhover == 1)
        sfRenderWindow_drawSprite(game->window,
        game->menu->selection[7]->sprite, NULL);
    update_option(game);
}

void main_menu(t_game *game)
{
    sfRenderWindow_drawSprite(game->window,
    game->menu->background->sprite, NULL);
    for (int i = 1; i < 6; i++)
        sfRenderWindow_drawSprite(game->window,
        game->menu->selection[i]->sprite, NULL);
    for (int i = 0; i < 4; i++)
        sfRenderWindow_drawText(game->window,
        game->menu->texts[i]->text, NULL);
    sfRenderWindow_drawSprite(game->window,
    game->menu->selection[6]->sprite, NULL);
    if (game->menu->hover == 1)
        sfRenderWindow_drawSprite(game->window,
        game->menu->selection[0]->sprite, NULL);

    main_menu1(game);
}
