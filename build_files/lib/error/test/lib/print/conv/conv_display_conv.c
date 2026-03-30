/*
** EPITECH PROJECT, 2025
** my_printf.c
** File description:
** None
*/

#include <stddef.h>
#include <stdarg.h>
#include "../includes/print_conv.h"

static const p_list_t Conv[] = {
    {'d', &p_conv_to_dec},
    {'i', &p_conv_to_dec},
    {'o', &p_conv_to_oct},
    {'u', &p_conv_to_dec_u},
    {'x', &p_conv_to_hex},
    {'X', &p_conv_to_hex_maj},
    {'e', &p_conv_put_scientific},
    {'E', &p_conv_put_scientific_maj},
    {'f', &p_conv_put_float},
    {'F', &p_conv_put_float_maj},
    {'g', &p_conv_put_g},
    {'G', &p_conv_put_g_maj},
    {'a', &p_conv_err},
    {'A', &p_conv_err},
    {'c', &p_conv_put_char},
    {'s', &p_conv_put_str},
    {'p', &p_conv_put_pointer},
    {'n', &p_conv_err},
    {'m', &p_conv_stderr},
    {'%', &p_conv_put_modulo},
    {'\n', &p_conv_put_line},
    {'\0', NULL}
};

void p_display_conv(const char conv, va_list list, int *c_tt, p_flag_t *Flag)
{
    for (int i = 0; Conv[i].conv != '\0'; i++)
        if (conv == Conv[i].conv) {
            Conv[i].func(list, c_tt, Flag);
            return;
        }
}
