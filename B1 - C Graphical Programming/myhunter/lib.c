/*
** EPITECH PROJECT, 2021
** lib
** File description:
** lib
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Export.h>
#include <SFML/System/Time.h>
#include <SFML/Window/Event.h>
#include <SFML/Audio.h>
#include <stddef.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]) {
        i++;
    }
    return (s1[i] - s2[i]);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int n = 0;
    while (str[i] != '\0') {
        if (str[i] <= '9' && str[i] >= '0') {
            n *= 10;
            n += str[i] - '0';
            i++;
        } else {
            return (n);
        }
    }
    return (n);
}

int my_strlen(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

char *cat(char *dest, char const *src)
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
