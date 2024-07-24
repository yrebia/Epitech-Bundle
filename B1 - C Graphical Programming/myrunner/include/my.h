/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** my.h
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Export.h>
#include <SFML/System/Time.h>
#include <SFML/Window/Event.h>
#include <SFML/Audio.h>
#include <stddef.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#ifndef MY_H_
    #define MY_H_
    #define SOULIGNE "\033[04m"
    #define ROUGE "\033[00;31m"
    #define GRAS "\033[01m"
    #define NORMAL "\033[00m"
    #define BLEU "\033[00;34m"
    #define VERT "\033[00;32m"
    #define MAGENTA "\033[00;35m"

typedef struct image {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f velocity;
    sfIntRect rect;
    sfVector2f scale;
    sfClock *clock;
    sfClock *j_clock;
    int offset;
    int is_jump;
} image_t;

typedef struct text {
    sfText *txt;
    sfFont *font;
    sfVector2f pos;
} text_t;

typedef struct menu {
    image_t *button[2];
    image_t *sound[2];
    image_t *screen[2];
    image_t *exit;
    text_t *title[4];
    text_t *lvl_select;
    text_t *skin_select;
    text_t *resume;
} menu_t;

typedef struct level {
    image_t *button[6];
    image_t *home;
    text_t *txt[6];
    text_t *score[4];
} level_t;

typedef struct enemy {
    image_t *image;
    struct enemy *next;
} enemy_t;

typedef struct game {
    sfRenderWindow *wind;
    sfEvent event;
    image_t *sky;
    image_t *rock[2];
    image_t *cloud[2];
    image_t *back[2];
    image_t *front[2];
    image_t *tree[2];
    image_t *ground[2];
    image_t *finish;
    image_t *player;
    image_t *skin[4];
    menu_t *s_menu;
    level_t *s_level;
    int play;
    int menu;
    int shop;
    int level_menu;
    int activ_skin;
    enemy_t *enemys;
    int level;
    int bonus;
    char *map;
    char *filepath;
    int error;
    sfClock *clock;
    text_t *score;
    int win;
    float time;
    int sound;
    int screen;
    int points;
    sfMusic *jump;
    sfMusic *dead;
    sfMusic *win_sfx;
    sfMusic *music;
} game_t;

// init
void set_string_text(game_t *);
void final_init_text(game_t *);
void init_text8(game_t *);
void init_text7(game_t *);
void init_text6(game_t *);

// init_text
void init_text5(game_t *);
void init_text4(game_t *);
void init_text3(game_t *);
void init_text2(game_t *);
void init_text(game_t *);

// init_menu
void init_skin(image_t *);
void set_position_menu2(game_t *);
void set_position_menu(game_t *);
void init_level_menu(game_t *);
void init_menu(game_t *);

// init_level
void init_level(game_t *);
void init(game_t *);

//destroy
void destroy(game_t *);
void destroy2(game_t *);
void usage(void);

// main
void change_skin(game_t *, char *);
image_t *create_img(const char *, float, int, int);
int game_management(game_t *);
int check_flag(int, char **, game_t *);
int main(int, char **);

// analyse
void analyse_events_shop_r(game_t *);
void analyse_events_shop(game_t *);
void analyse_events2(game_t *);
void analyse_events(game_t *);

// analyse_menu
void analyse_events_menu_m2(game_t *);
void analyse_events_menu_m(game_t *);
void analyse_events_menu2(game_t *);
void analyse_events_menu(game_t *);

// analyse_menu_level
void analyse_events_menu_r4(game_t *);
void analyse_events_menu_r3(game_t *);
void analyse_events_menu_r2(game_t *);
void analyse_events_menu_r(game_t *);
void analyse_events_game(game_t *);

// analyse_level
void analyse_events_level_menu_r4(game_t *);
void analyse_events_level_menu_r3(game_t *);
void analyse_events_level_menu_r2(game_t *);
void analyse_events_level_menu_r(game_t *);

//analyse_level_menu
void analyse_events_level_menu2(game_t *);
void analyse_events_level_menu(game_t *);
void analyse_events_level_menu_m3(game_t *);
void analyse_events_level_menu_m2(game_t *);
void analyse_events_level_menu_m(game_t *);


// parallax
void parallax(image_t *, image_t *);
void restart_skin(game_t *);
void fall(game_t *, image_t *);
void jump(game_t *, image_t *);
void parallax_management(game_t *);

// time gestion
void time_gestion_run(image_t *);
void time_gestion_jump(image_t *);
void time_gestion_idle(image_t *);
void time_gestion_enemy(image_t *, game_t *);

// update game
void set_position_bg(game_t *);
void draw_sprite_bg(game_t *);
void update_game2(game_t *);
void update_game(game_t *);
void update_shop(game_t *);

// update menu
void update_menu2(game_t *);
void update_menu(game_t *);
void draw_text_level_menu(game_t *);
void update_level_menu(game_t *);

// file
void init_music(game_t *);
char *read_file(game_t *, char const *);
void write_score(game_t *);
int load_file_in_mem(char const *, game_t *);

// map
enemy_t *create_enemy(char *, int, int, int);
void init_enemy2(game_t *, int, enemy_t *, enemy_t *);
void init_enemy(game_t *, char *);
void init_enemy_infini(game_t *);
void display_enemy(game_t *);

// game_start_end
void change_best(game_t *);
void end_game(game_t *, int);
void start_game(game_t *);

// lib
int my_put_nbr(int);
char *my_strcat(char *, char const *);
int my_getnbr(char const *);
int my_strcmp(char const *, char const *);
int my_strlen(char const *);
void my_putchar(char);
void my_putstr(char *);
char *to_c(int);

#endif
