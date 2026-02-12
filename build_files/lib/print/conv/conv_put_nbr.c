/*
** EPITECH PROJECT, 2025
** conv_put_nbr_base.c
** File description:
** None
*/

#include <stdarg.h>
#include "../includes/print.h"
#include "../includes/print_conv.h"

static void put_flag(int *char_total, flag_t *Flag)
{
    if (Flag[0].is_plus) {
        my_put_char('+', char_total);
        return;
    }
    if (Flag[0].is_space)
        my_put_char(' ', char_total);
}

void conv_to_dec(va_list list, int *char_total, flag_t *Flag)
{
    int nb = va_arg(list, int);
    char const dec[] = "0123456789";

    if (*(Flag[0]).precision == -1)
        *(Flag[0]).precision = 0;
    if (nb == 0) {
        my_put_char('0', char_total);
        return;
    }
    if (nb < 0) {
        my_put_char('-', char_total);
        nb *= -1;
    } else
        put_flag(char_total, Flag);
    my_put_nbr_base(nb, dec, char_total, Flag);
}

void conv_to_dec_u(va_list list, int *char_total, flag_t *Flag)
{
    my_lli_t nb = va_arg(list, my_lli_t);
    char const dec[] = "0123456789";

    if (*(Flag[0].precision) == -1)
        *(Flag[0].precision) = 0;
    if (nb == 0) {
        my_put_char('0', char_total);
        return;
    }
    my_put_nbr_base(nb, dec, char_total, Flag);
}
