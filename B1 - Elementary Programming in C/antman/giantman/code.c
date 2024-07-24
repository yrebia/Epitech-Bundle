/*
** EPITECH PROJECT, 2022
** code
** File description:
** code
*/

#include <stdlib.h>
#include <unistd.h>
#include "../my.h"

int extract_code2(reverse_t *reverse, int i, int j, int t)
{
    while (reverse->text[i] != '\0') {
        char *tmp = malloc(sizeof(char) * 10);
        reverse->table[j] = reverse->text[i];
        i++;
        while (reverse->text[i] != '|' && reverse->text[i] != '\0')
            tmp[t] = reverse->text[i], t++, i++;
        reverse->key[j] = tmp;
        t = 0;
        j++;
        if (reverse->text[i] == '\0')
            return 0;
        i++;
    }
    return 0;
}

int extract_code(reverse_t *reverse)
{
    int i = 0;
    int j = 0;
    int t = 0;
    reverse->key = malloc(sizeof(char *) * my_strlen(reverse->text));
    reverse->table = malloc(sizeof(char) * my_strlen(reverse->text));
    while (reverse->text[i] != '|') {
        if (reverse->text[i] == '\0')
            return 0;
        i++;
    }
    i++;
    extract_code2(reverse, i, j, t);
    return 0;
}

int get_code(reverse_t *reverse)
{
    int i = 0;
    int j = 0;
    int ascii;
    char *bin = malloc(sizeof(char) * (my_strlen(reverse->text) * 7));
    char *tmp = malloc(sizeof(char) * 31);
    reverse->a_decoder[0] = '\0';
    while (reverse->text[i] != '|') {
        tmp[j] = '\0';
        while (reverse->text[i] != '~') {
            if (reverse->text[i] == '\0') {
                break;
            }
            tmp[j] = reverse->text[i], i++, j++, tmp[j] = '\0';
        }
        j = 0, i++, ascii = get_ascii(tmp), bin = convert_nbr_bin(ascii);
        bin[my_strlen(bin) - 1] = '\0', bin = my_revstr(bin);
        reverse->a_decoder = my_strcat(reverse->a_decoder, bin);
    }
    free(bin), free(tmp);
    return 0;
}