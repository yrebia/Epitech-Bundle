/*
** EPITECH PROJECT, 2022
** final print
** File description:
** final print
*/

#include "../my.h"
#include <stdlib.h>

char *add_a_one(char *code)
{
    int i = 1;
    int j = 0;
    char *new = malloc(my_strlen(code) + 2);
    new[0] = '1';
    while (code[j] != '\0')
        new[i] = code[j], i++, j++;
    free(code);
    new[i] = '\0';
    return (new);
}

int bin_to_dec(char *bi)
{
    int i = my_strlen(bi) - 1;
    int c = 0;
    int b = 1;
    while (i >= 0) {
        if (bi[i] == '1')
            c += b;
        b *= 2;
        i--;
    }
    return (c);
}

char *dec_to_ascii(int dec)
{
    int dix = 1;
    int i = 0;
    int tmp = 0;
    char *code = malloc(sizeof(char) * 10);
    while ((dec / dix) >= 10)
        dix *= 10, i++;
    if ((i % 2) == 0)
        code[0] = (dec / dix) % 10, dix /= 10, i = 1;
    else
        i = 0;
    while (dix > 0) {
        tmp += (dec / dix) % 10, tmp *= 10, dix /= 10;
        tmp += (dec / dix) % 10, dix /= 10;
        if (tmp == 0)
            tmp = 107;
        code[i] = tmp, i++, tmp = 0;
    }
    code[i] = '\0';
    return (code);
}

void code(huffman_t *huffman)
{
    int i = 0;
    while (huffman->bin[i] != '\0') {
        i = fill_code(huffman, i);
    }
}

void final_print(huffman_t *huffman)
{
    int dec;
    char *tmp;
    code(huffman);
    for (int i = 0; huffman->table[i] != '\0'; i++) {
        my_putchar('|');
        my_putchar(huffman->table[i]);
        huffman->code[i] = add_a_one(huffman->code[i]);
        dec = bin_to_dec(huffman->code[i]);
        tmp = dec_to_ascii(dec);
        my_putstr(tmp);
        free(tmp);
    }
}
