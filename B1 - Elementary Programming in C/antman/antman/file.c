/*
** EPITECH PROJECT, 2022
** file
** File description:
** file
*/

#include "../my.h"
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int open_file(huffman_t *huffman, char const *filepath)
{
    struct stat statbuf;
    stat(filepath, &statbuf);
    char *buff = malloc(sizeof(char) * statbuf.st_size + 1);
    int fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return (84);
    read(fd, buff, statbuf.st_size);
    buff[statbuf.st_size] = '\0';
    close(fd);
    huffman->text = buff;
    return (0);
}

int fill_code(huffman_t *huffman, int i)
{
    char *tmp = malloc(sizeof(char) * 31);
    int dec = 0;
    int j = 0;
    if ((my_strlen(huffman->bin) - i) - 30 > 0) {
        while (j < 30)
            tmp[j] = huffman->bin[i], i++, j++;
    } else {
        while (j < my_strlen(huffman->bin) - i)
            tmp[j] = huffman->bin[i], i++, j++;
    }
    tmp[j] = '\0';
    tmp = add_a_one(tmp);
    dec = bin_to_dec(tmp), free(tmp);
    tmp = dec_to_ascii(dec);
    my_putstr(tmp), free(tmp);
    my_putchar('~');
    return (i);
}

void destroy(huffman_t *huffman)
{
    free(huffman->table);
    free(huffman->frequence);
    free(huffman->tmp_code);
    free(huffman->code);
    free(huffman->bin);
    free(huffman->arbre);
}
