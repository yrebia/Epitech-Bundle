/*
** EPITECH PROJECT, 2021
** file
** File description:
** get number and board
*/

#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char *fs_get_first_line(char const *filepath)
{
    char buff[1];
    buff[0] = '\0';
    char *str = malloc(sizeof(char) * 10);
    int fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return (0);
    int i = 0;
    for (int size = 1; size != 0;) {
        size = read(fd, buff, 1);
        if (buff[0] != '\n') {
            str[i] = buff[0];
            i++;
        } else
            break;
    }
    str[i] = '\0';
    close(fd);
    return (str);
}

int fs_get_number_from_first_line(char const *filepath)
{
    char *str = fs_get_first_line(filepath);
    if (str == 0)
        return (-1);
    int i = 0;
    int n = 0;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return (-1);
        n = (n * 10) + str[i] - '0';
    }
    free(str);
    return (n);
}

char *load_file_in_mem(char const *filepath)
{
    struct stat statbuf;
    stat(filepath, &statbuf);
    char *buff = malloc(sizeof(char) * statbuf.st_size + 1);
    char str[1];
    int fd = open(filepath, O_RDONLY);
    if (fd == -1)
        exit (84);
    int i = 0;
    for (int size = 1; size != 0;) {
        int compt = 0;
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

char *load_board(char const *filepath)
{
    char *buff = load_file_in_mem(filepath);
    int i = 0;
    int j = 0;
    while (buff[i] != '\n') {
        if (buff[i] == '\0')
            exit(84);
        i++;
    }
    i++;
    while (buff[i] != '\0') {
        buff[j] = buff[i];
        i++, j++;
    }
    buff[j] = '\0';
    return (buff);
}
