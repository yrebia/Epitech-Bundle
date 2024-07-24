/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** Reverse String
*/

#include "../../include/mystruct.h"

char *my_revstr(char *str)
{
    int i;
    int j;
    char variable;

    j = my_strlen(str) - 1;
    for (i = 0; i < j; i++) {
        variable = str[i];
        str[i] = str [j];
        str[j] = variable;
        j = j - 1;
    }
    return (str);
}
