/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** English Position
*/

#include "../../../include/mystruct.h"

void text_english_position_main_menu(rpg_t *rpg)
{
    sfText_setPosition(rpg->text[1][0].text, (sfVector2f) {885, 240});
    sfText_setPosition(rpg->text[1][1].text, (sfVector2f) {830, 390});
    sfText_setPosition(rpg->text[1][2].text, (sfVector2f) {875, 540});
    sfText_setPosition(rpg->text[1][3].text, (sfVector2f) {860, 690});
    sfText_setPosition(rpg->text[1][15].text, (sfVector2f) {730, 895});
}

void text_english_position_play_and_pause(rpg_t *rpg)
{
    sfText_setPosition(rpg->text[1][4].text, (sfVector2f) {860, 240});
    sfText_setPosition(rpg->text[1][5].text, (sfVector2f) {860, 390});
    sfText_setPosition(rpg->text[1][6].text, (sfVector2f) {860, 540});
    sfText_setPosition(rpg->text[1][7].text, (sfVector2f) {730, 690});
    sfText_setPosition(rpg->text[1][27].text, (sfVector2f) {855, 290});
    sfText_setPosition(rpg->text[1][28].text, (sfVector2f) {890, 410});
    sfText_setPosition(rpg->text[1][29].text, (sfVector2f) {850, 535});
    sfText_setPosition(rpg->text[1][30].text, (sfVector2f) {880, 660});
}

void text_english_position_option_menu(rpg_t *rpg)
{
    sfText_setPosition(rpg->text[1][8].text, (sfVector2f) {570, 250});
    sfText_setPosition(rpg->text[1][9].text, (sfVector2f) {1070, 250});
    sfText_setPosition(rpg->text[1][10].text, (sfVector2f) {580, 400});
    sfText_setPosition(rpg->text[1][11].text, (sfVector2f) {1040, 400});
    sfText_setPosition(rpg->text[1][12].text, (sfVector2f) {635, 550});
    sfText_setPosition(rpg->text[1][13].text, (sfVector2f) {1110, 550});
    sfText_setPosition(rpg->text[1][14].text, (sfVector2f) {730, 690});
}

void text_english_position_keys_menu(rpg_t *rpg)
{
    sfText_setPosition(rpg->text[1][16].text, (sfVector2f) {580, 140});
    sfText_setPosition(rpg->text[1][17].text, (sfVector2f) {560, 270});
    sfText_setPosition(rpg->text[1][18].text, (sfVector2f) {635, 400});
    sfText_setPosition(rpg->text[1][19].text, (sfVector2f) {625, 530});
    sfText_setPosition(rpg->text[1][20].text, (sfVector2f) {550, 660});
    sfText_setPosition(rpg->text[1][21].text, (sfVector2f) {1350, 140});
    sfText_setPosition(rpg->text[1][22].text, (sfVector2f) {1355, 270});
    sfText_setPosition(rpg->text[1][23].text, (sfVector2f) {1355, 400});
    sfText_setPosition(rpg->text[1][24].text, (sfVector2f) {1355, 530});
    sfText_setPosition(rpg->text[1][25].text, (sfVector2f) {1355, 660});
    sfText_setPosition(rpg->text[1][26].text, (sfVector2f) {750, 910});
}

void text_english_position(rpg_t *rpg)
{
    text_english_position_main_menu(rpg);
    text_english_position_play_and_pause(rpg);
    text_english_position_option_menu(rpg);
    text_english_position_keys_menu(rpg);
}
