/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** Create Game
*/

#include "../../include/mystruct.h"

sfVector2f get_player_pos(rpg_t *rpg)
{
    sfVector2f pos;
    int y = 0;
    int x = 0;
    while (rpg->map[y] != 0) {
        while (rpg->map[y][x] != '\0') {
            if (rpg->map[y][x] == 'P') {
                pos.x = x * 25 * 3;
                pos.y = y * 25 * 3;
            }
            x++;
        }
        y++, x = 0;
    }
    return (pos);
}

int height_array(char **map)
{
    int y = 0;
    while (map[y] != 0)
        y++;
    return (y);
}

char **make_map_from_str(char *buff)
{
    int i, a, j, b;
    i = a = j = b = 0;
    while (buff[i] != '\n') {
        if (buff[i] == '\0')
            break;
        i++;
    }
    char **map = malloc(sizeof(char *) * (i + 3));
    while (buff[a] != '\0') {
        char *tmp = malloc(sizeof(char) * (i + 1));
        while (buff[a] != '\n' && buff[a] != '\0')
            tmp[j] = buff[a], a++, j++;
        tmp[j] = '\0', map[b] = tmp, b++, j = 0;
        if (buff[a] == '\0')
            break;
        a++;
    }
    map[b] = 0;
    return (map);
}

char *load_file(char const *filepath)
{
    struct stat statbuffer;
    stat(filepath, &statbuffer);
    char *buffer = malloc(sizeof(char) * statbuffer.st_size * 1000);

    int path = open(filepath, O_RDONLY);
    if (path < 0) {
        my_putstr("File is not found.\n");
        return ("Error");
    }
    int valeur = read(path, buffer, statbuffer.st_size + 1);
    if (valeur < 0) {
        my_putstr("Read failed\n");
        return ("Error");
    }
    buffer[statbuffer.st_size] = '\0';
    close(path);
    return (buffer);
}

void manage_position(rpg_t *rpg)
{
    sfVector2f pos = sfSprite_getPosition(rpg->player->sprite);
    if (pos.x != rpg->player_pos.x) {
        if (pos.x > rpg->player_pos.x)
            rpg->player->pos.x -= 12.5;
        else
            rpg->player->pos.x += 12.5;
    }
    if (pos.y != rpg->player_pos.y) {
        if (pos.y > rpg->player_pos.y)
            rpg->player->pos.y -= 12.5;
        else
            rpg->player->pos.y += 12.5;
    }
    sfSprite_setPosition(rpg->player->sprite, rpg->player->pos);
}
