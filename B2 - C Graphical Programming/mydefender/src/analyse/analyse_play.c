/*
** EPITECH PROJECT, 2022
** ANALYSE_PLAY
** File description:
** Function analyzing play button
*/

#include "../../include/my.h"

void analyse_play4(t_game *game, sfVector2i mp, sfVector2f pos)
{
    int pass = 0; char *filepath = game->av[1];
    if (mp.x >= (pos.x) && mp.x <= (pos.x + 300) && mp.y >= (pos.y)
    && mp.y <= (pos.y + 40) && filepath != NULL) {
        game->event.type == sfEvtMouseButtonPressed ?
        game->menu->lvl = 8 : 0;
        game->event.type == sfEvtMouseButtonReleased ? game->gamestate = 1,
        sfMusic_stop(game->music->menu), sfMusic_play(game->music->game) : 0;
    }
    (game->menu->lvl == 0) ? load_file_in_mem("maps/map1", game), pass = 1 :
    (game->menu->lvl == 1) ? load_file_in_mem("maps/map2", game), pass = 1 :
    (game->menu->lvl == 2) ? load_file_in_mem("maps/map3", game), pass = 1 :
    (game->menu->lvl == 3) ? load_file_in_mem("maps/map4", game), pass = 1 :
    (game->menu->lvl == 4) ? load_file_in_mem("maps/map5", game), pass = 1 :
    (game->menu->lvl == 5) ? load_file_in_mem("maps/map1", game), pass = 1 :
    (game->menu->lvl == 6) ? load_file_in_mem("maps/map1", game), pass = 1 :
    (game->menu->lvl == 7) ? load_file_in_mem("maps/map1", game), pass = 1 :
    (game->menu->lvl == 8) ? load_file_in_mem(filepath, game), pass = 1 : 0;
    if (pass == 1) generate_map(game), game->menu->lvl = 42;
}

void analyse_play3(t_game *game, int pass, sfVector2i mouse_pos)
{
    for (int i = 6; i < 8; i++) {
        if (mouse_pos.x >= (game->menu->levels[i]->pos.x)
            && mouse_pos.x <= (game->menu->levels[i]->pos.x + 100)
            && mouse_pos.y >= (game->menu->levels[i]->pos.y)
            && mouse_pos.y <= (game->menu->levels[i]->pos.y + 40)) {
            pass = 1; game->menu->lvlhover = 1;
            sfSprite_setPosition(game->menu->selection[7]->sprite,
            (sfVector2f) {1325 + i % 2 * 255, 570});
            sfSprite_setScale(game->menu->selection[7]->sprite,
            (sfVector2f) {0.23, 0.5});
            game->event.type == sfEvtMouseButtonPressed ?
            game->menu->lvl = i : 0;
            game->event.type == sfEvtMouseButtonReleased ?
            game->gamestate = 1, sfMusic_stop(game->music->menu),
            sfMusic_play(game->music->game) : 0;
        }
    } if (pass == 0) game->menu->lvlhover = 0;
    analyse_play4(game, mouse_pos, game->menu->levels[8]->pos);
}

void analyse_play2(t_game *game, int pass, sfVector2i mouse_pos)
{
    for (int i = 4; i < 6; i++) {
        if (mouse_pos.x >= (game->menu->levels[i]->pos.x)
            && mouse_pos.x <= (game->menu->levels[i]->pos.x + 100)
            && mouse_pos.y >= (game->menu->levels[i]->pos.y)
            && mouse_pos.y <= (game->menu->levels[i]->pos.y + 40)) {
            pass = 1; game->menu->lvlhover = 1;
            sfSprite_setPosition(game->menu->selection[7]->sprite,
            (sfVector2f) {1325 + i % 2 * 255, 495});
            sfSprite_setScale(game->menu->selection[7]->sprite,
            (sfVector2f) {0.23, 0.5});
            game->event.type == sfEvtMouseButtonPressed ?
            game->menu->lvl = i : 0;
            game->event.type == sfEvtMouseButtonReleased ?
            game->gamestate = 1, sfMusic_stop(game->music->menu),
            sfMusic_play(game->music->game) : 0;
        }
    } analyse_play3(game, pass, mouse_pos);
}

void analyse_play1(t_game *game, int pass, sfVector2i mouse_pos)
{
    for (int i = 2; i < 4; i++) {
        if (mouse_pos.x >= (game->menu->levels[i]->pos.x)
            && mouse_pos.x <= (game->menu->levels[i]->pos.x + 100)
            && mouse_pos.y >= (game->menu->levels[i]->pos.y)
            && mouse_pos.y <= (game->menu->levels[i]->pos.y + 40)) {
            pass = 1; game->menu->lvlhover = 1;
            sfSprite_setPosition(game->menu->selection[7]->sprite,
            (sfVector2f) {1325 + i % 2 * 255, 420});
            sfSprite_setScale(game->menu->selection[7]->sprite,
            (sfVector2f) {0.23, 0.5});
            game->event.type == sfEvtMouseButtonPressed ?
            game->menu->lvl = i : 0;
            game->event.type == sfEvtMouseButtonReleased ?
            game->gamestate = 1, sfMusic_stop(game->music->menu),
            sfMusic_play(game->music->game) : 0;
        }
    } analyse_play2(game, pass, mouse_pos);
}

void analyse_play(t_game *game, sfVector2i mouse_pos)
{
    int pass = 0;
    for (int i = 0; i < 2; i++) {
        if (mouse_pos.x >= (game->menu->levels[i]->pos.x)
            && mouse_pos.x <= (game->menu->levels[i]->pos.x + 100)
            && mouse_pos.y >= (game->menu->levels[i]->pos.y)
            && mouse_pos.y <= (game->menu->levels[i]->pos.y + 40)) {
            pass = 1; game->menu->lvlhover = 1;
            sfSprite_setPosition(game->menu->selection[7]->sprite,
            (sfVector2f) {1325 + i * 255, 345});
            sfSprite_setScale(game->menu->selection[7]->sprite,
            (sfVector2f) {0.23, 0.5});
            game->event.type == sfEvtMouseButtonPressed ?
            game->menu->lvl = i : 0;
            game->event.type == sfEvtMouseButtonReleased ?
            game->gamestate = 1, sfMusic_stop(game->music->menu),
            sfMusic_play(game->music->game) : 0;
        }
    } analyse_play1(game, pass, mouse_pos);
}
