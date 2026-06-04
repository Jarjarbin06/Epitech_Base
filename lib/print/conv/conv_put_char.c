/*
** EPITECH PROJECT, 2025
** my_printf.c
** File description:
** None
*/

#include <stdarg.h>
#include "../includes/print.h"

void p_conv_put_char(va_list list, int *char_total, p_flag_t *Flag)
{
    (void)Flag;
    p_put_char(va_arg(list, int), char_total);
}
