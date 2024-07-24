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
#include "my.h"

char *read_file(char const *filepath)
{
    char *buff = malloc(sizeof(char) * 200);
    char str[1];
    int fd = open(filepath, O_RDONLY);
    if (fd == -1)
        exit (84);
    int i = 0;
    for (int size = 1; size != 0;) {
        size = read(fd, str, 1);
        if (size == 0)
            break;
        if (str[0] != '\n')
            buff[i] = str[0], i++;
        else if (buff[i - 1] != '\n')
            buff[i] = '\n', i++;
    }
    buff[i] = '\0', close(fd);
    return (buff);
}

void write_score(game_t *game)
{
    char *new = to_c(game->points);
    int fd = open("txt/score.txt", O_WRONLY);
    write(fd, new, my_strlen(new));
}
