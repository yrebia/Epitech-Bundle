/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_

typedef struct image {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f velocity;
    sfIntRect rect;
    sfVector2f scale;
    sfClock *clock;
    sfTime time;
    float seconds;
    int offset;
    int sens;
} image_t;

typedef struct text {
    sfText *txt;
    sfFont *font;
    sfVector2f pos;
} text_t;

typedef struct menu {
    image_t *bg;
    image_t *play;
    image_t *sound_on;
    image_t *sound_off;
    image_t *exit;
} menu_t;

typedef struct game {
    sfRenderWindow *wind;
    sfEvent event;
    image_t *bg;
    image_t *duck;
    image_t *duck2;
    image_t *duck3;
    image_t *viseur;
    image_t *goal;
    image_t *goal2;
    image_t *shot;
    image_t *shot2;
    text_t *txt_bst;
    text_t *score;
    text_t *text_level;
    sfMusic *gunshot;
    sfMusic *game_over;
    int points;
    int bullet;
    int best;
    int playing;
    int menu;
    int level;
    int sound;
} game_t;

void set_images(game_t *);
void set_text(game_t *);
void set_duck2(game_t *);
void set_duck(game_t *);
void set_struct3(game_t *);
void set_struct2(game_t *);
void set_struct(game_t *);
void set_menu4(menu_t *);
void set_menu3(menu_t *);
void set_menu2(menu_t *);
void set_menu(menu_t *);
void manage_mouse_click(game_t *);
void manage_mouse_click2(game_t *);
void analyse_events(game_t *);
void update_game(game_t *);
void update_text(game_t *);
void time_gestion(game_t *, image_t *);
void destroy(game_t *);
int my_strcmp(char const *, char const *);
char *read_file(char const *);
int my_getnbr(char const *);
int my_strlen(char const *);
void write_score(game_t *);
char *cat(char *, char const *);
char *to_c(int);
void playing(game_t *);
void menuing(game_t *, menu_t *);
void menuing_draw_sprite(game_t *, menu_t *);
void restart_pos(game_t *, image_t *);
void level_up(game_t *);
void manage_mouse_menu(game_t *);
void launch_game(game_t *);
void game_over(game_t *);

#endif
