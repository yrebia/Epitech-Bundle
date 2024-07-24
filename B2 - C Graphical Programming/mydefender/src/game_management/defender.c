/*
** EPITECH PROJECT, 2022
** DEFENDER
** File description:
** Function managing defender
*/

#include "../../include/my.h"

void defender3(t_game *game)
{
    game->money_text[1]->str = my_int_to_str(game->money);
    sfText_setString(game->money_text[1]->text, game->money_text[1]->str);
    sfRenderWindow_drawText(game->window, game->money_text[0]->text, NULL);
    sfRenderWindow_drawText(game->window, game->money_text[1]->text, NULL);
    game->wave_text[1]->str = my_int_to_str(game->wave_nbr);
    sfText_setString(game->wave_text[1]->text, game->wave_text[1]->str);
    sfRenderWindow_drawText(game->window, game->wave_text[0]->text, NULL);
    sfRenderWindow_drawText(game->window, game->wave_text[1]->text, NULL);
    game->livess[1]->str = my_int_to_str(game->lives);
    sfText_setString(game->livess[1]->text, game->livess[1]->str);
    sfRenderWindow_drawText(game->window, game->livess[0]->text, NULL);
    sfRenderWindow_drawText(game->window, game->livess[1]->text, NULL);
}

void defender2(t_game *game)
{
    animate_enemy(game->enemys); display_enemys(game);
    display_bullets(game); display_towers(game);
    if (game->tilestate == WALL) {
        for (int i = 0; i < 5; i++) {
            sfRenderWindow_drawSprite
            (game->window, game->towmenu[0][i]->sprite, NULL);
            sfRenderWindow_drawSprite
            (game->window, game->towmenu[1][i]->sprite, NULL);
            sfRenderWindow_drawText(game->window,
            game->tower_pricess[i][0]->text, NULL);
            sfRenderWindow_drawText(game->window,
            game->tower_pricess[i][1]->text, NULL);
        }
    }
    defender3(game);
    if (game->is_spawn == 1)
        start_wave(game);
}

void defender1(t_game *game)
{
    sfRenderWindow_drawSprite(game->window,
    game->buttons[0]->sprite, NULL);
    sfRenderWindow_drawSprite(game->window,
    game->buttons[1]->sprite, NULL);
    sfRenderWindow_drawSprite(game->window,
    game->buttons[2]->sprite, NULL);
    sfRenderWindow_drawText(game->window,
    game->btn_text[0]->text, NULL);
    sfRenderWindow_drawText(game->window,
    game->btn_text[1]->text, NULL);
    sfRenderWindow_drawText(game->window,
    game->btn_text[2]->text, NULL);
    for (int i = 0; i < 5; i++) {
        if (game->tilestate == i) {
            sfRenderWindow_drawSprite(game->window,
            game->txtbox[i]->sprite, NULL);
            sfRenderWindow_drawText(game->window,
            game->description[i]->text, NULL);
        }
    } defender2(game);
}

void defender(t_game *game)
{
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++)
            sfRenderWindow_drawSprite(game->window,
            game->sprtmap[i][j]->sprite, NULL);
    }
    sfRenderWindow_drawSprite(game->window,
    game->backgrounds[0]->sprite, NULL);
    sfRenderWindow_drawSprite(game->window,
    game->backgrounds[1]->sprite, NULL);
    sfRenderWindow_drawSprite(game->window,
    game->borders[0]->sprite, NULL);
    sfRenderWindow_drawSprite(game->window,
    game->borders[1]->sprite, NULL);
    sfRenderWindow_drawSprite(game->window,
    game->selection->sprite, NULL);

    defender1(game);
}
