/*
** EPITECH PROJECT, 2022
** test
** File description:
** test
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "../my.h"

int open_to_str(char const *filepath, reverse_t *reverse)
{
    struct stat st_size;
    stat(filepath, &st_size);
    char *buff = malloc(sizeof(char *) * st_size.st_size + 1);
    if (st_size.st_size == 0)
        return 84;
    int fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        return (84);
    }
    read(fd, buff, st_size.st_size);
    buff[st_size.st_size] = '\0';
    close(fd);
    reverse->text = buff;
    return (0);
}
