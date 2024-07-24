/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** Window
*/

#include "../include/mystruct.h"

sfRenderWindow *create_windows(sfRenderWindow *win)
{
    sfVideoMode mode = {1920, 1080, 32};
    win = sfRenderWindow_create(mode, "RPG",
    sfClose | sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(win, 60);
    return win;
}

void anime_bg(rpg_t *rpg)
{
    rpg->bg->time = sfClock_getElapsedTime(rpg->bg->animation);
    rpg->bg->seconds = rpg->bg->time.microseconds / 1000000.0;
    if (rpg->bg->seconds >= 0)
        sfRenderWindow_drawSprite(rpg->window, rpg->bg->sprite, NULL);
    if (rpg->bg->seconds >= 0.75)
        sfRenderWindow_drawSprite(rpg->window, rpg->bg2->sprite, NULL);
    if (rpg->bg->seconds >= 1.5)
        sfRenderWindow_drawSprite(rpg->window, rpg->bg3->sprite, NULL);
    if (rpg->bg->seconds >= 2.25)
        sfClock_restart(rpg->bg->animation);
}

void condition_window(rpg_t *rpg)
{
    if (rpg->loading == 0)
        sfClock_restart(rpg->clock);
    sfRenderWindow_drawSprite(rpg->window,
    rpg->cursor.sprite_cursor, NULL);
    sfRenderWindow_display(rpg->window);
    sfRenderWindow_clear(rpg->window, sfColor_fromRGB(4, 46, 72));
}

void window_loop(rpg_t *rpg)
{
    while (sfRenderWindow_isOpen(rpg->window)) {
        pollevent(rpg), game_management(rpg);
        if (rpg->loading == 1) {
            rpg->time = sfClock_getElapsedTime(rpg->clock);
            rpg->seconds = rpg->time.microseconds / 1000000.0;
            if (rpg->seconds >= 0.1) {
                sfRenderWindow_drawSprite(rpg->window,
                rpg->waiting->sprite, NULL);
                sfView_setCenter(rpg->view, (sfVector2f) {960, 540});
                sfRenderWindow_setView(rpg->window, rpg->view);
            }
            if (rpg->seconds >= 5)
                rpg->loading = 0;
        }
        condition_window(rpg);
    }
}

void window(void)
{
    rpg_t rpg;
    rpg.window = create_windows(rpg.window);
    init_all(&rpg), init_gif(&rpg);
    init_gif2(&rpg), init_gif3(&rpg);
    init_title(&rpg);
    init_inventory(&rpg);
    init_dialogue(&rpg);
    char *map = load_file("assets/map/map_spawn.txt");
    rpg.map = make_map_from_str(map);
    rpg.player->pos = get_player_pos(&rpg);
    create_menu(&rpg), create_loading(&rpg);
    create_cursor(&rpg), set_press(&rpg);
    create_parallax(&rpg), create_clock_parallax(&rpg);
    create_loose_menu(&rpg);
    init_enemies(&rpg);
    window_loop(&rpg);
}
