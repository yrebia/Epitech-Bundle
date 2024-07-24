/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** Create Menu
*/

#include "../../include/mystruct.h"

void create_skin(rpg_t *rpg)
{
    rpg->skin_player = malloc(sizeof(sprite_t));
    rpg->skin_player->texture =
    sfTexture_createFromFile("assets/skin.png", NULL);
    rpg->skin_player->sprite = sfSprite_create();
    sfSprite_setTexture
    (rpg->skin_player->sprite, rpg->skin_player->texture, sfTrue);
    rpg->skin_player->pos.x = 560, rpg->skin_player->pos.y = 400;
    rpg->skin_player->rect.left = 5;
    rpg->skin_player->rect.top = 5;
    rpg->skin_player->rect.height = 40;
    rpg->skin_player->rect.width = 25;
    sfSprite_setTextureRect(rpg->skin_player->sprite, rpg->skin_player->rect);
    sfSprite_setPosition(rpg->skin_player->sprite, rpg->skin_player->pos);
    rpg->skin_player->scale.x = 5, rpg->skin_player->scale.y = 5;
    sfSprite_setScale
    (rpg->skin_player->sprite, rpg->skin_player->scale);
}

void create_menu(rpg_t *rpg)
{
    button_main_menu(rpg);
    button_play_menu(rpg);
    button_option_menu(rpg);
    button_guide_menu(rpg);
    button_guide_menu_rect(rpg);
    button_keys_menu(rpg);
    button_keys_menu2(rpg);
    button_keys_menu3(rpg);
    button_pause_menu(rpg);
    create_text(rpg);
    music_menu(rpg);
    run_song(rpg);
    inventory_menu(rpg);
    create_skin(rpg);
    create_sprite(rpg), create_sprite2(rpg);
    create_dialogues(rpg);
}
