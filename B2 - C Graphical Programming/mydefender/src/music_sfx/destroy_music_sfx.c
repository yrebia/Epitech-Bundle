/*
** EPITECH PROJECT, 2022
** DESTROY_MUSIC_SFX
** File description:
** Function destroying musics ans sfx
*/

#include "../../include/my.h"

void destroy_music_sfx(t_game *game)
{
    sfMusic_destroy(game->music->game);
    sfMusic_destroy(game->music->menu);
    sfMusic_destroy(game->music->shot);
}
