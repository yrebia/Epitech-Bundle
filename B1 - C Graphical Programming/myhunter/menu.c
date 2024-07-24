/*
** EPITECH PROJECT, 2021
** menu hunter
** File description:
** menu hunter
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

void manage_mouse_menu(game_t *game)
{
    if (game->event.mouseButton.button == sfMouseLeft) {
        if (game->event.mouseButton.x <= 660 &&
            game->event.mouseButton.x >= 350 &&
            game->event.mouseButton.y <= 680 &&
            game->event.mouseButton.y >= 500)
            launch_game(game);
        if (game->event.mouseButton.x <= 1000 &&
            game->event.mouseButton.x >= 950 &&
            game->event.mouseButton.y <= 80 &&
            game->event.mouseButton.y >= 30)
            game->sound *= -1;
        if (game->event.mouseButton.x <= 90 &&
            game->event.mouseButton.x >= 30 &&
            game->event.mouseButton.y <= 90 &&
            game->event.mouseButton.y >= 25)
            sfRenderWindow_close(game->wind);
    }
}

void menuing_draw_sprite(game_t *game, menu_t *menu)
{
    sfRenderWindow_drawSprite(game->wind, menu->bg->sprite, NULL);
    sfRenderWindow_drawSprite(game->wind, menu->exit->sprite, NULL);
    sfRenderWindow_drawSprite(game->wind, menu->play->sprite, NULL);
    if (game->sound == 1)
        sfRenderWindow_drawSprite(game->wind, menu->sound_on->sprite, NULL);
    else
        sfRenderWindow_drawSprite(game->wind, menu->sound_off->sprite, NULL);
}

void menuing(game_t *game, menu_t *menu)
{
    sfRenderWindow_setMouseCursorVisible(game->wind, sfTrue);
    game->best = my_getnbr(read_file("txt/score.txt"));
    menuing_draw_sprite(game, menu);
    sfText_setString(game->txt_bst->txt,
        cat("best score : ", to_c(game->best))), game->score->pos.x = 440;
    sfText_setFont(game->txt_bst->txt, game->txt_bst->font);
    sfText_setCharacterSize(game->txt_bst->txt, 30), game->score->pos.y = 400;
    game->txt_bst->pos.x = 380, game->txt_bst->pos.y = 300;
    sfText_setPosition(game->txt_bst->txt, game->txt_bst->pos);
    sfRenderWindow_drawText(game->wind, game->txt_bst->txt, NULL);
    sfText_setString(game->score->txt, cat("score : ", to_c(game->points)));
    sfText_setFont(game->score->txt, game->score->font);
    sfText_setCharacterSize(game->score->txt, 30);
    sfText_setPosition(game->score->txt, game->score->pos);
    sfRenderWindow_drawText(game->wind, game->score->txt, NULL);
}
