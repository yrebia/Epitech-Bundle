/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** Pollevent
*/

#include "../../include/mystruct.h"

void option_pollevent(rpg_t *rpg)
{
    change_size(rpg);
    change_fps(rpg);
    change_volume(rpg);
    active_music(rpg);
    change_language(rpg);
}

void pollevent(rpg_t *rpg)
{
    while (sfRenderWindow_pollEvent(rpg->window, &rpg->event)) {
        move_cursor(rpg);
        close_window(rpg);
        pollevent_key_intro(rpg);
        state_main_menu(rpg);
        state_main_menu0(rpg);
        state_main_menu1(rpg);
        state_main_menu2(rpg);
        state_main_menu3(rpg);
        navigation_menu(rpg);
        option_pollevent(rpg);
        choose_skin(rpg);
        check_position_inventory(rpg);
        pollevent_key(rpg);
        pause_menu(rpg);
        pollevent_attack(rpg);
        loose_game(rpg);
    }
}
