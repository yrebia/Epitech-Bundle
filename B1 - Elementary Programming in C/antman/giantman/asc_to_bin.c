/*
** EPITECH PROJECT, 2022
** asc_to_bin
** File description:
** test
*/

#include <stdlib.h>
#include <unistd.h>
#include "../my.h"

char *convert_nbr_bin(int nb)
{
    char *str;
    reverse_t reverse;
    int i = 0;

    str = malloc(sizeof(char) * 500);
    while (nb >= 1) {
        if (nb % 2 == 0)
            str[i] = '0';
        else
            str[i] = '1';
        nb = nb / 2;
        i++;
    }
    str[i] = '\0';
    return str;
}

int get_ascii(char *str)
{
    int i = 0;
    int final = 0;

    while (str[i] != '\0') {
        if (str[i] == 'k') {
            final *= 100;
        } else {
            final *= 100;
            final += str[i];
        }
        i++;
    }
    str[i] = '\0';
    return final;
}

int get_keys(reverse_t *reverse)
{
    int i = 0;
    int askey = 0;
    char *tmp = malloc(sizeof(char) * 31);

    while (reverse->key[i] != 0) {
        tmp = reverse->key[i];
        askey = get_ascii(tmp);
        tmp = convert_nbr_bin(askey);
        tmp[my_strlen(tmp) - 1] = '\0';
        tmp = my_revstr(tmp);
        reverse->key[i] = my_strcpy(tmp);
        i++;
    }
    reverse->key[i] = 0;
    free(tmp);
    return 0;
}

int get_txt(reverse_t *reverse)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char *tmp = malloc(sizeof(char) * my_strlen(reverse->text));
    while (reverse->a_decoder[i] != '\0') {
        tmp[k] = reverse->a_decoder[i];
        tmp[k + 1] = '\0';
        while (reverse->key[j] != 0) {
            if (my_strcmp(tmp, reverse->key[j]) == 0) {
                my_putchar(reverse->table[j]);
                k = -1;
                tmp[0] = '\0';
            }
            j++;
        }
        j = 0, i++, k++;
    }
    free(tmp);
    return 0;
}

int main(int ac, char **av)
{
    reverse_t reverse;
    if (ac != 3 || open_to_str(av[1], &reverse) == 84)
        return 84;
    reverse.a_decoder = malloc(sizeof(char) * my_strlen(reverse.text) * 7);
    get_code(&reverse);
    extract_code(&reverse);
    get_keys(&reverse);
    get_txt(&reverse);
    free(reverse.key);
    free(reverse.table);
}
