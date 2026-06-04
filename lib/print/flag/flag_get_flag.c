/*
** EPITECH PROJECT, 2025
** my_printf.c
** File description:
** None
*/

#include "../includes/print.h"

int p_get_flag(const char *format, int idx, p_flag_t *Flag)
{
    if (p_get_space(format, idx, Flag))
        return 1;
    if (p_get_precision(format, idx, Flag))
        return 1;
    if (p_get_hashtag(format, idx, Flag))
        return 1;
    if (p_get_plus(format, idx, Flag))
        return 1;
    if (p_get_space(format, idx, Flag))
        return 1;
    return 0;
}
