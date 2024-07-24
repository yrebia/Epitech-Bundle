/*
** EPITECH PROJECT, 2021
** main bsq
** File description:
** main bsq
*/

#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void empty_file(char *board, int size)
{
    int max = size;
    int i = 0;
    while (board[i] != '\n')
        i++;
    if (i < max)
        max = i;
    int l = i;
    i = 0;
    int m = max;
    for (int c = 0; c < max; c++) {
        while (i < m)
            board[i] = 'x', i++;
        while (board[i] != '\n')
            i++;
        m += l + 1, i++;
    }
    my_putstr(board);
}

void bsq_column(char *board)
{
    int i = 0;
    if (board[0] == 'o' && board[1] == '\n' && board[2] == '\0') {
        my_putstr("o\n");
        return;
    }
    while (board[i] != '.')
        i++;
    board[i] = 'x';
    my_putstr(board);
}

int main(int ac, char **av)
{
    if (ac != 2)
        return (84);
    int size = fs_get_number_from_first_line(av[1]);
    if (size == -1)
        return (84);
    char *file = load_board(av[1]);
    if (check_board(file, size) == 84 || check_board_content(file) == 84)
        return (84);
    if (file[1] == '\n' && check_board_content(file) != 1) {
        bsq_column(file);
        return (0);
    }
    if (check_board_content(file) == -1)
        empty_file(file, size);
    else if (check_board_content(file) == 1)
        my_putstr(file);
    else
        bsq(file, size);
    free(file);
    return (0);
}
