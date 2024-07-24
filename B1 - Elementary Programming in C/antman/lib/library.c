/*
** EPITECH PROJECT, 2021
** Navy
** File description:
** Library
*/

#include <unistd.h>

int my_getnbr(char const *str)
{
    int negative = 1;
    int result = 0;
    for (int c = 0; str[c] != '\0'; c++) {
        if (str[c] == '-')
            negative *= - 1;
        if (str[c] >= '0' && str[c] <= '9')
            result += str[c] - 48;
        if (str[c + 1] >= '0' && str[c + 1] <= '9')
            result *= 10;
    }
    return (result * negative);
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]) {
        i++;
    }
    return (s1[i] - s2[i]);
}

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
