/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** French Position
*/

#include "../../../include/mystruct.h"

void text_french_position_main_menu(rpg_t *rpg)
{
    sfText_setPosition(rpg->text[0][0].text, (sfVector2f) {860, 240});
    sfText_setPosition(rpg->text[0][1].text, (sfVector2f) {830, 390});
    sfText_setPosition(rpg->text[0][2].text, (sfVector2f) {875, 540});
    sfText_setPosition(rpg->text[0][3].text, (sfVector2f) {830, 690});
    sfText_setPosition(rpg->text[0][15].text, (sfVector2f) {670, 895});
}

void text_french_position_play_menu(rpg_t *rpg)
{
    sfText_setPosition(rpg->text[0][4].text, (sfVector2f) {820, 240});
    sfText_setPosition(rpg->text[0][5].text, (sfVector2f) {820, 390});
    sfText_setPosition(rpg->text[0][6].text, (sfVector2f) {820, 540});
    sfText_setPosition(rpg->text[0][7].text, (sfVector2f) {670, 690});
    sfText_setPosition(rpg->text[0][27].text, (sfVector2f) {850, 290});
    sfText_setPosition(rpg->text[0][28].text, (sfVector2f) {765, 410});
    sfText_setPosition(rpg->text[0][29].text, (sfVector2f) {850, 535});
    sfText_setPosition(rpg->text[0][30].text, (sfVector2f) {880, 660});
}

void text_french_position_option_menu(rpg_t *rpg)
{
    sfText_setPosition(rpg->text[0][8].text, (sfVector2f) {570, 250});
    sfText_setPosition(rpg->text[0][9].text, (sfVector2f) {1070, 250});
    sfText_setPosition(rpg->text[0][10].text, (sfVector2f) {580, 400});
    sfText_setPosition(rpg->text[0][11].text, (sfVector2f) {1000, 400});
    sfText_setPosition(rpg->text[0][12].text, (sfVector2f) {620, 550});
    sfText_setPosition(rpg->text[0][13].text, (sfVector2f) {1060, 550});
    sfText_setPosition(rpg->text[0][14].text, (sfVector2f) {670, 690});
}

void text_french_position_keys_menu(rpg_t *rpg)
{
    sfText_setPosition(rpg->text[0][16].text, (sfVector2f) {590, 140});
    sfText_setPosition(rpg->text[0][17].text, (sfVector2f) {590, 270});
    sfText_setPosition(rpg->text[0][18].text, (sfVector2f) {610, 400});
    sfText_setPosition(rpg->text[0][19].text, (sfVector2f) {620, 530});
    sfText_setPosition(rpg->text[0][20].text, (sfVector2f) {550, 660});
    sfText_setPosition(rpg->text[0][21].text, (sfVector2f) {1355, 140});
    sfText_setPosition(rpg->text[0][22].text, (sfVector2f) {1355, 270});
    sfText_setPosition(rpg->text[0][23].text, (sfVector2f) {1355, 400});
    sfText_setPosition(rpg->text[0][24].text, (sfVector2f) {1355, 530});
    sfText_setPosition(rpg->text[0][25].text, (sfVector2f) {1355, 660});
    sfText_setPosition(rpg->text[0][26].text, (sfVector2f) {700, 910});
}

void text_french_position(rpg_t *rpg)
{
    text_french_position_main_menu(rpg);
    text_french_position_play_menu(rpg);
    text_french_position_option_menu(rpg);
    text_french_position_keys_menu(rpg);
}
