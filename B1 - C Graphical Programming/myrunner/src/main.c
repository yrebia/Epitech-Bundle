/*
** EPITECH PROJECT, 2021
** main runner
** File description:
** main runner
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
#include "../include/my.h"

void change_skin(game_t *game, char *path_image)
{
    game->player->texture = sfTexture_createFromFile(path_image, NULL);
    sfSprite_setTexture(game->player->sprite, game->player->texture, sfTrue);
}

image_t *create_img(const char *path_image, float vel, int pos_x, int pos_y)
{
    image_t *image = malloc(sizeof(image_t));
    image->texture = sfTexture_createFromFile(path_image, NULL);
    image->sprite = sfSprite_create();
    image->velocity.x = vel;
    image->pos.x = pos_x, image->pos.y = pos_y;
    sfSprite_setTexture(image->sprite, image->texture, sfTrue);
    return (image);
}

int game_management(game_t *game)
{
    if (game->error == 84)
        return (84);
    if (game->play == 1)
        update_game(game);
    if (game->shop == 1)
        update_shop(game);
    if (game->menu == 1)
        update_menu(game);
    if (game->level_menu == 1)
        update_level_menu(game);
}

int check_flag(int ac, char **av, game_t *game)
{
    game->bonus = 0;
    if (ac == 2 && my_strcmp(av[1], "-h\0") == 0) {
        usage();
        return (1);
    }
    if (ac == 2 && my_strcmp(av[1], "-i\0") == 0)
        game->bonus = -1;
    else if (ac == 2)
        game->bonus = 1, game->filepath = av[1];
    return (0);
}

int main(int ac, char **av)
{
    game_t game;
    if (check_flag(ac, av, &game) == 1)
        return (0);
    init(&game);
    sfMusic_play(game.music);
    while (sfRenderWindow_isOpen(game.wind)) {
        while (sfRenderWindow_pollEvent(game.wind, &game.event))
            analyse_events(&game);
        if (game_management(&game) == 84)
            return (84);
        sfRenderWindow_display(game.wind);
    }
    destroy(&game);
    return (0);
}
