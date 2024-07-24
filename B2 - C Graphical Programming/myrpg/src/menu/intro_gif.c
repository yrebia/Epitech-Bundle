/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** Intro GIF
*/

#include "../../include/mystruct.h"

void display_gif(rpg_t *rpg)
{
    if (sfClock_getElapsedTime(rpg->clock_gif).microseconds >= 40000) {
        if (rpg->id_bg == 46)
            rpg->id_bg = 0;
        else
            rpg->id_bg++;
        sfClock_restart(rpg->clock_gif);
    }
    sfRenderWindow_drawSprite(rpg->window, rpg->gif[rpg->id_bg]->sprite, NULL);
    sfRenderWindow_drawText(rpg->window, rpg->text_start[1].text, NULL);
    sfRenderWindow_drawSprite(rpg->window, rpg->title->sprite, NULL);
}

sprite_t *init_background(char *str)
{
    sprite_t *menu = malloc(sizeof(sprite_t));

    menu->texture = sfTexture_createFromFile(str, NULL);
    menu->sprite = sfSprite_create();
    menu->scale = (sfVector2f){1.2, 1.2};
    menu->pos = (sfVector2f){670, 200};
    sfSprite_setTexture(menu->sprite, menu->texture, sfTrue);
    sfSprite_setScale(menu->sprite, menu->scale);
    sfSprite_setPosition(menu->sprite, menu->pos);
    return (menu);
}

void init_gif(rpg_t *rpg)
{
    rpg->clock = sfClock_create(), rpg->id_bg = 0;
    rpg->clock_gif = sfClock_create();
    rpg->gif = malloc(sizeof(menu_t *) * 50);
    rpg->gif[0] = init_background("assets/frames_intro/frame_00.png");
    rpg->gif[1] = init_background("assets/frames_intro/frame_01.png");
    rpg->gif[2] = init_background("assets/frames_intro/frame_02.png");
    rpg->gif[3] = init_background("assets/frames_intro/frame_03.png");
    rpg->gif[4] = init_background("assets/frames_intro/frame_04.png");
    rpg->gif[5] = init_background("assets/frames_intro/frame_05.png");
    rpg->gif[6] = init_background("assets/frames_intro/frame_06.png");
    rpg->gif[7] = init_background("assets/frames_intro/frame_07.png");
    rpg->gif[8] = init_background("assets/frames_intro/frame_08.png");
    rpg->gif[9] = init_background("assets/frames_intro/frame_09.png");
    rpg->gif[10] = init_background("assets/frames_intro/frame_10.png");
    rpg->gif[11] = init_background("assets/frames_intro/frame_11.png");
    rpg->gif[12] = init_background("assets/frames_intro/frame_12.png");
    rpg->gif[13] = init_background("assets/frames_intro/frame_13.png");
    rpg->gif[14] = init_background("assets/frames_intro/frame_14.png");
    rpg->gif[15] = init_background("assets/frames_intro/frame_15.png");
    rpg->gif[16] = init_background("assets/frames_intro/frame_16.png");
}

void init_gif2(rpg_t *rpg)
{
    rpg->gif[17] = init_background("assets/frames_intro/frame_17.png");
    rpg->gif[18] = init_background("assets/frames_intro/frame_18.png");
    rpg->gif[19] = init_background("assets/frames_intro/frame_19.png");
    rpg->gif[20] = init_background("assets/frames_intro/frame_20.png");
    rpg->gif[21] = init_background("assets/frames_intro/frame_21.png");
    rpg->gif[22] = init_background("assets/frames_intro/frame_22.png");
    rpg->gif[23] = init_background("assets/frames_intro/frame_23.png");
    rpg->gif[24] = init_background("assets/frames_intro/frame_24.png");
    rpg->gif[25] = init_background("assets/frames_intro/frame_25.png");
    rpg->gif[26] = init_background("assets/frames_intro/frame_26.png");
    rpg->gif[27] = init_background("assets/frames_intro/frame_27.png");
    rpg->gif[28] = init_background("assets/frames_intro/frame_28.png");
    rpg->gif[29] = init_background("assets/frames_intro/frame_29.png");
    rpg->gif[30] = init_background("assets/frames_intro/frame_30.png");
    rpg->gif[31] = init_background("assets/frames_intro/frame_31.png");
    rpg->gif[32] = init_background("assets/frames_intro/frame_32.png");
    rpg->gif[33] = init_background("assets/frames_intro/frame_33.png");
    rpg->gif[34] = init_background("assets/frames_intro/frame_34.png");
    rpg->gif[35] = init_background("assets/frames_intro/frame_35.png");
    rpg->gif[36] = init_background("assets/frames_intro/frame_36.png");
}

void init_gif3(rpg_t *rpg)
{
    rpg->gif[37] = init_background("assets/frames_intro/frame_37.png");
    rpg->gif[38] = init_background("assets/frames_intro/frame_38.png");
    rpg->gif[39] = init_background("assets/frames_intro/frame_39.png");
    rpg->gif[40] = init_background("assets/frames_intro/frame_40.png");
    rpg->gif[41] = init_background("assets/frames_intro/frame_41.png");
    rpg->gif[42] = init_background("assets/frames_intro/frame_42.png");
    rpg->gif[43] = init_background("assets/frames_intro/frame_43.png");
    rpg->gif[44] = init_background("assets/frames_intro/frame_44.png");
    rpg->gif[45] = init_background("assets/frames_intro/frame_45.png");
    rpg->gif[46] = init_background("assets/frames_intro/frame_46.png");
}
