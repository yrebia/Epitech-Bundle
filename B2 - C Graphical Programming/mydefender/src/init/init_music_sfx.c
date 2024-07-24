/*
** EPITECH PROJECT, 2022
** INIT_MUSIC_SFX
** File description:
** File initializing music and sfx
*/

#include "../../include/my.h"

void init_music_sfx(t_game *game)
{
    t_music *music = malloc(sizeof(t_music));
    music->shot = sfMusic_createFromFile("resources/shot.ogg");
    sfMusic_setVolume(music->shot, 50);
    music->menu = sfMusic_createFromFile("resources/menu.ogg");
    sfMusic_setLoop(music->menu, sfTrue);
    sfMusic_setVolume(music->menu, 50);
    music->game = sfMusic_createFromFile("resources/game.ogg");
    sfMusic_setLoop(music->game, sfTrue);
    sfMusic_setVolume(music->game, 50);
    game->music = music;
    sfMusic_play(game->music->menu);
}
