/*
** EPITECH PROJECT, 2025
** my_printf.c
** File description:
** None
*/

#include <stdarg.h>
#include "../includes/print.h"
#include "../includes/print_conv.h"

void conv_put_pointer(va_list list, int *char_total, flag_t *Flag)
{
    my_put_str("0x", char_total);
    my_put_nbr_base((my_lli_t)va_arg(list, var_ptr_t),
        "0123456789abcdef", char_total, Flag);
}
