/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** Create Parallax
*/

#include "../../include/mystruct.h"

void move_sky_parallax(rpg_t *rpg)
{
    rpg->parallax->time =
    sfClock_getElapsedTime(rpg->parallax->clock);
    rpg->parallax->seconds = rpg->parallax->time.microseconds / 1000000.0;
    if (rpg->parallax->seconds >= 0.001) {
        sfVector2f position = sfSprite_getPosition(rpg->parallax[0].sprt);
        position.x -= 3;
        sfSprite_setPosition(rpg->parallax[0].sprt, position);
        sfVector2f position_hidded = sfSprite_getPosition
        (rpg->parallax[1].sprt);
        position_hidded.x -= 3;
        sfSprite_setPosition(rpg->parallax[1].sprt, position_hidded);
        if (position.x <= -2693)
            position.x = 2687,
            sfSprite_setPosition(rpg->parallax[0].sprt, position);
        if (position_hidded.x <= -2690)
            position_hidded.x = 2680,
            sfSprite_setPosition(rpg->parallax[1].sprt, position_hidded);
        sfRenderWindow_setFramerateLimit(rpg->window, rpg->options.fps);
        sfClock_restart(rpg->parallax->clock);
    }
}

void move_moon_parallax(rpg_t *rpg)
{
    if (rpg->parallax->seconds >= 0.001) {
        sfVector2f position = sfSprite_getPosition(rpg->parallax[2].sprt);
        position.x -= 2;
        sfSprite_setPosition(rpg->parallax[2].sprt, position);

        if (position.x <= -1220) {
            position.x = 1000;
            sfSprite_setPosition(rpg->parallax[2].sprt, position);
            sfRenderWindow_setFramerateLimit(rpg->window, rpg->options.fps);
            sfClock_restart(rpg->parallax->clock);
        }
    }
}

void create_parallax(rpg_t *rpg)
{
    rpg->parallax[0].texture = sfTexture_createFromFile
    ("assets/parallax/background.png", NULL);
    rpg->parallax[0].sprt = sfSprite_create();
    sfSprite_setTexture(rpg->parallax[0].sprt,
    rpg->parallax[0].texture, sfFalse);
    sfVector2f position = {2693, 0};
    rpg->parallax[1].texture = sfTexture_createFromFile
    ("assets/parallax/background.png", NULL);
    rpg->parallax[1].sprt = sfSprite_create();
    sfSprite_setTexture(rpg->parallax[1].sprt,
    rpg->parallax[1].texture, sfFalse);
    sfSprite_setPosition(rpg->parallax[1].sprt, position);
    rpg->parallax[2].texture = sfTexture_createFromFile
    ("assets/parallax/moon.png", NULL);
    rpg->parallax[2].sprt = sfSprite_create();
    sfSprite_setTexture(rpg->parallax[2].sprt,
    rpg->parallax[2].texture, sfFalse);
    rpg->parallax[3].texture = sfTexture_createFromFile
    ("assets/parallax/foreground.png", NULL);
    rpg->parallax[3].sprt = sfSprite_create();
}

void create_clock_parallax(rpg_t *rpg)
{
    sfSprite_setTexture(rpg->parallax[3].sprt,
    rpg->parallax[3].texture, sfFalse);
    rpg->parallax->seconds = 0;
    rpg->parallax->clock = sfClock_create();
}
