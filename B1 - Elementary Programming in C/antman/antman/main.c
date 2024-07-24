/*
** EPITECH PROJECT, 2022
** main antman
** File description:
** main antman
*/

#include "../my.h"
#include <stdlib.h>

void add_code(huffman_t *huffman, char valeur)
{
    int i = 0;
    while (huffman->table[i] != valeur) {
        if (huffman->table[i] == '\0')
            break;
        i++;
    }
    huffman->code[i] = my_strcpy(huffman->tmp_code);
}

void del_one_code(huffman_t *huffman)
{
    int i = 0;
    while (huffman->tmp_code[i] != '\0')
        i++;
    if (i > 0)
        huffman->tmp_code[i - 1] = '\0';
}

void parcours(huffman_t *huffman, noeud_t *noeud)
{
    if (noeud->valeur == 0) {
        huffman->tmp_code = my_strcat(huffman->tmp_code, "0\0");
        parcours(huffman, noeud->fils_gauche);
        huffman->tmp_code = my_strcat(huffman->tmp_code, "1\0");
        parcours(huffman, noeud->fils_droit);
    } else
        add_code(huffman, noeud->valeur);
    del_one_code(huffman);
    return;
}

void fill_bin(huffman_t *huffman)
{
    int i = 0;
    int j = 0;
    while (huffman->text[i] != '\0') {
        while (huffman->text[i] != huffman->table[j])
            j++;
        huffman->bin = my_strcat(huffman->bin, huffman->code[j]);
        i++, j = 0;
    }
}

int main(int ac, char **av)
{
    huffman_t huffman;
    if (ac != 3 || open_file(&huffman, av[1]) == 84)
        return (84);
    huffman.table = malloc(sizeof(char) * (my_strlen(huffman.text) + 1));
    huffman.frequence = malloc(sizeof(int) * (my_strlen(huffman.text) + 1));
    huffman.tmp_code = malloc(sizeof(char) * 7);
    huffman.code = malloc(sizeof(char *) * (my_strlen(huffman.text) + 1));
    huffman.bin = malloc(sizeof(char) * (my_strlen(huffman.text) * 7));
    huffman.table[0] = '\0', huffman.tmp_code[0] = '\0', huffman.bin[0] = '\0';
    frequence(&huffman);
    huffman.true_size = my_strlen(huffman.table);
    huffman.arbre = malloc(sizeof(noeud_t *) * (huffman.true_size + 2));
    node(&huffman), sort(&huffman), tree(&huffman);
    parcours(&huffman, huffman.arbre[0]);
    fill_bin(&huffman), final_print(&huffman);
    destroy(&huffman);
    return (0);
}
