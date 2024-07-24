/*
** EPITECH PROJECT, 2021
** lib
** File description:
** lib
*/

#include "../include/my.h"

int my_put_nbr(int nb)
{
    int dix = 1;
    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    while ((nb / dix) >= 10) {
        dix *= 10;
    }
    while (dix > 0) {
        my_putchar((nb / dix) % 10 + 48);
        dix /= 10;
    }
    return (0);
}

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;
    char *new = malloc(my_strlen(dest) + my_strlen(src) + 1);
    while (dest[i] != '\0')
        new[i] = dest[i], i++;
    while (src[j] != '\0')
        new[i] = src[j], i++, j++;
    new[i] = '\0';
    return (new);
}

char *to_c(int v)
{
    int i = 0;
    int dix = 1;
    char *num = malloc(10000);
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
