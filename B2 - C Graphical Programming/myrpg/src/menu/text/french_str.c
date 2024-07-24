/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** French String
*/

#include "../../../include/mystruct.h"

void text_french_main_menu(rpg_t *rpg)
{
    sfText_setString(rpg->text[0][0].text, "JOUER\0");
    sfText_setString(rpg->text[0][1].text, "OPTIONS\0");
    sfText_setString(rpg->text[0][2].text, "GUIDE\0");
    sfText_setString(rpg->text[0][3].text, "QUITTER\0");
    sfText_setString(rpg->text[0][15].text, "RETOUR AU MENU\0");
}

void text_french_play_menu(rpg_t *rpg)
{
    sfText_setString(rpg->text[0][4].text, "PARTIE 1\0");
    sfText_setString(rpg->text[0][5].text, "PARTIE 2\0");
    sfText_setString(rpg->text[0][6].text, "PARTIE 3\0");
    sfText_setString(rpg->text[0][7].text, "RETOUR AU MENU\0");
    sfText_setString(rpg->text[0][27].text, "RETOUR\0");
    sfText_setString(rpg->text[0][28].text, "SAUVEGARDER\0");
    sfText_setString(rpg->text[0][29].text, "OPTIONS\0");
    sfText_setString(rpg->text[0][30].text, "MENU\0");
}

void text_french_options_menu(rpg_t *rpg)
{
    sfText_setString(rpg->text[0][8].text, "PLEIN ECRAN\0");
    sfText_setString(rpg->text[0][9].text, "FPS: 60\0");
    sfText_setString(rpg->text[0][10].text, "VOLUME: 50\0");
    sfText_setString(rpg->text[0][11].text, "MUSIQUE: ON\0");
    sfText_setString(rpg->text[0][12].text, "FRANCAIS\0");
    sfText_setString(rpg->text[0][13].text, "TOUCHES\0");
    sfText_setString(rpg->text[0][14].text, "RETOUR AU MENU\0");
}

void text_french_keys_menu(rpg_t *rpg)
{
    sfText_setString(rpg->text[0][16].text, "AVANCER\0");
    sfText_setString(rpg->text[0][17].text, "RECULER\0");
    sfText_setString(rpg->text[0][18].text, "GAUCHE\0");
    sfText_setString(rpg->text[0][19].text, "DROITE\0");
    sfText_setString(rpg->text[0][20].text, "INVENTAIRE\0");
    sfText_setString(rpg->text[0][21].text, "Z\0");
    sfText_setString(rpg->text[0][22].text, "Q\0");
    sfText_setString(rpg->text[0][23].text, "S\0");
    sfText_setString(rpg->text[0][24].text, "D\0");
    sfText_setString(rpg->text[0][25].text, "E\0");
    sfText_setString(rpg->text[0][26].text, "RETOUR AU MENU\0");
}

void text_french(rpg_t *rpg)
{
    text_french_main_menu(rpg);
    text_french_play_menu(rpg);
    text_french_options_menu(rpg);
    text_french_keys_menu(rpg);
}
