/*
** EPITECH PROJECT, 2021
** my
** File description:
** prototypes
*/

#ifndef MY_H_
    #define MY_H_

int my_strlen(char const *);
void my_putchar(char);
void my_putstr(char *);
char *fs_get_first_line(char const *);
int fs_get_number_from_first_line(char const *);
char *load_file_in_mem(char const *);
char *load_board(char const *);
int check_board(char *, int);
int check_board_content(char *);
void bsq(char *, int);
char *draw_square(char *, int, int);
int check_max(char *, int);
int biggest_square(char *, int);
int check_obstacle(char *, int, int, int);

int my_put_nbr(int);
int fs_get_number_from_first_line(char const *);
char *fs_get_first_line(char const *);
void fs_print_first_line(char const *);
void fs_cat_x_bytes(char const *, int);
void fs_cat_500_bytes(char const *);
void fs_understand_return_of_read(int, char *, int);
int fs_open_file(char const *);
void array_1d_print_chars(char const *);
void array_1d_print_ints(int const *, int);
int array_1d_sum(int const *, int);
int array_2d_sum(int **, int, int);
int array_2d_how_many(int **, int, int, int);
char *mem_alloc(char const *, char const *);
char **mem_alloc_2d_array(int, int);
char **mem_dup_2d_array(char **, int, int);
char *load_file_in_mem(char const *);
char **load_2d_arr_from_file(char const *, int, int);

#endif
