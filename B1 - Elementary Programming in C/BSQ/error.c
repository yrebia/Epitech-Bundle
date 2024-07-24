/*
** EPITECH PROJECT, 2021
** error
** File description:
** error
*/

#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int check_board(char *board, int size)
{
    int n = 0;
    int c = 0;
    int max = 0;
    while (board[max] != '\n') {
        if (board[max] == '\0')
            return (84);
        max++;
    }
    for (int i = 0; board[i] != '\0'; i++) {
        if (board[i] == '\n' && c != max)
            return (84);
        else if (board[i] == '\n')
            c = 0, n++;
        else
            c++;
    }
    if (n != size)
        return (84);
    return (0);
}

int check_board_content(char *board)
{
    int i = 0;
    int p = 0;
    int o = 0;
    while (board[i] != '\0') {
        if (board[i] == '\n' || board[i] == 'o' || board[i] == '.')
            i++;
        else
            return (84);
        if (board[i] == 'o')
            o = 1;
        if (board[i] == '.')
            p = 1;
    }
    if (board[i - 1] != '\n')
        return (84);
    if (p == 1 && o == 0)
        return (-1);
    if (p == 0 && o == 1)
        return (1);
    return (0);
}
