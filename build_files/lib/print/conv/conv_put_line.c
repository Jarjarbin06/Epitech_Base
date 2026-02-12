/*
** EPITECH PROJECT, 2025
** my_printf.c
** File description:
** None
*/

#include <stdarg.h>
#include "../includes/print.h"

void conv_put_line(va_list list, int *char_total, flag_t *Flag)
{
    if (Flag[0].is_space)
        my_put_str("% \n", char_total);
    else
        my_put_str("%\n", char_total);
}
