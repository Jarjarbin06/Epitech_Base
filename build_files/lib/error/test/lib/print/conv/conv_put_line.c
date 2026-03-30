/*
** EPITECH PROJECT, 2025
** my_printf.c
** File description:
** None
*/

#include <stdarg.h>
#include "../includes/print.h"

void p_conv_put_line(va_list list, int *char_total, p_flag_t *Flag)
{
    (void)list;
    if (Flag[0].is_space)
        p_put_str("% \n", char_total);
    else
        p_put_str("%\n", char_total);
}
