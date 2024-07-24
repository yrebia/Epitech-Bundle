/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** my.h
*/

#include <unistd.h>

#ifndef MY_H_
    #define MY_H_

typedef struct list {
    int value;
    struct list *next;
} list_t;

typedef struct swap {
    list_t *list_a;
    int len_a;
    int len_b;
} swap_t;

int my_getnbr(char const *);
int my_strlen(char const *);
void my_putchar(char);
void my_putstr(char *);
void init_swap(swap_t *, int, char **);
int is_sorted(swap_t *);
int minimum(swap_t *);
void sort(swap_t *);
void best_way(swap_t *, int, int *);
void move_first(swap_t *, int);
void swap_first(swap_t *, int *);
void rotate_left(swap_t *, int, int *);
void rotate_right(swap_t *, int, int *);
int is_num(char);
int check_argv(int, char **);
list_t *creat_cel(int);

#endif
