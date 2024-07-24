/*
** EPITECH PROJECT, 2022
** MAIN
** File description:
** Main function for MyDefender
*/

#include "../include/my.h"

int error_handle(int ac)
{
    if (ac > 2) return (84);
    return (0);
}

int display_help(void)
{
    my_putstr("                                                " RED BOLD);
    my_putstr(UNDERLINE "MY DEFENDER\n" NORMAL "              The goal of t");
    my_putstr("he game is to defend your castle against the perfidious enem");
    my_putstr("ies !\n\n                                                   ");
    my_putstr(BLUE UNDERLINE BOLD "FLAGS\n" NORMAL "                       ");
    my_putstr("                 ./my_defender -h = usage\n                 ");
    my_putstr("                ./my_defender map = load a precise map\n\n  ");
    my_putstr("                                                 " GREEN BOLD);
    my_putstr(UNDERLINE "INPUT\n" NORMAL "                                 ");
    my_putstr("Escape to pause the game while playing\n                    ");
    my_putstr("            Click in-game to interact with the tiles\n\n    ");
    my_putstr("                                               " MAGENTA);
    my_putstr(UNDERLINE BOLD "BONUS\n" NORMAL "Thanks to the buttons on the");
    my_putstr(" menu, you can play the game, modify options, look at \"How ");
    my_putstr("to play\" or quit the game\n             Finaly, 3 levels ");
    my_putstr("are made. Try to finish them all to be a professional ");
    my_putstr("defender\n                                                ");
    my_putstr("Have fun :)\n"); return (0);
}

int load_file_in_mem(char const *filepath, t_game *game)
{
    game->smap = malloc(sizeof(char) * 251);
    int fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return (84);
    read(fd, game->smap, 250);
    close(fd);
    game->smap[239] = '\0';
    return (0);
}

int main(int ac, char **av)
{
    if (ac == 2 && !(my_strcmp(av[1], "-h"))) return (display_help());
    if (error_handle(ac) == 84) return (84);
    t_game *game = malloc(sizeof(t_game)); game->av = av;
    if (ac == 2 && load_file_in_mem(av[1], game) == 84) return (84);
    set_random(); init(game); init_music_sfx(game);
    init_menu(game); init_description(game), init_option(game);
    init_pause(game); init_game(game); init_tower_menu(game);
    while (sfRenderWindow_isOpen(game->window)) {
        while (sfRenderWindow_pollEvent(game->window, &game->event))
            analyse_events(game);
        if (game_management(game) == 84)
            return (84);
        sfRenderWindow_display(game->window);
    }
    return (0);
}
