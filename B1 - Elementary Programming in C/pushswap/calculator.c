/*
** EPITECH PROJECT, 2021
** calculator
** File description:
** calculator
*/

#include "my.h"
#include <stdlib.h>

void move_first(swap_t *swap, int first)
{
    if (first == 0)
        my_putstr("pb");
    else
        my_putstr(" pb");
    swap->list_a = swap->list_a->next;
    swap->len_a -= 1;
    swap->len_b += 1;
}

void swap_first(swap_t *swap, int *first)
{
    if (*first == 0)
        my_putstr("sa");
    else
        my_putstr(" sa");
    *first = 1;
    list_t *tmp = swap->list_a;
    swap->list_a = swap->list_a->next;
    tmp->next = swap->list_a->next;
    swap->list_a->next = tmp;
}

void rotate_left(swap_t *swap, int min, int *first)
{
    if (*first == 0)
        my_putstr("ra");
    else
        my_putstr(" ra");
    *first = 1;
    int value = swap->list_a->value;
    swap->list_a = swap->list_a->next;
    list_t *tmp = swap->list_a;
    for (int i = 1; i < swap->len_a - 1; i++)
        tmp = tmp->next;
    free(tmp->next);
    tmp->next = creat_cel(value);
    if (swap->list_a->value != min)
        rotate_left(swap, min, first);
}

void rotate_right(swap_t *swap, int min, int *first)
{
    if (*first == 0)
        my_putstr("rra");
    else
        my_putstr(" rra");
    *first = 1;
    list_t *list = swap->list_a;
    list_t *tmp = swap->list_a;
    for (int i = 0; i < swap->len_a - 1; i++)
        tmp = tmp->next;
    int value = tmp->value;
    swap->list_a = creat_cel(value);
    swap->list_a->next = list;
    free(tmp->next);
    if (swap->list_a->value != min)
        rotate_right(swap, min, first);
}

void best_way(swap_t *swap, int min, int *first)
{
    int i = 0;
    list_t *tmp = swap->list_a;
    while (tmp->value != min)
        i++, tmp = tmp->next;
    if (i == 0)
        return;
    if (i == 1)
        swap_first(swap, first);
    else if (i < swap->len_a / 2)
        rotate_left(swap, min, first);
    else
        rotate_right(swap, min, first);
}
