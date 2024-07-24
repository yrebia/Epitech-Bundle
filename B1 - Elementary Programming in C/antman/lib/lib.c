/*
** EPITECH PROJECT, 2021
** lib
** File description:
** lib
*/

#include <stdlib.h>
#include "../my.h"

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
    while (dest[i] != '\0') {
        i++;
    }
    while (src[j] != '\0') {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return (dest);
}

char *my_strcpy(char const *src)
{
    char *dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char *my_revstr(char *str)
{
    char swap;
    int a = 0;
    int b = my_strlen(str) - 1;

    while (a < b) {
        swap = str[a];
        str[a] = str[b];
        str[b] = swap;
        a++;
        b--;
    }
    return str;
}
