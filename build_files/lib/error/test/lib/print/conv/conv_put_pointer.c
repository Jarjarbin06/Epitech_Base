/*
** EPITECH PROJECT, 2025
** my_printf.c
** File description:
** None
*/

#include <stdarg.h>
#include "../includes/print.h"
#include "../includes/print_conv.h"

void p_conv_put_pointer(va_list list, int *char_total, p_flag_t *Flag)
{
    p_put_str("0x", char_total);
    p_put_nbr_base((p_lli_t)va_arg(list, p_var_ptr_t),
        "0123456789abcdef", char_total, Flag);
}
