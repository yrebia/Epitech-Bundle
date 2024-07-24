/*
** EPITECH PROJECT, 2021
** update_game
** File description:
** update_game
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

void update_text(game_t *game)
{
    sfText_setString(game->txt_bst->txt,
        cat("best score : ", to_c(game->best)));
    sfText_setFont(game->txt_bst->txt, game->txt_bst->font);
    sfText_setCharacterSize(game->txt_bst->txt, 16);
    sfText_setPosition(game->txt_bst->txt, game->txt_bst->pos);
    sfRenderWindow_drawText(game->wind, game->txt_bst->txt, NULL);
    sfText_setString(game->score->txt, cat("score : ", to_c(game->points)));
    sfText_setFont(game->score->txt, game->score->font);
    sfText_setCharacterSize(game->score->txt, 16);
    sfText_setPosition(game->score->txt, game->score->pos);
    sfRenderWindow_drawText(game->wind, game->score->txt, NULL);
    sfText_setString(game->text_level->txt,
        cat("level : ", to_c(game->level)));
    sfText_setFont(game->text_level->txt, game->text_level->font);
    sfText_setCharacterSize(game->text_level->txt, 12);
    sfText_setPosition(game->text_level->txt, game->text_level->pos);
    sfRenderWindow_drawText(game->wind, game->text_level->txt, NULL);
}

void draw_sprite(game_t *game)
{
    sfRenderWindow_drawSprite(game->wind, game->duck->sprite, NULL);
    sfRenderWindow_drawSprite(game->wind, game->duck2->sprite, NULL);
    sfRenderWindow_drawSprite(game->wind, game->duck3->sprite, NULL);
    sfRenderWindow_drawSprite(game->wind, game->goal->sprite, NULL);
    sfRenderWindow_drawSprite(game->wind, game->goal2->sprite, NULL);
    sfRenderWindow_drawSprite(game->wind, game->shot->sprite, NULL);
    sfRenderWindow_drawSprite(game->wind, game->shot2->sprite, NULL);
    sfRenderWindow_drawSprite(game->wind, game->viseur->sprite, NULL);
}

void update_game(game_t *game)
{
    sfRenderWindow_drawSprite(game->wind, game->bg->sprite, NULL);
    sfSprite_setTexture(game->duck->sprite, game->duck->texture, sfTrue);
    sfSprite_setTextureRect(game->duck->sprite, game->duck->rect);
    sfSprite_setPosition(game->duck->sprite, game->duck->pos);
    sfSprite_setTexture(game->duck2->sprite, game->duck2->texture, sfTrue);
    sfSprite_setTextureRect(game->duck2->sprite, game->duck2->rect);
    sfSprite_setPosition(game->duck2->sprite, game->duck2->pos);
    sfSprite_setTexture(game->duck3->sprite, game->duck3->texture, sfTrue);
    sfSprite_setTextureRect(game->duck3->sprite, game->duck3->rect);
    sfSprite_setPosition(game->duck3->sprite, game->duck3->pos);
    sfSprite_setPosition(game->viseur->sprite, game->viseur->pos);
    sfSprite_setPosition(game->goal->sprite, game->goal->pos);
    sfSprite_setPosition(game->goal2->sprite, game->goal->pos);
    sfSprite_setPosition(game->shot->sprite, game->shot->pos);
    sfSprite_setPosition(game->shot2->sprite, game->shot2->pos);
    sfSprite_setTextureRect(game->goal2->sprite, game->goal2->rect);
    sfSprite_setTextureRect(game->shot2->sprite, game->shot2->rect);
    draw_sprite(game);
    update_text(game);
}

void game_over(game_t *game)
{
    if (game->points > game->best)
        write_score(game);
    if (game->sound > 0)
        sfMusic_stop(game->game_over), sfMusic_play(game->game_over);
    game->points = 0, game->level = 1, game->playing = 0, game->menu = 1;
    game->goal2->rect.width = 32;
    if (game->duck->velocity.x > 0)
        game->duck->velocity.x = 2, game->duck->velocity.y = -0.5;
    else
        game->duck->velocity.x = -2, game->duck->velocity.y = -0.5;
    if (game->duck2->velocity.x > 0)
        game->duck2->velocity.x = 2, game->duck2->velocity.y = -0.5;
    else
        game->duck2->velocity.x = -2, game->duck2->velocity.y = -0.5;
    if (game->duck3->velocity.x > 0)
        game->duck3->velocity.x = 2, game->duck3->velocity.y = -0.5;
    else
        game->duck3->velocity.x = -2, game->duck3->velocity.y = -0.5;
    restart_pos(game, game->duck), restart_pos(game, game->duck2);
    restart_pos(game, game->duck3);
}
