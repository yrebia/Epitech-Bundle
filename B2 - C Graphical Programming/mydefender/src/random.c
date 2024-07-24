/*
** EPITECH PROJECT, 2022
** RANDOM
** File description:
** Functions generating random
*/

#include "../include/my.h"

int random_it(FILE *path)
{
    int seed = 0;

    if (fread(&seed, sizeof(seed), 1, path) == 1) {
        fclose(path);
        srand(seed);
        return 0;
    }

    fclose(path);
    return -1;
}

void set_random(void)
{
    if (!random_it(fopen("/dev/urandom", "r")))
        return;
    if (!random_it(fopen("/dev/arandom", "r")))
        return;
    if (!random_it(fopen("/dev/random", "r")))
        return;
}
