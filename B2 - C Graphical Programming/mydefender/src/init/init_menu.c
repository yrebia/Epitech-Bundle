/*
** EPITECH PROJECT, 2022
** INIT_MENU
** File description:
** Functions initializing menu
*/

#include "../../include/my.h"

void init_menu3(t_game *game)
{
    game->menu->levels[3] = create_text("MAP 4", (sfVector2f) {1600, 425}, 25,
    sfWhite);
    game->menu->levels[4] = create_text("MAP 5", (sfVector2f) {1350, 500}, 25,
    sfWhite);
    game->menu->levels[5] = create_text("MAP 6", (sfVector2f) {1600, 500}, 25,
    sfWhite);
    game->menu->levels[6] = create_text("MAP 7", (sfVector2f) {1350, 575}, 25,
    sfWhite);
    game->menu->levels[7] = create_text("MAP 8", (sfVector2f) {1600, 575}, 25,
    sfWhite);
    game->menu->levels[8] = create_text("SELECTED MAP",
    (sfVector2f) {1400, 650}, 25, sfWhite);
    game->menu->selection[7] = create_sprite("resources/LevelSelect.png",
    (sfVector2f) {1375, 640}, (sfIntRect) {0, 0, 580, 100},
    (sfVector2f) {0.5, 0.5});
}

void init_menu2(t_game *game)
{
    game->menu->selection[6] = create_sprite("resources/UnderMenu.png",
    (sfVector2f) {1200, 200}, (sfIntRect) {0, 0, 660, 615},
    (sfVector2f) {1, 1});
    game->menu->texts[6] = create_text(HOWTOPLAY, (sfVector2f) {1260, 400}, 30,
    sfWhite);
    game->menu->texts[7] = create_text(BENVENUTO, (sfVector2f) {1260, 300}, 25,
    sfWhite);

    t_text **levels = malloc(sizeof(t_text *) * 9);
    game->menu->levels = levels;
    game->menu->levels[0] = create_text("MAP 1", (sfVector2f) {1350, 350}, 25,
    sfWhite);
    game->menu->levels[1] = create_text("MAP 2", (sfVector2f) {1600, 350}, 25,
    sfWhite);
    game->menu->levels[2] = create_text("MAP 3", (sfVector2f) {1350, 425}, 25,
    sfWhite);

    init_menu3(game);
}

void init_menu1(t_game *game)
{
    t_sprite **sprt = malloc(sizeof(t_sprite *) * 8);
    sprt[0] = create_sprite("resources/BtnSelect.png", (sfVector2f) {0, 0},
    (sfIntRect) {0, 0, 795, 200}, (sfVector2f) {0.75, 0.8});
    sprt[1] = create_sprite("resources/ButtonUp.png", (sfVector2f) {170, 50},
    (sfIntRect) {0, 0, 670, 110}, (sfVector2f) {0.97, 1});
    sprt[2] = create_sprite("resources/Button1.png", (sfVector2f) {107, 150},
    (sfIntRect) {0, 0, 560, 120}, (sfVector2f) {1.5, 1.5});
    sprt[3] = create_sprite("resources/Button2.png", (sfVector2f) {107, 340},
    (sfIntRect) {0, 0, 560, 120}, (sfVector2f) {1.5, 1.5});
    sprt[4] = create_sprite("resources/Button3.png", (sfVector2f) {107, 530},
    (sfIntRect) {0, 0, 560, 120}, (sfVector2f) {1.5, 1.5});
    sprt[5] = create_sprite("resources/Button4.png", (sfVector2f) {107, 720},
    (sfIntRect) {0, 0, 560, 120}, (sfVector2f) {1.5, 1.5});

    game->menu->selection = sprt; game->menu->hover = 0;
    game->menu->menustate = WELCOME; game->menu->lvlhover = 0;

    init_menu2(game);
}

void init_menu(t_game *game)
{
    t_menu *menu = malloc(sizeof(t_menu)); menu->background = create_sprite
    ("resources/Background_menu.png", (sfVector2f) {0, 0},
    (sfIntRect) {0, 0, 3840, 2160}, (sfVector2f) {0.5, 0.5});
    game->menu = menu; game->menu->lvl = 42;

    t_text **texts = malloc(sizeof(t_text *) * 8);
    texts[0] = create_text("PLAY", (sfVector2f) {300, 210}, 50,
    sfColor_fromRGB(60, 60, 60));
    texts[1] = create_text("OPTIONS", (sfVector2f) {300, 400}, 50,
    sfColor_fromRGB(60, 60, 60));
    texts[2] = create_text("HOW TO PLAY", (sfVector2f) {300, 590}, 50,
    sfColor_fromRGB(60, 60, 60));
    texts[3] = create_text("EXIT", (sfVector2f) {300, 780}, 50,
    sfColor_fromRGB(60, 60, 60));
    game->menu->texts = texts;

    init_menu1(game);
}
