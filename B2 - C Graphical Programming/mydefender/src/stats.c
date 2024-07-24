/*
** EPITECH PROJECT, 2022
** STATS
** File description:
** Functions setting stats
*/

#include "../include/my.h"

t_stat *set_stats_t(float atk, float atkspd, float range)
{
    t_stat *stat = malloc(sizeof(t_stat));
    stat->ATK = atk;
    stat->ATKSPD = atkspd;
    stat->RANGE = range;
    return (stat);
}

t_stat *set_stats_e(float hp, float atk)
{
    t_stat *stat = malloc(sizeof(t_stat));
    stat->ATK = atk;
    stat->HP = hp;
    stat->HP_max = hp;
    return (stat);
}
