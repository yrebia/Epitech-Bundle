/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** Put String
*/

#include "../../include/mystruct.h"

void my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}
