/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** Int To Char
*/

#include "../../include/mystruct.h"

char *int_to_char(int number)
{
    char *str = malloc(sizeof(char) * my_int_len(number) + 1);
    int i = 0;

    if (number == 0) {
        str[i] = '0';
        str[i + 1] = '\0';
        return (str);
    }
    while (number > 0) {
        str[i] = number % 10 + '0';
        number = number / 10;
        i++;
    }
    str[i] = '\0';
    return (my_revstr(str));
}
