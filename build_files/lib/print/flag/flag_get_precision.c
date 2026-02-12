/*
** EPITECH PROJECT, 2025
** my_printf.c
** File description:
** None
*/

#include "../includes/print.h"

int get_precision(const char *format, int idx, flag_t *Flag)
{
    if (format[idx] == '.') {
        *(Flag[0].precision) = my_get_nbr(&format[idx + 1]);
        return 1;
    }
    return 0;
}
