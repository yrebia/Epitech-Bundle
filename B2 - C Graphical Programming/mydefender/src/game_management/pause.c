/*
** EPITECH PROJECT, 2022
** PAUSE
** File description:
** Function managing pause in-game
*/

#include "../../include/my.h"

void game_pause(t_game *game)
{
    sfRenderWindow_drawSprite(game->window,
    game->pause->background->sprite, NULL);
    for (int i = 0; i < 4; i++) {
        if (i == 1);
        else {
            sfRenderWindow_drawSprite(game->window,
            game->pause->buttons[i]->sprite, NULL);
            sfRenderWindow_drawText(game->window,
            game->pause->btn_text[i]->text, NULL);
        }
    }
}
