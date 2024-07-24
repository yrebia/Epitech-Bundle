/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** String Compare
*/

#include "../../include/mystruct.h"

int my_strcmp(char const *s1, char const *s2)
{
    int letter = 0;

    while (s1[letter] != '\0' && s2[letter] != '\0'
    && s1[letter] == s2[letter]) {
        letter++;
    }
    return (s1[letter] - s2[letter]);
}
