/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** English Strings
*/

#include "../../../include/mystruct.h"

void text_english_main_menu(rpg_t *rpg)
{
    sfText_setString(rpg->text[1][0].text, "PLAY\0");
    sfText_setString(rpg->text[1][1].text, "OPTIONS\0");
    sfText_setString(rpg->text[1][2].text, "GUIDE\0");
    sfText_setString(rpg->text[1][3].text, "LEAVE\0");
    sfText_setString(rpg->text[1][15].text, "RETURN MENU\0");
}

void text_english_play_menu_and_pause(rpg_t *rpg)
{
    sfText_setString(rpg->text[1][4].text, "PART 1\0");
    sfText_setString(rpg->text[1][5].text, "PART 2\0");
    sfText_setString(rpg->text[1][6].text, "PART 3\0");
    sfText_setString(rpg->text[1][7].text, "RETURN MENU\0");
    sfText_setString(rpg->text[1][27].text, "RESUNE\0");
    sfText_setString(rpg->text[1][28].text, "SAVE\0");
    sfText_setString(rpg->text[1][29].text, "OPTIONS\0");
    sfText_setString(rpg->text[1][30].text, "MENU\0");
}

void text_english_option_menu(rpg_t *rpg)
{
    sfText_setString(rpg->text[1][8].text, "FULLSCREEN\0");
    sfText_setString(rpg->text[1][9].text, "FPS: 60\0");
    sfText_setString(rpg->text[1][10].text, "VOLUME: 50\0");
    sfText_setString(rpg->text[1][11].text, "MUSIC: ON\0");
    sfText_setString(rpg->text[1][12].text, "ENGLISH\0");
    sfText_setString(rpg->text[1][13].text, "KEYS\0");
    sfText_setString(rpg->text[1][14].text, "RETURN MENU\0");
}

void text_english_keys_menu(rpg_t *rpg)
{
    sfText_setString(rpg->text[1][16].text, "FORWARD\0");
    sfText_setString(rpg->text[1][17].text, "BACKWARD\0");
    sfText_setString(rpg->text[1][18].text, "LEFT\0");
    sfText_setString(rpg->text[1][19].text, "RIGHT\0");
    sfText_setString(rpg->text[1][20].text, "INVENTORY\0");
    sfText_setString(rpg->text[1][21].text, "Z\0");
    sfText_setString(rpg->text[1][22].text, "Q\0");
    sfText_setString(rpg->text[1][23].text, "S\0");
    sfText_setString(rpg->text[1][24].text, "D\0");
    sfText_setString(rpg->text[1][25].text, "E\0");
    sfText_setString(rpg->text[1][26].text, "RETURN MENU\0");
}

void text_english(rpg_t *rpg)
{
    text_english_main_menu(rpg);
    text_english_play_menu_and_pause(rpg);
    text_english_option_menu(rpg);
    text_english_keys_menu(rpg);

}
