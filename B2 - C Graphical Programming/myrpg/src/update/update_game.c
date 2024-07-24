/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** Update Main Menu
*/

#include "../../include/mystruct.h"

void update_pause_menu(rpg_t *rpg)
{
    if (rpg->menu_id == 6 && rpg->pause_id == 1) {
        for (int i = 0; i < 5; i++)
            sfRenderWindow_drawSprite(rpg->window, rpg->menu[6][i].sprt, NULL);
        for (int i = 27; i < 31; i++)
            sfRenderWindow_drawText
            (rpg->window, rpg->text[rpg->options.language][i].text, NULL);
        sfView_setCenter(rpg->view, (sfVector2f) {960, 540});
        sfRenderWindow_setView(rpg->window, rpg->view);
    }
}

void update_inventory_menu(rpg_t *rpg)
{
    if (rpg->menu_id == 6 && rpg->inventory_id == 1) {
        sfRenderWindow_drawSprite(rpg->window, rpg->menu[7][0].sprt, NULL);
        sfRenderWindow_drawSprite(rpg->window, rpg->skin_player->sprite, NULL);
        sfView_setCenter(rpg->view, (sfVector2f) {960, 540});
        sfRenderWindow_setView(rpg->window, rpg->view);
    }
}

void update_life(rpg_t *rpg)
{
    if (rpg->player->hp <= 0) {
        rpg->loose = 1;
        sfRenderWindow_clear(rpg->window, sfBlack);
        sfRenderWindow_drawSprite(rpg->window, rpg->menu[8][0].sprt, NULL);
        sfView_setCenter(rpg->view, (sfVector2f) {960, 540});
        sfRenderWindow_setView(rpg->window, rpg->view);
    }
}

void update_win(rpg_t *rpg)
{
    if (rpg->loose == -1) {
        sfRenderWindow_clear(rpg->window, sfBlack);
        sfRenderWindow_drawSprite(rpg->window, rpg->menu[9][0].sprt, NULL);
        sfView_setCenter(rpg->view, (sfVector2f) {960, 540});
        sfRenderWindow_setView(rpg->window, rpg->view);
    }
}

void check_win(rpg_t *rpg)
{
    if (rpg->bg->map == 0 && rpg->inventory[3].placement == 1 &&
        (rpg->player->pos.x == 2775 || rpg->player->pos.x == 2850) &&
        rpg->player->pos.y == 600) {
        rpg->inventory[3].placement = 0;
        rpg->loose = -1;
    }
}
