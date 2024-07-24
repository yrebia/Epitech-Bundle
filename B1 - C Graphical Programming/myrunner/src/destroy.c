/*
** EPITECH PROJECT, 2021
** destroy
** File description:
** destroy
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Export.h>
#include <SFML/System/Time.h>
#include <SFML/Window/Event.h>
#include <SFML/Audio.h>
#include <stddef.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/my.h"

void destroy2(game_t *game)
{
    for (int i = 0; i < 3; i++) {
        sfClock_destroy(game->skin[i]->clock);
        sfClock_destroy(game->skin[i]->j_clock);
        sfTexture_destroy(game->skin[i]->texture);
        sfSprite_destroy(game->skin[i]->sprite), free(game->skin[i]);
    }
    sfTexture_destroy(game->sky->texture);
    sfTexture_destroy(game->player->texture);
    sfSprite_destroy(game->sky->sprite);
    sfSprite_destroy(game->player->sprite);
    free(game->sky), free(game->player), free(game->s_menu);
    sfMusic_destroy(game->music), sfMusic_destroy(game->jump);
    sfMusic_destroy(game->dead), sfMusic_destroy(game->win_sfx);
    sfRenderWindow_destroy(game->wind);
}

void destroy(game_t *game)
{
    sfClock_destroy(game->player->clock);
    sfClock_destroy(game->player->j_clock);
    for (int i = 0; i < 2; i++) {
        sfTexture_destroy(game->rock[i]->texture);
        sfTexture_destroy(game->cloud[i]->texture);
        sfTexture_destroy(game->tree[i]->texture);
        free(game->s_menu->button[i]);
        sfTexture_destroy(game->ground[i]->texture);
        sfTexture_destroy(game->front[i]->texture);
        sfTexture_destroy(game->back[i]->texture);
        sfSprite_destroy(game->rock[i]->sprite), free(game->rock[i]);
        sfSprite_destroy(game->cloud[i]->sprite), free(game->cloud[i]);
        sfSprite_destroy(game->tree[i]->sprite), free(game->tree[i]);
        sfSprite_destroy(game->ground[i]->sprite), free(game->ground[i]);
        sfSprite_destroy(game->front[i]->sprite), free(game->front[i]);
        sfSprite_destroy(game->back[i]->sprite), free(game->back[i]);
    }
    destroy2(game);
}

void usage(void)
{
    my_putstr("                                                " ROUGE GRAS);
    my_putstr(SOULIGNE "MY RUNNER\n" NORMAL "         The goal of the game");
    my_putstr(" is to jump over enemys without touching them up to the fini");
    my_putstr("sh flag\n                                                  ");
    my_putstr(BLEU SOULIGNE GRAS "FLAGS\n" NORMAL "                        ");
    my_putstr("              ./my_runner -i = infini mode\n                ");
    my_putstr("                         ./my_runner -h = usage\n           ");
    my_putstr("                       ./my_runner map.txt = load your map\n");
    my_putstr("                                                  " VERT GRAS);
    my_putstr(SOULIGNE "KEYS\n" NORMAL "                                   ");
    my_putstr("          Space to jump\n                                   ");
    my_putstr("     Escape to open the menu\n                              ");
    my_putstr("                    " MAGENTA SOULIGNE GRAS "BONUS\n" NORMAL);
    my_putstr("Thanks to the buttons on the menu, you can mute the volume, ");
    my_putstr("put the game on full screen or quit the game\n              ");
    my_putstr("      You also have acces to a customization menu to change ");
    my_putstr("your skin\n                 Finaly, 4 levels or made. Try to");
    my_putstr(" finish them or to break your records\n                     ");
    my_putstr("                         Have fun :)\n");
}
