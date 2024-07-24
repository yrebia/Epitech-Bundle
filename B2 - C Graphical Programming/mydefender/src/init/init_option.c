/*
** EPITECH PROJECT, 2022
** option
** File description:
** option
*/

#include "../../include/my.h"

void init_option_sprite(t_game *game)
{
    t_sprite **img = malloc(sizeof(t_sprite *) * 4);
    img[0] = create_sprite("resources/sound_on.png", (sfVector2f) {1290, 325},
    (sfIntRect) {0, 0, 10000, 10000}, (sfVector2f) {0.04, 0.04});
    img[1] = create_sprite("resources/sound_off.png", (sfVector2f) {1285, 330},
    (sfIntRect) {0, 0, 10000, 10000}, (sfVector2f) {0.2, 0.2});
    img[2] = create_sprite("resources/full_screen.png",
    (sfVector2f) {1300, 480}, (sfIntRect) {0, 0, 1000, 1000},
    (sfVector2f) {0.15, 0.15});
    img[3] = create_sprite("resources/screen.png", (sfVector2f) {1280, 475},
    (sfIntRect) {0, 0, 1000, 1000}, (sfVector2f) {0.5, 0.5});
    game->option->img = img;
    game->option->selection = create_sprite("resources/LevelSelect.png",
    (sfVector2f) {-100, -100}, (sfIntRect) {0, 0, 580, 100},
    (sfVector2f) {0.8, 1});
}

void init_option(t_game *game)
{
    t_option *option = malloc(sizeof(t_option)); game->option = option;
    t_text **texts = malloc(sizeof(t_text *) * 7);
    texts[0] = create_text("SOUND ON", (sfVector2f) {1400, 350}, 30,
    sfColor_fromRGB(150, 150, 150));
    texts[1] = create_text("SOUND OFF", (sfVector2f) {1400, 350}, 30,
    sfColor_fromRGB(150, 150, 150)); game->option->sound = 1;
    texts[2] = create_text("FULL SCREEN", (sfVector2f) {1400, 500}, 30,
    sfColor_fromRGB(150, 150, 150));
    texts[3] = create_text("WINDOWED", (sfVector2f) {1400, 500}, 30,
    sfColor_fromRGB(150, 150, 150)); game->option->screen = 0;
    texts[4] = create_text("FPS", (sfVector2f) {1400, 650}, 30,
    sfColor_fromRGB(150, 150, 150));
    texts[5] = create_text("30", (sfVector2f) {1300, 645}, 40,
    sfColor_fromRGB(0, 0, 0));
    texts[6] = create_text("60", (sfVector2f) {1300, 645}, 40,
    sfColor_fromRGB(0, 0, 0)); game->option->fps = 60;
    game->option->texts = texts; init_option_sprite(game);
}
