/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** Move Cursor
*/

#include "../../include/mystruct.h"

void move_cursor(rpg_t *rpg)
{
    if (rpg->event.type == sfEvtMouseMoved) {
        rpg->cursor.pos_cursor = (sfVector2f){rpg->event.mouseMove.x,
        rpg->event.mouseMove.y};
        sfSprite_setPosition(rpg->cursor.sprite_cursor,
        rpg->cursor.pos_cursor);
    }
    if (rpg->event.type == sfEvtMouseButtonPressed) {
        rpg->cursor.texture_cursor = sfTexture_createFromFile
        ("assets/cursor/cursor_select_tap.png", NULL);
        sfSprite_setTexture(rpg->cursor.sprite_cursor,
        rpg->cursor.texture_cursor, sfTrue);
    }
    if (rpg->event.type == sfEvtMouseButtonReleased) {
        rpg->cursor.texture_cursor = sfTexture_createFromFile
        ("assets/cursor/cursor_select.png", NULL);
        sfSprite_setTexture(rpg->cursor.sprite_cursor,
        rpg->cursor.texture_cursor, sfTrue);
    }
}
