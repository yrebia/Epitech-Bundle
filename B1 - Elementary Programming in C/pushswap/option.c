/*
** EPITECH PROJECT, 2021
** option
** File description:
** option
*/

#include "my.h"
#include <stdlib.h>

int is_num(char c)
{
    if ((c > 47 && c < 58) || c == 45)
        return (0);
    return (84);
}

int check_argv(int ac, char **av)
{
    int test = 0;
    for (int i = 1; i < ac; i++) {
        for (int j = 0; j < my_strlen(av[i]); j++)
            test += is_num(av[i][j]);
        if (test != 0)
            return (84);
    }
    return (0);
}

list_t *creat_cel(int value)
{
    list_t *cel = malloc(sizeof(list_t));
    cel->value = value;
    cel->next = 0;
    return (cel);
}
