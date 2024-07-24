/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** Main File
*/

#include "../include/mystruct.h"

void usage(void)
{

}

int main(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        usage();
        return EXIT_SUCCESS;
    }
    window();
    return EXIT_SUCCESS;
}
