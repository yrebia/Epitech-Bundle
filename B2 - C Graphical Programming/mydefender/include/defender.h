/*
** EPITECH PROJECT, 2022
** DEFENDER
** File description:
** Header file for MyDefender
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdio.h>

#ifndef DEFENDER_H_
    #define DEFENDER_H_

enum spritevalue {
    GRASS = 0,
    WALL = 1,
    CASTLE = 2,
    SPAWN = 3,
    PATH = 4,
    ENEMY = 5,
    SELECTION = 6,
    USED = 7
};

enum menuvalue {
    PLAY = 0,
    OPTIONS = 1,
    HTP = 2,
    EXIT = 3,
    WELCOME = 4,
};

enum gamevalue {
    MENU = 0,
    GAME = 1,
    PAUSE = 2,
};

enum towertype {
    TOWER1 = 1,
    TOWER2 = 2,
    TOWER3 = 3,
    TOWER4 = 4,
    TOWER5 = 5,
};

typedef struct texts {
    char *str;
    sfText *text;
    sfFont *font;
    sfVector2f pos;
} t_text;

typedef struct sprites {
    float fastest;
    int offset;
    int state;
    float seconds;
    sfClock *animation;
    sfClock *movement;
    sfIntRect rect;
    sfSprite *sprite;
    sfTexture *texture;
    sfTime time;
    sfVector2f pos;
    sfVector2f scale;
    sfVector2f velocity;
} t_sprite;

typedef struct statistics {
    float HP;
    float HP_max;
    float ATK;
    float ATKSPD;
    float SPD;
    float RANGE;
} t_stat;

typedef struct enemys {
    t_sprite *sprite;
    t_sprite *life_bar;
    t_sprite *bg_life;
    t_stat *stats;
    int dead;
    struct enemys *next;
} t_enemy;

typedef struct towers {
    int price;
    int type;
    t_sprite *sprite;
    t_stat *stats;
    t_enemy *target;
    struct towers *next;
} t_tower;

typedef struct bullet {
    t_sprite *sprite;
    t_stat *stats;
    t_enemy *target;
    t_tower *from;
    int touched;
    struct bullet *next;
} t_bullet;

typedef struct option {
    int sound;
    int screen;
    int fps;
    t_sprite *selection;
    t_sprite **img;
    t_text **texts;
} t_option;

typedef struct music {
    sfMusic *shot;
    sfMusic *menu;
    sfMusic *game;
} t_music;

typedef struct menu {
    int lvl;
    int menustate;
    int hover;
    int lvlhover;
    t_sprite *background;
    t_sprite **selection;
    t_text **texts;
    t_text **levels;
} t_menu;

typedef struct pause {
    t_sprite *background;
    t_sprite **buttons;
    t_text **btn_text;
} t_pause;

typedef struct game {
    int gamestate;
    int tilestate;
    int tmp_spawn;
    float nbr_spawn;
    int is_spawn;
    int tower_menu;
    int money;
    int points;
    int lives;
    int tower_prices[5];
    int wave_nbr;
    char *smap;
    char **av;
    sfEvent event;
    sfRenderWindow *window;
    sfVector2f spawn_pos;
    sfVector2f tower_pos;
    t_enemy *enemys;
    t_pause *pause;
    t_sprite *borders[2];
    t_sprite *backgrounds[2];
    t_sprite **txtbox;
    t_sprite **buttons;
    t_sprite *selection;
    t_sprite ***sprtmap;
    t_sprite ***towmenu;
    t_text **btn_text;
    t_text **wave_text;
    t_text **money_text;
    t_text *description[5];
    t_text **livess;
    t_text ***tower_pricess;
    t_tower *towers;
    t_bullet *bullets;
    t_menu *menu;
    t_music *music;
    t_option *option;
    sfClock *spawn_clock;
} t_game;

void free_game(t_game *game);

void generate_map(t_game *game);

int game_management(t_game *game);
void defender(t_game *game);
void main_menu(t_game *game);
void game_pause(t_game *game);
int load_file_in_mem(char const *filepath, t_game *game);

void start_wave(t_game *game);
int enemy_len(t_game *game);
void set_random(void);
void init(t_game *game);
void append_enemys(t_game *game);
void init_game(t_game *game);
void init_menu(t_game *game);
void init_pause(t_game *game);
void init_description(t_game *game);
void append_tower(t_game *game, int x, int y, int type);
void init_bullet(t_game *game, t_tower *tower);
void init_tower_menu(t_game *game);
void init_music_sfx(t_game *game);
void init_option(t_game *game);

void animate_enemy(t_enemy *enemys);
void display_enemys(t_game *game);
void move_enemy(t_enemy *enemy, t_game *game);

void display_towers(t_game *game);
void display_bullets(t_game *game);

void analyse_events(t_game *game);
void analyse_game(t_game *game);
void analyse_selection(t_game *game);
void analyse_pause(t_game *game);
void analyse_menu(t_game *game);
void analyse_play(t_game *game, sfVector2i mouse_pos);
void analyse_towers(t_game *game);
void analyse_option(t_game *game);

void game_theme(t_game *game);
void menu_theme(t_game *game);
void shot_sfx(t_game *game);
void destroy_music_sfx(t_game *game);

t_sprite *create_button(char *path, sfVector2f pos);
t_sprite *create_sprite(char *path, sfVector2f pos, sfIntRect rect,
sfVector2f scale);
t_sprite *create_textbox(char *path);
t_sprite *create_back(char *path, int x);
t_sprite *create_borders(char *path, int x);
t_sprite *create_tile(char *path, int x, int y, int state);
t_sprite *create_enemy(char *path, sfVector2f pos, int state, float vel);
t_sprite *create_bullet(char *path, sfVector2f pos, int velx, int vely);
t_sprite *create_tower(char *path, sfVector2f pos, int top, int left);

t_stat *set_stats_t(float atk, float atkspd, float range);
t_stat *set_stats_e(float hp, float atk);

t_text *create_text(char *str, sfVector2f pos, int size, sfColor color);

int game_management(t_game *game);

#endif

#define TABWALL     "\t      WALL\n\n\t This is a WALL !\n\n" \
"You can place Towers\n\t\t on it !"

#define TABCASTLE   "\t     CASTLE\n\n\tThis is the place\n\t" \
"   to defend !\n\n\tDon't let enemies\n\t   attack it !"

#define TABSPAWN    "\t     SPAWN\n\n  This is where enemies\n\t     " \
"appear !\n\n\tYou must defend\n\t against them !"

#define HOWTOPLAY   "  Escape to pause the\n    game while playing\n\n\n" \
"Click ingame to interact\n       with the tiles"

#define BENVENUTO   "\n\n   Welcome to MyDefender :)\n\n\n" \
"  This project was made by :\n    - Corentin LEVET\n    - Yanis REBIA\n" \
"\n\n                  Have fun !\n" \
"\n\n       EPITECH Project 2022"
