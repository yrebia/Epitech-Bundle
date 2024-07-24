/*
** EPITECH PROJECT, 2022
** frequence and sort
** File description:
** frequence and sort
*/

#include "../my.h"
#include <stdlib.h>

void frequence_add(huffman_t *huffman, char c)
{
    int i = 0;
    while (huffman->table[i] != c) {
        if (huffman->table[i] == '\0')
            break;
        i++;
    }
    if (huffman->table[i] == '\0') {
        huffman->table[i] = c, huffman->frequence[i] = 1;
        huffman->table[i + 1] = '\0';
    } else
        huffman->frequence[i] += 1;
}

void frequence(huffman_t *huffman)
{
    int i = 0;
    while (huffman->text[i] != '\0') {
        frequence_add(huffman, huffman->text[i]);
        i++;
    }
}

void node(huffman_t *huffman)
{
    int i = 0;
    while (huffman->table[i] != '\0') {
        noeud_t *tmp = malloc(sizeof(noeud_t));
        tmp->valeur = huffman->table[i];
        tmp->occurence = huffman->frequence[i];
        huffman->arbre[i] = tmp;
        i++;
    }
    huffman->arbre[i] = 0;
}

void swap_elem(huffman_t *huffman, int index1, int index2)
{
    noeud_t *tmp = huffman->arbre[index1];
    huffman->arbre[index1] = huffman->arbre[index2];
    huffman->arbre[index2] = tmp;
}

void sort(huffman_t *huffman)
{
    int s = 0;
    for (int i = 0; i < huffman->true_size - 1; i++) {
        if (huffman->arbre[i]->occurence < huffman->arbre[i + 1]->occurence)
            swap_elem(huffman, i, i + 1), s = 1;
    }
    if (s == 1)
        sort(huffman);
}
