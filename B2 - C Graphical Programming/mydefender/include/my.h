/*
** EPITECH PROJECT, 2021
** MY_H
** File description:
** Header file for the project
*/

#include "defender.h"

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>

#ifndef MY_H_
    #define MY_H_
    #define _USE_MATH_DEFINES

void my_putstr(char const *str);

char *my_strcat(char *dest, char const *src);
char *my_int_to_str(int v);

int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);

#endif

#define TRUE    1
#define FALSE   0

#define UNDERLINE   "\033[04m"
#define BOLD        "\033[01m"
#define NORMAL      "\033[00m"
#define RESET       "\033[0m"
#define BLACK       "\033[30m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"
#define WHITE       "\033[37m"

#define BUFFER_SIZE 4096
