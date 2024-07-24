/*
** EPITECH PROJECT, 2022
** analyse option
** File description:
** analyse option
*/

#include "../../include/my.h"

void analyse_option5(t_game *game, int *hover)
{
    if (*hover == 0)
        game->option->selection->pos = (sfVector2f) {-100, -100};
    sfSprite_setPosition(game->option->selection->sprite,
        game->option->selection->pos);
}

void analyse_option4(t_game *game)
{
    if (game->event.type == sfEvtMouseButtonReleased &&
        game->option->screen == 1) {
        game->option->screen = 0, sfRenderWindow_destroy(game->window);
        sfVideoMode v_mode = {1920, 1080, 32};
        game->window = sfRenderWindow_create
        (v_mode, "MyDefender", sfClose | sfResize, NULL);
        sfRenderWindow_setFramerateLimit(game->window, game->option->fps);
    } else if (game->event.type == sfEvtMouseButtonReleased &&
        game->option->screen == 0) {
        game->option->screen = 1, sfRenderWindow_destroy(game->window);
        sfVideoMode v_mode = {1920, 1080, 32};
        game->window = sfRenderWindow_create
        (v_mode, "MyDefender", sfClose | sfFullscreen, NULL);
        sfRenderWindow_setFramerateLimit(game->window, game->option->fps);
    }
}

void analyse_option3(t_game *game, int *hover, sfVector2i mp)
{
    if (mp.x >= (game->option->texts[2]->pos.x - 125)
    && mp.x <= (game->option->texts[2]->pos.x + 325)
    && mp.y >= (game->option->texts[2]->pos.y - 25)
    && mp.y <= (game->option->texts[2]->pos.y + 75)) {
        game->option->selection->pos.x = game->option->texts[2]->pos.x - 145;
        game->option->selection->pos.y = game->option->texts[2]->pos.y - 30;
        *hover = 1;
        if (game->event.type == sfEvtMouseButtonPressed)
            sfText_setColor(game->option->texts[2]->text, sfWhite),
            sfText_setColor(game->option->texts[3]->text, sfWhite);
        analyse_option4(game);
    }
    if (game->event.type == sfEvtMouseButtonReleased)
        for (int i = 0; i < 5; i++)
            sfText_setColor(game->option->texts[i]->text,
            sfColor_fromRGB(150, 150, 150));
}

void analyse_option2(t_game *game, int *hover, sfVector2i mp)
{
    analyse_option3(game, hover, mp);
    sfVector2f pos = game->option->texts[4]->pos;
    if (mp.x >= (pos.x - 125) && mp.x <= (pos.x + 325) && mp.y >= (pos.y - 25)
        && mp.y <= (pos.y + 75)) {
        game->option->selection->pos.x = pos.x - 145;
        game->option->selection->pos.y = pos.y - 30; *hover = 1;
        if (game->event.type == sfEvtMouseButtonPressed)
            sfText_setColor(game->option->texts[4]->text, sfWhite);
        if (game->event.type == sfEvtMouseButtonReleased &&
            game->option->fps == 60) game->option->fps = 30,
            sfRenderWindow_setFramerateLimit(game->window, game->option->fps);
        else if (game->event.type == sfEvtMouseButtonReleased &&
            game->option->fps == 30) game->option->fps = 60,
            sfRenderWindow_setFramerateLimit(game->window, game->option->fps);
    } analyse_option5(game, hover);
}

void analyse_option(t_game *game)
{
    sfVector2i mp = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f pos = game->option->texts[0]->pos; int hover = 0;
    if (mp.x >= (pos.x - 125) && mp.x <= (pos.x + 325) && mp.y >= (pos.y - 25)
        && mp.y <= (pos.y + 75)) {
        game->option->selection->pos.x = pos.x - 145;
        game->option->selection->pos.y = pos.y - 30; hover = 1;
        if (game->event.type == sfEvtMouseButtonPressed)
            sfText_setColor(game->option->texts[0]->text, sfWhite),
            sfText_setColor(game->option->texts[1]->text, sfWhite);
        if (game->event.type == sfEvtMouseButtonReleased &&
            game->option->sound == 1) game->option->sound = 0,
            sfMusic_setVolume(game->music->shot, 0),
            sfMusic_setVolume(game->music->game, 0),
            sfMusic_setVolume(game->music->menu, 0);
        else if (game->event.type == sfEvtMouseButtonReleased &&
            game->option->sound == 0) game->option->sound = 1,
            sfMusic_setVolume(game->music->shot, 50),
            sfMusic_setVolume(game->music->game, 50),
            sfMusic_setVolume(game->music->menu, 50);
    } analyse_option2(game, &hover, mp);
}
