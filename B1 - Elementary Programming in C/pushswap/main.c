/*
** EPITECH PROJECT, 2021
** pushswap
** File description:
** pushswap
*/

#include "my.h"
#include <stdlib.h>

void init_swap(swap_t *swap, int ac, char **av)
{
    swap->list_a = malloc(sizeof(list_t));
    list_t *cel;
    swap->list_a->value = my_getnbr(av[ac - 1]);
    swap->list_a->next = NULL;
    for (int i = ac - 2; i > 0; i--) {
        cel = creat_cel(my_getnbr(av[i])), cel->next = swap->list_a;
        swap->list_a = cel;
    }
    swap->len_a = ac - 1, swap->len_b = 0;
}

int is_sorted(swap_t *swap)
{
    list_t *tmp = swap->list_a;
    for (int i = 0; i < swap->len_a - 1; i++) {
        if (tmp->value > tmp->next->value)
            return (-1);
        tmp = tmp->next;
    }
    return (0);
}

int minimum(swap_t *swap)
{
    list_t *tmp = swap->list_a;
    int min = tmp->value;
    tmp = tmp->next;
    for (int i = 1; i < swap->len_a; i++)  {
        if (tmp->value < min)
            min = tmp->value;
        tmp = tmp->next;
    }
    return (min);
}

void sort(swap_t *swap)
{
    int first = 0;
    int min;
    while (is_sorted(swap) != 0) {
        min = minimum(swap);
        best_way(swap, min, &first);
        if (is_sorted(swap) == 0)
            break;
        move_first(swap, first);
        first = 1;
    }
    for (int i = 0; i < swap->len_b; i++)
        my_putstr(" pa");
}

int main(int ac, char **av)
{
    swap_t swap;
    if (check_argv(ac, av) == 84)
        return (84);
    init_swap(&swap, ac, av);
    list_t *list = swap.list_a;
    int first = 0;
    if (is_sorted(&swap) != 0)
        sort(&swap);
    my_putchar('\n');
    free(swap.list_a);
    return (0);
}
