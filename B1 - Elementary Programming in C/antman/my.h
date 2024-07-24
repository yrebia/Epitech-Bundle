/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** my.h
*/

#include <unistd.h>

#ifndef MY_H_
    #define MY_H_

typedef struct noeud {
    char valeur;
    int occurence;
    struct noeud *fils_gauche;
    struct noeud *fils_droit;
} noeud_t;

typedef struct huffman {
    struct noeud **arbre;
    char *text;
    char *table;
    int *frequence;
    char **code;
    char *tmp_code;
    int size;
    int true_size;
    char *bin;
    char *final_bin;
} huffman_t;

typedef struct reverse {
    char *text;
    char *a_decoder;
    char *table;
    char **key;
} reverse_t;

// lib
int my_getnbr(char const *);
int my_strcmp(char const *, char const *);
int my_strlen(char const *);
void my_putchar(char);
void my_putstr(char *);
int my_put_nbr(int);
char *my_strcat(char *, char const *);
char *my_strcpy(char const *);
char *my_revstr(char *str);

// antman :
// main
void add_code(huffman_t *, char);
void del_one_code(huffman_t *);
void parcours(huffman_t *, noeud_t *);
void fill_bin(huffman_t *);

// file
int open_file(huffman_t *, char const *);
int fill_code(huffman_t *, int);
void destroy(huffman_t *);

// frequence_sort
void frequence_add(huffman_t *, char);
void frequence(huffman_t *);
void node(huffman_t *);
void swap_elem(huffman_t *, int, int);
void sort(huffman_t *);

// tree
noeud_t *create_node(int, char, noeud_t *, noeud_t *);
void make_tree(huffman_t *, int);
void tree(huffman_t *);

// final_print
char *add_a_one(char *);
int bin_to_dec(char *);
char *dec_to_ascii(int);
void code(huffman_t *);
void final_print(huffman_t *);

// giantman :

int open_to_str(char const *filepath, reverse_t *reverse);
int get_ascii(char *str);
char *convert_nbr_bin(int nb);
char *my_revstr(char *str);
int extract_code(reverse_t *reverse);
int get_txt(reverse_t *reverse);
int get_keys(reverse_t *reverse);
int get_code(reverse_t *reverse);
int extract_code2(reverse_t *reverse, int i, int j, int t);

#endif
