/*
** EPITECH PROJECT, 2022
** INIT_PAUSE
** File description:
** Functions initializing pause
*/

#include "../../include/my.h"

void init_pause1(t_game *game)
{
    t_text **btn_text = malloc(sizeof(t_text *) * 4);
    btn_text[0] = create_text("Resume", (sfVector2f) {860, 260}, 40, sfWhite);
    btn_text[1] = create_text("Options", (sfVector2f) {860, 360}, 40, sfWhite);
    btn_text[2] = create_text("Menu", (sfVector2f) {860, 460}, 40, sfWhite);
    btn_text[3] = create_text("Exit", (sfVector2f) {860, 660}, 40, sfWhite);
    game->pause->btn_text = btn_text;
}

void init_pause(t_game *game)
{
    t_pause *pause = malloc(sizeof(t_pause)); game->pause = pause;

    game->pause->background = create_sprite("resources/Darkening.png",
    (sfVector2f) {0, 0}, (sfIntRect) {0, 0, 1920, 1080}, (sfVector2f) {1, 1});

    t_sprite **buttons = malloc(sizeof(t_sprite *) * 4);
    buttons[0] = create_button
    ("resources/Button.png", (sfVector2f) {815, 240});
    buttons[1] = create_button
    ("resources/Button.png", (sfVector2f) {815, 340});
    buttons[2] = create_button
    ("resources/Button.png", (sfVector2f) {815, 440});
    buttons[3] = create_button
    ("resources/Button.png", (sfVector2f) {815, 640});
    game->pause->buttons = buttons;

    init_pause1(game);
}
