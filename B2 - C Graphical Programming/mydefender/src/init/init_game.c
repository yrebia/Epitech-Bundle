/*
** EPITECH PROJECT, 2022
** INIT_GAME
** File description:
** Functions initializing game
*/

#include "../../include/my.h"

void init_game2(t_game *game)
{
    t_text **wave_text = malloc(sizeof(t_text *) * 2);
    wave_text[0] = create_text("WAVE:", (sfVector2f) {31, 740}, 40, sfWhite);
    wave_text[1] = create_text(my_int_to_str(game->wave_nbr),
    (sfVector2f) {181, 800}, 40, sfRed);
    game->wave_text = wave_text;
    t_text **lives = malloc(sizeof(t_text *) * 2);
    lives[0] = create_text("LIVES:", (sfVector2f) {31, 340}, 40, sfWhite);
    lives[1] = create_text(my_int_to_str(game->wave_nbr),
    (sfVector2f) {181, 400}, 40, sfGreen);
    game->livess = lives;
}

void init_game1(t_game *game)
{
    game->backgrounds[0] = create_back("resources/Backleft.png", 0);
    game->backgrounds[1] = create_back("resources/Backright.png", 1);
    game->selection = create_tile("resources/TileSelect.png",
    -420, -690, SELECTION); game->tilestate = 42;
    game->towers = 0; game->enemys = 0; game->lives = 3;
    game->bullets = NULL; game->wave_nbr = 0;
    game->tower_prices[0] = 100, game->tower_prices[1] = 150;
    game->tower_prices[2] = 200, game->tower_prices[3] = 250;
    game->tower_prices[4] = 300;
    t_text **money_text = malloc(sizeof(t_text *) * 2);
    money_text[0] = create_text("MONEY:", (sfVector2f) {31, 540}, 40, sfWhite);
    money_text[1] = create_text(my_int_to_str(game->money),
    (sfVector2f) {181, 600}, 40, sfYellow);
    game->money_text = money_text;
    init_game2(game);
}

void init_game(t_game *game)
{
    game->spawn_clock = sfClock_create();
    game->tmp_spawn = 0; game->nbr_spawn = 1;
    game->is_spawn = 0; game->money = 250;
    game->borders[0] = create_borders("resources/Pipe.png", 0);
    game->borders[1] = create_borders("resources/Pipe.png", 1);
    t_sprite **buttons = malloc(sizeof(t_sprite *) * 3);
    buttons[0] = create_button("resources/Button.png", (sfVector2f) {31, 40});
    buttons[1] = create_button("resources/Button.png", (sfVector2f) {31, 190});
    buttons[2] = create_button("resources/Button.png", (sfVector2f) {31, 900});
    game->buttons = buttons;
    t_text **btn_text = malloc(sizeof(t_text *) * 3);
    btn_text[0] = create_text("MENU", (sfVector2f) {70, 55}, 50, sfWhite);
    btn_text[1] = create_text("PAUSE", (sfVector2f) {70, 205}, 50, sfWhite);
    btn_text[2] = create_text("START", (sfVector2f) {70, 915}, 50, sfWhite);
    game->btn_text = btn_text; init_game1(game);
}
