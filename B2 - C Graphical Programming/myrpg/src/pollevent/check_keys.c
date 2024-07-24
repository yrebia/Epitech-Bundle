/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** Check Keys
*/

#include "../../include/mystruct.h"

void clock_movement(rpg_t * rpg)
{
    if (rpg->player->seconds >= 0.1) {
        if (rpg->event.key.code == sfKeyD)
            move_right(rpg), sfMusic_setVolume
            (rpg->musics.run_song, rpg->options.volume);
        if (rpg->event.key.code == sfKeyQ)
            move_left(rpg), sfMusic_setVolume
            (rpg->musics.run_song, rpg->options.volume);
        if (rpg->event.key.code == sfKeyZ)
            move_up(rpg), sfMusic_setVolume
            (rpg->musics.run_song, rpg->options.volume);
        if (rpg->event.key.code == sfKeyS) {
            move_down(rpg), sfMusic_setVolume
            (rpg->musics.run_song, rpg->options.volume);
        }
        sfClock_restart(rpg->player->animation);
    }
}

void pollevent_key(rpg_t *rpg)
{
    rpg->player->time =
    sfClock_getElapsedTime(rpg->player->animation);
    rpg->player->seconds =
    rpg->player->time.microseconds / 1000000.0;
    if (rpg->menu_id == 6) {
        if (rpg->event.type == sfEvtKeyPressed) {
            clock_movement(rpg);
        }
        else if (rpg->event.type == sfEvtKeyReleased) {
            if (rpg->event.key.code == sfKeyD || rpg->event.key.code == sfKeyQ
            || rpg->event.key.code == sfKeyZ || rpg->event.key.code == sfKeyS)
                sfMusic_setVolume(rpg->musics.run_song, 0);
        }
    }
}

void check_hit(rpg_t *rpg, int c)
{
    enemie_t *tmp = rpg->enemies;
    sfVector2f pos = rpg->player->pos;
    if (c == 1) pos.x -= 100;
    if (c == 2) pos.y -= 100;
    if (c == 3) pos.x += 100;
    if (c == 4) pos.y += 100;
    while (tmp != NULL) {
        if (sqrt(pow(tmp->sprite->pos.x - pos.x, 2) + pow(tmp->sprite->pos.y -
        pos.y, 2)) < 100) {
            tmp->touched = 1;
            sfClock_restart(tmp->clock);
            tmp->stat->vel_x *= -1, tmp->stat->vel_y *= -1;
            tmp->stat->hp -= 10;
        }
        tmp = tmp->next;
    }
}

void pollevent_attack(rpg_t *rpg)
{
    if (rpg->menu_id == 6 &&
    rpg->event.key.code == sfMouseLeft &&
    rpg->event.type == sfEvtMouseButtonReleased) {
        if (rpg->state == 1)
            rpg->player->is_attacking = 1, rpg->player->rect.left = 215;
        if (rpg->state == 2)
            rpg->player->is_attacking = 2, rpg->player->rect.left = 175;
        if (rpg->state == 3)
            rpg->player->is_attacking = 3, rpg->player->rect.left = 215;
        if (rpg->state == 4)
            rpg->player->is_attacking = 4, rpg->player->rect.left = 175;
        sfSprite_setTextureRect(rpg->player->sprite, rpg->player->rect);
        check_hit(rpg, rpg->player->is_attacking);
    }
}

void pollevent_key_intro(rpg_t *rpg)
{
    if (rpg->event.type == sfEvtKeyPressed && rpg->menu_id == 0) {
        if (rpg->event.key.code == sfKeySpace)
            rpg->menu_id = 1;
    }
}
