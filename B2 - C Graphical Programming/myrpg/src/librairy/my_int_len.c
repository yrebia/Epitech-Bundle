/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** Int Lenght
*/

#include "../../include/mystruct.h"

int my_int_len(int nb)
{
    int len = 0;
    if (nb < 0) {
        len++;
        nb = -nb;
    }
    while (nb > 0) {
        nb = nb / 10;
        len++;
    }
    return (len);
}
