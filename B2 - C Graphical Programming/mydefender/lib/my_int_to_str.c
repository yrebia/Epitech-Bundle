/*
** EPITECH PROJECT, 2022
** MY_INT_TO_STR
** File description:
** Function converting int into str
*/

#include "../include/my.h"

char *my_int_to_str(int v)
{
    int i = 0;
    int dix = 1;
    char *num = malloc(sizeof(char) * 20);
    while ((v / dix) >= 10)
        dix *= 10;
    while (dix > 0) {
        num[i] = ((v / dix) % 10 + '0');
        dix /= 10;
        i++;
    }
    num[i] = '\0';
    return (num);
}
