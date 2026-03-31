/*
** EPITECH PROJECT, 2025
** my_printf.c
** File description:
** None
*/

#include "../includes/print.h"

int p_get_precision(const char *format, int idx, p_flag_t *Flag)
{
    if (format[idx] == '.') {
        *(Flag[0].precision) = p_get_nbr(&format[idx + 1]);
        return 1;
    }
    return 0;
}
