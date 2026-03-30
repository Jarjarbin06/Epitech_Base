/*
** EPITECH PROJECT, 2025
** my_printf.c
** File description:
** None
*/

#include "print.h"

int p_get_plus(const char *format, int idx, p_flag_t *Flag)
{
    if (format[idx] == '+') {
        Flag[0].is_plus = 1;
        return 1;
    }
    return 0;
}
