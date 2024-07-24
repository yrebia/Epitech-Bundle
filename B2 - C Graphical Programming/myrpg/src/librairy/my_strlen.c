/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** String Lenght
*/

#include "../../include/mystruct.h"

int my_strlen(char const *str)
{
    int a = 0;
    while (str[a] != '\0')
        a = a + 1;
    return (a);
}
