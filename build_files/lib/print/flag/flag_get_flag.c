/*
** EPITECH PROJECT, 2025
** my_printf.c
** File description:
** None
*/

#include "../includes/print.h"

int get_flag(const char *format, int idx, flag_t *Flag)
{
    if (get_space(format, idx, Flag))
        return 1;
    if (get_precision(format, idx, Flag))
        return 1;
    if (get_hashtag(format, idx, Flag))
        return 1;
    if (get_plus(format, idx, Flag))
        return 1;
    if (get_space(format, idx, Flag))
        return 1;
    return 0;
}
