/*
** EPITECH PROJECT, 2022
** CREATION_ONE
** File description:
** Functions for creation
*/

#include "../../include/my.h"

t_sprite *create_back(char *path, int x)
{
    t_sprite *sprt = malloc(sizeof(t_sprite));

    sprt->pos = (sfVector2f) {x * 1500, 0};
    sprt->texture = sfTexture_createFromFile(path, NULL);
    sprt->sprite = sfSprite_create();
    sprt->scale = (sfVector2f) {1, 1};
    sfSprite_setPosition(sprt->sprite, sprt->pos);
    sfSprite_setTexture(sprt->sprite, sprt->texture, sfFalse);
    sfSprite_setScale(sprt->sprite, sprt->scale);
    return (sprt);
}

t_sprite *create_button(char *path, sfVector2f pos)
{
    t_sprite *sprt = malloc(sizeof(t_sprite));

    sprt->pos = pos;
    sprt->texture = sfTexture_createFromFile(path, NULL);
    sprt->sprite = sfSprite_create();
    sprt->scale = (sfVector2f) {0.7, 0.7};
    sfSprite_setPosition(sprt->sprite, sprt->pos);
    sfSprite_setTexture(sprt->sprite, sprt->texture, sfFalse);
    sfSprite_setScale(sprt->sprite, sprt->scale);
    return (sprt);
}

t_text *create_text(char *str, sfVector2f pos, int size, sfColor color)
{
    t_text *txt = malloc(sizeof(t_text));

    txt->str = str;
    txt->text = sfText_create();
    txt->font = sfFont_createFromFile("resources/space.ttf");
    txt->pos = pos;
    sfText_setColor(txt->text, color);
    sfText_setFont(txt->text, txt->font);
    sfText_setString(txt->text, txt->str);
    sfText_setCharacterSize(txt->text, size);
    sfText_setPosition(txt->text, txt->pos);

    return (txt);
}

t_sprite *create_textbox(char *path)
{
    t_sprite *sprt = malloc(sizeof(t_sprite));

    sprt->pos = (sfVector2f) {1506, 0};
    sprt->texture = sfTexture_createFromFile(path, NULL);
    sprt->sprite = sfSprite_create();
    sprt->scale = (sfVector2f) {0.69, 0.5};
    sfSprite_setScale(sprt->sprite, sprt->scale);
    sfSprite_setPosition(sprt->sprite, sprt->pos);
    sfSprite_setTexture(sprt->sprite, sprt->texture, sfFalse);
    return (sprt);
}

t_sprite *create_sprite(char *path, sfVector2f pos, sfIntRect rect,
sfVector2f scale)
{
    t_sprite *sprt = malloc(sizeof(t_sprite));
    sprt->texture = sfTexture_createFromFile(path, NULL);
    sprt->sprite = sfSprite_create();
    sprt->pos = pos;
    sprt->rect = rect;
    sprt->scale = scale;
    sfSprite_setScale(sprt->sprite, sprt->scale);
    sfSprite_setPosition(sprt->sprite, sprt->pos);
    sfSprite_setTexture(sprt->sprite, sprt->texture, sfFalse);
    sfSprite_setTextureRect(sprt->sprite, sprt->rect);
    return (sprt);
}
