/*
** EPITECH PROJECT, 2021
** game hunter
** File description:
** game hunter
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

void manage_mouse_click2(game_t *game)
{
    if (game->event.mouseButton.x <= game->duck3->pos.x + 88 &&
        game->event.mouseButton.x >= game->duck3->pos.x &&
        game->event.mouseButton.y <= game->duck3->pos.y + 88 &&
        game->event.mouseButton.y >= game->duck3->pos.y)
        restart_pos(game, game->duck3), game->points++,
            game->goal2->rect.width += 8;
    else
        game->bullet--;
}

void manage_mouse_click(game_t *game)
{
    if (game->event.mouseButton.button == sfMouseLeft) {
        if (game->event.mouseButton.x <= game->duck->pos.x + 88 &&
            game->event.mouseButton.x >= game->duck->pos.x &&
            game->event.mouseButton.y <= game->duck->pos.y + 88 &&
            game->event.mouseButton.y >= game->duck->pos.y)
            restart_pos(game, game->duck), game->points++,
                game->goal2->rect.width += 8;
        else if (game->event.mouseButton.x <= game->duck2->pos.x + 88 &&
            game->event.mouseButton.x >= game->duck2->pos.x &&
            game->event.mouseButton.y <= game->duck2->pos.y + 88 &&
            game->event.mouseButton.y >= game->duck2->pos.y)
            restart_pos(game, game->duck2), game->points++,
                game->goal2->rect.width += 8;
        else
            manage_mouse_click2(game);
        if (game->sound > 0)
            sfMusic_stop(game->gunshot), sfMusic_play(game->gunshot);
        game->viseur->pos.x = game->event.mouseButton.x - 30;
        game->viseur->pos.y = game->event.mouseButton.y - 30;
    }
}

void restart_pos(game_t *game, image_t *duck)
{
    sfVector2f reverse;
    sfVector2f origin;
    reverse.x = -1, reverse.y = 1, origin.x = 0, origin.y = 1;
    srand(time(NULL));
    if (rand() % 2 == 0) {
        duck->pos.x = 1050;
        origin.x = 55, sfSprite_setOrigin(duck->sprite, origin);
        if (duck->velocity.x > 0)
            sfSprite_scale(duck->sprite, reverse), duck->velocity.x *= -1;
    } else {
        duck->pos.x = -150, sfSprite_setOrigin(duck->sprite, origin);
        if (duck->velocity.x < 0)
            sfSprite_scale(duck->sprite, reverse), duck->velocity.x *= -1;
    }
    duck->pos.y = 200 + (rand() % 401);
    duck->velocity.y = -(rand() % (game->level + 1));
}

void level_up(game_t *game)
{
    restart_pos(game, game->duck);
    game->goal2->rect.width = 32;
    game->level++;
    game->duck->velocity.x *= 1.5;
    game->duck2->velocity.x *= 1.5;
    game->duck3->velocity.x *= 1.5;
}

void time_gestion(game_t *game, image_t *duck)
{
    duck->time = sfClock_getElapsedTime(duck->clock);
    duck->seconds = duck->time.microseconds / 1000000.0;
    if (duck->seconds > 0.2) {
        duck->rect.left = duck->offset * 45 - 2;
        sfClock_restart(duck->clock);
        if (duck->offset == 2 || duck->offset == 0)
            duck->sens *= -1;
        duck->offset += duck->sens;
    }
    if (duck->pos.y < -75 || (duck->pos.x < -75 && duck->velocity.x < 0) ||
        (duck->pos.x > 1100 && duck->velocity.x > 0))
        restart_pos(game, duck);
    duck->pos.x += duck->velocity.x;
    duck->pos.y += duck->velocity.y;
}
