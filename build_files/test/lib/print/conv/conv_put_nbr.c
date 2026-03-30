/*
** EPITECH PROJECT, 2025
** conv_put_nbr_base.c
** File description:
** None
*/

#include <stdarg.h>
#include "print.h"
#include "print_conv.h"

static void put_flag(int *char_total, p_flag_t *Flag)
{
    if (Flag[0].is_plus) {
        p_put_char('+', char_total);
        return;
    }
    if (Flag[0].is_space)
        p_put_char(' ', char_total);
}

void p_conv_to_dec(va_list list, int *char_total, p_flag_t *Flag)
{
    int nb = va_arg(list, int);
    char const dec[] = "0123456789";

    if (*(Flag[0]).precision == -1)
        *(Flag[0]).precision = 0;
    if (nb == 0) {
        p_put_char('0', char_total);
        return;
    }
    if (nb < 0) {
        p_put_char('-', char_total);
        nb *= -1;
    } else
        put_flag(char_total, Flag);
    p_put_nbr_base(nb, dec, char_total, Flag);
}

void p_conv_to_dec_u(va_list list, int *char_total, p_flag_t *Flag)
{
    p_lli_t nb = va_arg(list, p_lli_t);
    char const dec[] = "0123456789";

    if (*(Flag[0].precision) == -1)
        *(Flag[0].precision) = 0;
    if (nb == 0) {
        p_put_char('0', char_total);
        return;
    }
    p_put_nbr_base(nb, dec, char_total, Flag);
}
