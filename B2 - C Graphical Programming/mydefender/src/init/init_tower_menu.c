/*
** EPITECH PROJECT, 2022
** INIT_TOWER_MENU
** File description:
** Function initializing tower menu
*/

#include "../../include/my.h"

void init_tower_menu1(t_game *game)
{
    t_text ***tower_prices = malloc(sizeof(t_text **) * 5);
    for (int i = 0; i < 5; i++) {
        tower_prices[i] = malloc(sizeof(t_text *) * 2);
        tower_prices[i][0] = create_text("PRICE :", (sfVector2f)
        {1600, 270 + i * 150}, 30, sfWhite);
        tower_prices[i][1] = create_text(my_int_to_str(game->tower_prices[i]),
        (sfVector2f) {1650, 320 + i * 150}, 30, sfYellow);
    }
    game->tower_pricess = tower_prices;
}

void init_tower_menu(t_game *game)
{
    int left = 0; game->towmenu = malloc(sizeof(t_sprite **) * 2);
    for (int i = 0; i < 2; i++)
        game->towmenu[i] = malloc(sizeof(t_sprite *) * 5);
    for (int j = 0; j < 5; j++) {
        (j == TOWER1 - 1) ? left = 2 : (j == TOWER2 - 1) ? left = 71 :
        (j == TOWER3 - 1) ? left = 137 : (j == TOWER4 - 1) ? left = 205 :
        (j == TOWER5 - 1) ? left = 274 : 0;
        game->towmenu[0][j] = create_sprite("resources/Box.png",
        (sfVector2f) {1780, 260 + j * 150}, (sfIntRect) {0, 0, 73, 72},
        (sfVector2f) {1.5, 1.5});
        game->towmenu[1][j] = create_sprite("resources/towers.png",
        (sfVector2f) {1800, 280 + j * 150}, (sfIntRect) {left, 1, 65, 63},
        (sfVector2f) {1, 1});
    }
    init_tower_menu1(game);
}
