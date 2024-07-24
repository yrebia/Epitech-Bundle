/*
** EPITECH PROJECT, 2022
** tree
** File description:
** make tree and nodes
*/

#include "../my.h"
#include <stdlib.h>

noeud_t *create_node(int occurence, char value, noeud_t *d, noeud_t *g)
{
    noeud_t *new = malloc(sizeof(noeud_t));
    new->fils_droit = d;
    new->fils_gauche = g;
    new->occurence = occurence;
    new->valeur = value;
    return (new);
}

void make_tree(huffman_t *huffman, int i)
{
    noeud_t **list_tmp = malloc(sizeof(noeud_t *) * (huffman->true_size + 2));
    huffman->size = huffman->true_size, huffman->true_size = 0;
    while (huffman->size >= 2) {
        noeud_t *tmp = malloc(sizeof(noeud_t));
        tmp->occurence = huffman->arbre[huffman->size - 1]->occurence +
            huffman->arbre[huffman->size - 2]->occurence;
        tmp->valeur = 0;
        tmp->fils_gauche = create_node(huffman->arbre[huffman->size -
            2]->occurence, huffman->arbre[huffman->size - 2]->valeur,
            huffman->arbre[huffman->size - 2]->fils_droit,
            huffman->arbre[huffman->size - 2]->fils_gauche);
        tmp->fils_droit = create_node(huffman->arbre[huffman->size -
            1]->occurence, huffman->arbre[huffman->size - 1]->valeur,
            huffman->arbre[huffman->size - 1]->fils_droit,
            huffman->arbre[huffman->size - 1]->fils_gauche);
        huffman->size -= 2, list_tmp[i] = tmp, huffman->true_size++, i++;
    }
    if (huffman->size == 1)
        list_tmp[i] = huffman->arbre[0], huffman->true_size++;
    huffman->arbre = list_tmp;
}

void tree(huffman_t *huffman)
{
    int i = 0;
    make_tree(huffman, i);
    sort(huffman);
    if (huffman->true_size > 1)
        tree(huffman);
}
