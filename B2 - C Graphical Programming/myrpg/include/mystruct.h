/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** mystruct.h
*/

#ifndef MY_H_
    #define MY_H_

    #include <stdarg.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <stdbool.h>
    #include <fcntl.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <math.h>


typedef struct text {
    float seconds;
    sfText *text;
    sfFont *police;
    sfVector2f pos;
    sfClock *clock_press;
    sfTexture *texture_text;
    sfSprite *sprite_text;
    sfVector2f scale_text;
} text_t;

typedef struct menu {
    sfTexture *texture;
    sfSprite *sprt;
    sfIntRect rect;
    sfVector2f scale;
} menu_t;

typedef struct parallax {
    sfTexture *texture;
    sfSprite *sprt;
    sfTime time;
    sfClock *clock;
    float seconds;
} parallax_t;

typedef struct cursor {
    sfTexture *texture_cursor;
    sfSprite *sprite_cursor;
    sfVector2f pos_cursor;
} cursor_t;

typedef struct options {
    bool fullscreen;
    int fps;
    int volume;
    bool music;
    int language;
} options_t;

typedef struct sprites {
    int offset;
    float seconds;
    int is_attacking;
    int map;
    int hp;
    int touched;
    sfClock *animation;
    sfClock *attack;
    sfClock *movement;
    sfIntRect rect;
    sfSprite *sprite;
    sfTexture *texture;
    sfTime time;
    sfVector2f pos;
    sfVector2f scale;
    sfVector2f velocity;
} sprite_t;

typedef struct musics {
    sfMusic *music_menu;
    sfMusic *run_song;
    sfMusic *click_song;
} musics_t;

typedef struct stats {
    float range;
    float hp;
    float vel;
    float atk;
    float vel_x;
    float vel_y;
} stat_t;

typedef struct enemie {
    stat_t *stat;
    int map;
    int touched;
    sfClock *clock;
    sprite_t *sprite;
    sprite_t *target;
    struct enemie *next;
} enemie_t;

typedef struct inventory {
    sfTexture *texture;
    sfSprite *sprt;
    int placement;
} inventory_t;

typedef struct dialogue {
    sfTexture *texture;
    sfSprite *sprt;
    sfIntRect rect;
    sfVector2f scale;
    sfTime time;
    sfClock *clock;
    float seconds;
} dialogue_t;

typedef struct rpg {
    sfRenderWindow *window;
    sfEvent event;
    sfClock *clock;
    sfClock *clock_gif;
    sfTime time;
    float seconds;
    int id_bg;
    int menu_id;
    int pause_id;
    int inventory_id;
    int loading;
    int state;
    int skin;
    int loose;
    cursor_t cursor;
    sprite_t **gif;
    sprite_t *title;
    sprite_t *bg;
    sprite_t *bg2;
    sprite_t *bg3;
    sprite_t *player;
    sprite_t *life_bar_back;
    sprite_t *life_bar;
    sprite_t *skin_player;
    sprite_t *waiting;
    sfVector2f player_pos;
    sfView *view;
    char **map;
    menu_t menu[10][12];
    text_t text[2][31];
    inventory_t inventory[12];
    parallax_t parallax[4];
    dialogue_t dialogue[16];
    options_t options;
    musics_t musics;
    enemie_t *enemies;
    text_t text_start[2];
} rpg_t;

// Menu
void create_parallax(rpg_t *rpg);
void create_menu(rpg_t *rpg);
void button_main_menu(rpg_t *rpg);
void button_option_menu(rpg_t *rpg);
void button_play_menu(rpg_t *rpg);
void button_guide_menu(rpg_t *rpg);
void music_menu(rpg_t *rpg);
void move_sky_parallax(rpg_t *rpg);
void move_moon_parallax(rpg_t *rpg);

// Librairy
int my_strcmp(char const *s1, char const *s2);
char *my_strcat(char *dest, char const *src);
int my_int_len(int nb);
char *my_revstr(char *str);
char *int_to_char(int number);
int my_strlen(char const *str);

// PollEvent
void pollevent(rpg_t *rpg);
void move_cursor(rpg_t *rpg);
void close_window(rpg_t *rpg);
void navigation_menu(rpg_t *rpg);
void change_size(rpg_t *rpg);
void change_fps(rpg_t *rpg);
void change_to_windowed(rpg_t *rpg);
void change_to_fullscreen(rpg_t *rpg);
void active_music(rpg_t *rpg);
void change_language(rpg_t *rpg);
void change_volume(rpg_t *rpg);
void pollevent_key_intro(rpg_t *rpg);

// Update
void update_menu(rpg_t *rpg);
void update_main_menu(rpg_t *rpg);
void update_play_menu(rpg_t *rpg);
void update_options_menu(rpg_t *rpg);
void update_guide_menu(rpg_t *rpg);
void update_keys_menu(rpg_t *rpg);
void update_dialogue(rpg_t *rpg);
void update_win(rpg_t *rpg);

// Text
void text_anglais_position(rpg_t *rpg);
void text_francais_position(rpg_t *rpg);
void text_anglais(rpg_t *rpg);
void text_francais(rpg_t *rpg);

// Initialisation
void init_all(rpg_t *rpg);

//intro gif
sprite_t *init_background(char *str);
void init_gif(rpg_t *rpg);
void display_intro_gif(rpg_t *rpg);
void set_press(rpg_t *rpg);
void move_txt(rpg_t *rpg);
void test_sprite(rpg_t *rpg);

// Change map
void change_map_spawn(rpg_t *rpg);
void change_map_dungeon(rpg_t *rpg);
void change_map_forest(rpg_t *rpg);
void set_life_bar(rpg_t *rpg, sfVector2f pos);

// Teleportation
void all_tp(rpg_t *rpg);
void all_tp2(rpg_t *rpg);
void all_tp3(rpg_t *rpg);

// Pas Rangées
void window(void);
sfRenderWindow *create_windows(sfRenderWindow *win);
void create_cursor(rpg_t *rpg);
void create_text(rpg_t *rpg);
void button_keys_menu(rpg_t *rpg);
sfVector2f get_player_pos(rpg_t *rpg);
void pollevent_key(rpg_t *rpg);
void move_down(rpg_t *rpg);
void move_up(rpg_t *rpg);
void move_right(rpg_t *rpg);
void move_left(rpg_t *rpg);
void set_camera(rpg_t *rpg);
int height_array(char **map);
void manage_position(rpg_t *rpg);
char **make_map_from_str(char *buff);
char *load_file(char const *filepath);
void inside_map(rpg_t *rpg);
void my_putstr(char *str);
void pollevent_attack(rpg_t *rpg);
void update_pause_menu(rpg_t *rpg);
void button_pause_menu(rpg_t *rpg);
void attack_anim(rpg_t *rpg);
void display_gif(rpg_t *rpg);
void pause_menu(rpg_t *rpg);
void position_keys_menu(rpg_t *rpg);
void inventory_menu(rpg_t *rpg);
void inventory(rpg_t *rpg);
void setting_close_window(rpg_t *rpg);
void update_inventory_menu(rpg_t *rpg);
void update_inventory_menu(rpg_t *rpg);
void init_title(rpg_t *rpg);
void state_main_menu(rpg_t *rpg);
void change_map_spawn(rpg_t *rpg);
void change_map_dungeon(rpg_t *rpg);
void change_map_forest(rpg_t *rpg);
void all_tp(rpg_t *rpg);
void rect_and_scale_player(rpg_t *rpg);
void create_clock_parallax(rpg_t *rpg);
void button_guide_menu_rect(rpg_t *rpg);
void init_gif2(rpg_t *rpg);
void init_gif3(rpg_t *rpg);
void button_keys_menu2(rpg_t *rpg);
void button_keys_menu3(rpg_t *rpg);
void state_main_menu0(rpg_t *rpg);
void state_main_menu1(rpg_t *rpg);
void state_main_menu2(rpg_t *rpg);
void state_main_menu3(rpg_t *rpg);
void text_english_position_main_menu(rpg_t *rpg);
void text_english_position_play_and_pause(rpg_t *rpg);
void text_english_position_option_menu(rpg_t *rpg);
void text_english_position_keys_menu(rpg_t *rpg);
void text_english_position(rpg_t *rpg);
void text_english_main_menu(rpg_t *rpg);
void text_english_play_menu_and_pause(rpg_t *rpg);
void text_english_option_menu(rpg_t *rpg);
void text_english_keys_menu(rpg_t *rpg);
void text_english(rpg_t *rpg);
void text_french_position_main_menu(rpg_t *rpg);
void text_french_position_play_menu(rpg_t *rpg);
void text_french_position_option_menu(rpg_t *rpg);
void text_french_position_keys_menu(rpg_t *rpg);
void text_french_position(rpg_t *rpg);
void text_french_main_menu(rpg_t *rpg);
void text_french_play_menu(rpg_t *rpg);
void text_french_options_menu(rpg_t *rpg);
void text_french_keys_menu(rpg_t *rpg);
void text_french(rpg_t *rpg);
void attack_anim_down(rpg_t *rpg);
void run_song(rpg_t *rpg);
void click_song(rpg_t *rpg);
void check_position_inventory(rpg_t *rpg);
void create_skin(rpg_t *rpg);
void choose_skin(rpg_t *rpg);
void create_sprite(rpg_t *rpg);
void init_inventory(rpg_t *rpg);
void draw_inventory(rpg_t *rpg);
void create_loading(rpg_t *rpg);
void create_sprite2(rpg_t *rpg);
void create_dialogues(rpg_t *rpg);
void display_enemies(rpg_t *rpg);
void anime_bg(rpg_t *rpg);
void move_enemie_touched(rpg_t *rpg);
void colision_enemies(rpg_t *rpg);
void enemies_target(rpg_t *rpg);
void append_enemies(rpg_t *rpg, int x, int y, int map);
void set_life_bar(rpg_t *rpg, sfVector2f pos);
void init_enemies(rpg_t *rpg);
void game_management(rpg_t *rpg);
void loose_game(rpg_t *rpg);
void create_loose_menu(rpg_t *rpg);
void update_life(rpg_t *rpg);
void update_dialogue_fisherman(rpg_t *rpg);
void update_dialogue_gunsmith(rpg_t *rpg);
void update_dialogue_butcher(rpg_t *rpg);
void update_dialogue_jeweler(rpg_t *rpg);
void inventory_first_case(rpg_t *rpg);
void inventory_second_case(rpg_t *rpg);
void inventory_third_case(rpg_t *rpg);
void inventory_fourth_case(rpg_t *rpg);
void inventory_fifth_case(rpg_t *rpg);
void inventory_sixth_case(rpg_t *rpg);
void inventory_seventh_case(rpg_t *rpg);
void inventory_eighth_case(rpg_t *rpg);
void inventory_ninth_case(rpg_t *rpg);
void init_dialogue(rpg_t *rpg);
void check_win(rpg_t *rpg);
void all_tp2(rpg_t *rpg);
void all_tp3(rpg_t *rpg);
void change_map_coridor(rpg_t *rpg);
void change_map_return_coridor(rpg_t *rpg);
void change_map_room(rpg_t *rpg);
void change_map_return_room(rpg_t *rpg);
void change_map_return_forest(rpg_t *rpg);
void all_tp4(rpg_t *rpg);

#endif
