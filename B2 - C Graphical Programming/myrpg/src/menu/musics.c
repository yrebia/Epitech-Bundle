/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** Music
*/

#include "../../include/mystruct.h"

void music_menu(rpg_t *rpg)
{
    rpg->musics.music_menu = sfMusic_createFromFile("assets/main_theme.ogg");
    sfMusic_setLoop(rpg->musics.music_menu, sfTrue);
    sfMusic_play(rpg->musics.music_menu);
    sfMusic_setVolume(rpg->musics.music_menu, 50);
}

void run_song(rpg_t *rpg)
{
    rpg->musics.run_song = sfMusic_createFromFile("assets/run_song.ogg");
    sfMusic_setLoop(rpg->musics.run_song, sfTrue);
    sfMusic_play(rpg->musics.run_song);
    sfMusic_setVolume(rpg->musics.run_song, 0);
}

void click_song(rpg_t *rpg)
{
    rpg->musics.click_song = sfMusic_createFromFile("assets/click_song.ogg");
    sfMusic_setVolume(rpg->musics.click_song, 50);
    sfMusic_setVolume(rpg->musics.click_song, rpg->options.volume);
    sfMusic_play(rpg->musics.click_song);
}
