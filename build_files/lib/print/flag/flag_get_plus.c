/*
** EPITECH PROJECT, 2025
** my_printf.c
** File description:
** None
*/

#include "../includes/print.h"

int get_plus(const char *format, int idx, flag_t *Flag)
{
    if (format[idx] == '+') {
        Flag[0].is_plus = 1;
        return 1;
    }
    return 0;
}
