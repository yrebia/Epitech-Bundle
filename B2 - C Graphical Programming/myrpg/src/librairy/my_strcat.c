/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** String Catenation
*/

#include "../../include/mystruct.h"

char *my_strcat(char *dest, char const *src)
{
    char *result = malloc(sizeof(char) *
    (my_strlen(dest) + my_strlen(src)) + 1);
    int dest_len = my_strlen(dest);

    for (int i = 0; i < dest_len; i++)
        result[i] = dest[i];

    int i = 0;
    while (src[i] != '\0') {
        result[dest_len + i] = src[i];
        i++;
    }
    result[dest_len + i] = '\0';
    return result;
}
