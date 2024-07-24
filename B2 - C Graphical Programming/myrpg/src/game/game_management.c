/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** Game Management
*/

#include "../../include/mystruct.h"

void set_door2(rpg_t *rpg, int offset, sfVector2f pos)
{
    if (offset == 1) {
        if (rpg->map[25][30] == 'P')
            rpg->map[27][30] = 'P', rpg->map[25][30] = 'X';
        else
            rpg->map[25][30] = 'X';
        if (rpg->map[25][31] == 'P')
            rpg->map[27][31] = 'P', rpg->map[25][31] = 'X';
        else
            rpg->map[25][31] = 'X';
        if (rpg->map[25][32] == 'P')
            rpg->map[27][32] = 'P', rpg->map[25][32] = 'X';
        else
            rpg->map[25][32] = 'X';
    }
}

void set_door(rpg_t *rpg, int offset, sfVector2f pos)
{
    if (offset == 3) {
        rpg->map[25][30] = (rpg->map[25][30] == 'P') ? 'P' : ' ';
        rpg->map[25][31] = (rpg->map[25][31] == 'P') ? 'P' : ' ';
        rpg->map[25][32] = (rpg->map[25][32] == 'P') ? 'P' : ' ';
    }
    if (offset == 2) {
        rpg->map[25][30] = (rpg->map[25][30] == 'P') ? 'P' : ' ';
        rpg->map[25][31] = (rpg->map[25][31] == 'P') ? 'P' : ' ';
        if (rpg->map[25][32] == 'P')
            rpg->map[27][32] = 'P', rpg->map[25][32] = 'X';
        else
            rpg->map[25][32] = 'X';
    }
    set_door2(rpg, offset, pos);
}

void colision_trap(rpg_t *rpg)
{
    sfVector2f pos = get_player_pos(rpg);
    if ((rpg->bg->map == 2 || rpg->bg->map == 3) && rpg->player->touched == 0
    && rpg->bg->seconds >= 1.5 && rpg->bg->seconds < 2.25) {
        if ((pos.x == 900 || pos.x == 975 || pos.x == 1050) && pos.y == 2550)
            rpg->player->hp -= 25, rpg->player->touched = 1;
        if ((pos.x == 2250 || pos.x == 2325 || pos.x == 2400) && pos.y == 1050)
            rpg->player->hp -= 25, rpg->player->touched = 1;
        set_door(rpg, 3, pos);
    } else if ((rpg->bg->map == 2 || rpg->bg->map == 3) &&
        rpg->bg->seconds < 1.5)
        set_door(rpg, 2, pos), rpg->player->touched = 0;
    if ((rpg->bg->map == 2 || rpg->bg->map == 3) && rpg->bg->seconds < 0.75)
        set_door(rpg, 1, pos), rpg->player->touched = 0;
}

void update_game(rpg_t *rpg)
{
    if (rpg->pause_id == 0 && rpg->inventory_id == 0) {
        rpg->player_pos = get_player_pos(rpg);
        manage_position(rpg), set_camera(rpg);
        enemies_target(rpg), colision_enemies(rpg);
        colision_trap(rpg), move_enemie_touched(rpg);
        anime_bg(rpg), display_enemies(rpg);
        attack_anim_down(rpg), update_life(rpg);
        sfRenderWindow_drawSprite(rpg->window, rpg->player->sprite, NULL);
        sfRenderWindow_drawSprite(rpg->window,
        rpg->life_bar_back->sprite, NULL);
        sfRenderWindow_drawSprite(rpg->window, rpg->life_bar->sprite, NULL);
        check_win(rpg);
    }
    update_pause_menu(rpg), update_inventory_menu(rpg);
    update_dialogue(rpg), draw_inventory(rpg);
    update_win(rpg);
}

void game_management(rpg_t *rpg)
{
    if (rpg->menu_id == 0) {
        display_gif(rpg);
    } else if (rpg->menu_id <= 5)
        update_menu(rpg);
    else
        update_game(rpg);
}
