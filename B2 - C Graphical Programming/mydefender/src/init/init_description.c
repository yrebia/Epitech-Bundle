/*
** EPITECH PROJECT, 2022
** INIT_DESCRIPTION
** File description:
** Functions initializing tile descriptions
*/

#include "../../include/my.h"

void init_description2(t_game *game, char **tab)
{
    for (int i = 3; i < 5; i++) {
        if (i == SPAWN)
            game->description[SPAWN] = create_text(tab[SPAWN],
            (sfVector2f) {1520, 10}, 20, sfColor_fromRGB(128, 128, 128));
        if (i == PATH)
            game->description[PATH] = create_text(tab[PATH],
            (sfVector2f) {1520, 10}, 20, sfColor_fromRGB(255, 125, 0));
    }
}

void init_description1(t_game *game, char **tab)
{
    for (int i = 0; i < 3; i++) {
        if (i == GRASS)
            game->description[GRASS] = create_text(tab[GRASS],
            (sfVector2f) {1520, 10}, 20, sfColor_fromRGB(0, 100, 0));
        if (i == WALL)
            game->description[WALL] = create_text(tab[WALL],
            (sfVector2f) {1520, 10}, 20, sfColor_fromRGB(0, 0, 0));
        if (i == CASTLE)
            game->description[CASTLE] = create_text(tab[CASTLE],
            (sfVector2f) {1520, 10}, 20, sfColor_fromRGB(255, 255, 255));
    }
    init_description2(game, tab);
}

void init_description(t_game *game)
{
    char **tab = malloc(sizeof(char *) * 6);
    tab[GRASS] = "\t     GRASS\n\n\n\n  What a green grass !";
    tab[WALL] = TABWALL;
    tab[CASTLE] = TABCASTLE;
    tab[SPAWN] = TABSPAWN;
    tab[PATH] = "\t      PATH\n\n\n\n  What a big path !"; tab[5] = '\0';

    t_sprite **tmp = malloc(sizeof(t_sprite *) * 5);
    tmp[GRASS] = create_textbox("resources/TextBoxGrass.png");
    tmp[WALL] = create_textbox("resources/TextBoxWall.png");
    tmp[CASTLE] = create_textbox("resources/TextBoxCastle.png");
    tmp[SPAWN] = create_textbox("resources/TextBoxWall.png");
    tmp[PATH] = create_textbox("resources/TextBoxGrass.png");
    game->txtbox = tmp;

    init_description1(game, tab);
}
