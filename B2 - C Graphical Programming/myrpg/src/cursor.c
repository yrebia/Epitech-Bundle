/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** Cursor
*/

#include "../include/mystruct.h"

void create_cursor(rpg_t *rpg)
{
    sfRenderWindow_setMouseCursorVisible(rpg->window, sfFalse);
    rpg->cursor.texture_cursor = sfTexture_createFromFile
    ("assets/cursor/cursor_select.png", NULL);
    rpg->cursor.sprite_cursor = sfSprite_create();
    sfSprite_setTexture(rpg->cursor.sprite_cursor,
    rpg->cursor.texture_cursor, sfTrue);
}
