/*
** EPITECH PROJECT, 2021
** file
** File description:
** file
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

void init_music(game_t *game)
{
    game->jump = sfMusic_createFromFile("asset/level1/jump.ogg");
    game->dead = sfMusic_createFromFile("asset/level1/death.ogg");
    game->win_sfx = sfMusic_createFromFile("asset/level1/win.ogg");
    game->music = sfMusic_createFromFile("asset/level1/music.ogg");
    sfMusic_setLoop(game->music, sfTrue), sfMusic_setVolume(game->music, 50);
}

char *read_file(game_t *game, char const *filepath)
{
    char *buff = malloc(sizeof(char) * 200);
    char str[1];
    int fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        game->error = 84, buff[0] = '\0';
        return (buff);
    }
    int i = 0;
    for (int size = 1; size != 0;) {
        size = read(fd, str, 1);
        if (size == 0)
            break;
        buff[i] = str[0], i++;
    }
    buff[i] = '\0', close(fd);
    return (buff);
}

void write_score(game_t *game)
{
    char *new = to_c(game->points);
    int fd;
    if (game->level == 1)
        fd = open("asset/level1/best.txt", O_WRONLY);
    if (game->level == 2)
        fd = open("asset/level2/best.txt", O_WRONLY);
    if (game->level == 3)
        fd = open("asset/level3/best.txt", O_WRONLY);
    if (game->level == 4)
        fd = open("asset/level4/best.txt", O_WRONLY);
    write(fd, new, my_strlen(new));
    close(fd);
}

int load_file_in_mem(char const *filepath, game_t *game)
{
    char *buff = malloc(sizeof(char) * 300);
    int fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        game->error = 84;
        return (84);
    }
    read(fd, buff, 300);
    close(fd);
    game->map = buff;
}
