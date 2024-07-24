/*
** EPITECH PROJECT, 2022
** game start end
** File description:
** game start end
*/

#include "../include/my.h"

void change_best(game_t *game)
{
    if (game->level == 1)
        if (game->points > my_getnbr(read_file(game, "asset/level1/best.txt")))
            write_score(game), sfText_setString(game->s_level->score[0]->txt,
            my_strcat(my_strcat("Best score : ", read_file(game,
            "asset/level1/best.txt")), "%"));
    if (game->level == 2)
        if (game->points > my_getnbr(read_file(game, "asset/level2/best.txt")))
            write_score(game), sfText_setString(game->s_level->score[1]->txt,
            my_strcat(my_strcat("Best score : ", read_file(game,
            "asset/level2/best.txt")), "%"));
    if (game->level == 3)
        if (game->points > my_getnbr(read_file(game, "asset/level3/best.txt")))
            write_score(game), sfText_setString(game->s_level->score[2]->txt,
            my_strcat(my_strcat("Best score : ", read_file(game,
            "asset/level3/best.txt")), "%"));
    if (game->level == 4)
        if (game->points > my_getnbr(read_file(game, "asset/level4/best.txt")))
            write_score(game), sfText_setString(game->s_level->score[3]->txt,
            my_strcat(my_strcat("Best score : ", read_file(game,
            "asset/level4/best.txt")), "%"));
}

void end_game(game_t *game, int win)
{
    change_best(game);
    if (win == 1)
        game->win = 1;
    else
        game->win = -1;
    game->play = 0, game->menu = 1;
}

void start_game(game_t *game)
{
    sfClock_restart(game->clock);
    if (game->level == -1)
        init_enemy_infini(game);
    if (game->level == 1)
        init_enemy(game, "asset/level1/map.txt");
    if (game->level == 2)
        init_enemy(game, "asset/level2/map.txt");
    if (game->level == 3)
        init_enemy(game, "asset/level3/map.txt");
    if (game->level == 4)
        init_enemy(game, "asset/level4/map.txt");
    if (game->level == 5)
        init_enemy(game, game->filepath);
    game->time = 0, game->level_menu = 0, game->play = 1, game->win = 0;
}
