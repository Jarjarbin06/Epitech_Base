/*
** EPITECH PROJECT, 2025
** my_printf.c
** File description:
** None
*/

#include <stddef.h>
#include <stdarg.h>
#include "../includes/print_conv.h"

static const list_t Conv[] = {
    {'d', &conv_to_dec},
    {'i', &conv_to_dec},
    {'o', &conv_to_oct},
    {'u', &conv_to_dec_u},
    {'x', &conv_to_hex},
    {'X', &conv_to_hex_maj},
    {'e', &conv_put_scientific},
    {'E', &conv_put_scientific_maj},
    {'f', &conv_put_float},
    {'F', &conv_put_float_maj},
    {'g', &conv_put_g},
    {'G', &conv_put_g_maj},
    {'a', &conv_err},
    {'A', &conv_err},
    {'c', &conv_put_char},
    {'s', &conv_put_str},
    {'p', &conv_put_pointer},
    {'n', &conv_err},
    {'m', &conv_stderr},
    {'%', &conv_put_modulo},
    {'\n', &conv_put_line},
    {'\0', NULL}
};

void display_conv(char conv, va_list list, int *c_tt, flag_t *Flag)
{
    for (int i = 0; Conv[i].conv != '\0'; i++)
        if (conv == Conv[i].conv) {
            Conv[i].func(list, c_tt, Flag);
            return;
        }
}
