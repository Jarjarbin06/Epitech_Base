/*
** EPITECH PROJECT, 2025
** my_printf.c
** File description:
** None
*/

#include "../includes/print.h"

int get_hashtag(const char *format, int idx, flag_t *Flag)
{
    if (format[idx] == '#') {
        Flag[0].is_hashtag = 1;
        return 1;
    }
    return 0;
}
