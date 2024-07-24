/*
** EPITECH PROJECT, 2021
** bsq
** File description:
** bsq
*/

#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char *draw_square(char *board, int max, int x)
{
    int i = 0;
    int a = x;
    while (board[i] != '\n')
        i++;
    int ligne = i + 1;
    for (i = 0; i < max; i++) {
        for (int j = 0; j < max; j++)
            board[x] = 'x', x++;
        x = ligne * (i + 1) + a;
    }
    return (board);
}

int check_max(char *board, int x)
{
    int max;
    int i = x;
    int c = 0;
    while (board[i] == '.')
        i++;
    max = i, i = x;
    while (board[i] != '\0') {
        if (board[i] == '\n')
            c++;
        i++;
    }
    if (c < max)
        return (c);
    return (max);
}

int check_obstacle(char *board, int x, int max, int j)
{
    if (board[x] == 'o')
        return (j);
    return (max);
}

int biggest_square(char *board, int x)
{
    int max = check_max(board, x);
    int i = 0;
    int j = 0;
    int a = x;
    int c = 0;
    while (board[i] != '\n')
        i++;
    int ligne = i + 1;
    i = 0;
    while (i < max) {
        while (j < max) {
            max = check_obstacle(board, x, max, j);
            j++, x++;
        }
        c = i, i++, x = ligne * i + a, j = 0;
    }
    if (c > max)
        return (c);
    return (max);
}

void bsq(char *board, int size)
{
    int i = 0;
    int max = 0;
    int x = 0;
    while (board[i] != '\0') {
        if (board[i] == '\n')
            i++;
        if (biggest_square(board, i) > max)
            max = biggest_square(board, i), x = i;
        if (biggest_square(board, i) > 1)
            i += biggest_square(board, i) + 2;
        else
            i++;
    }
    my_putstr(draw_square(board, max, x));
}
