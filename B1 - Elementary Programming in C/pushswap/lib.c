/*
** EPITECH PROJECT, 2021
** lib
** File description:
** lib
*/

#include "my.h"

int my_strlen(char const *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}

int my_getnbr(char const *str)
{
    int i = 0;
    int n = 0;
    int isneg = 1;
    if (str[i] == '-')
        isneg *= -1, i++;
    while (str[i] != '\0') {
        if (str[i] <= '9' && str[i] >= '0') {
            n *= 10;
            n += str[i] - '0';
            i++;
        } else
            return (n * isneg);
    }
    return (n * isneg);
}
