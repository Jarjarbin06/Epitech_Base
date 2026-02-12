/*
** EPITECH PROJECT, 2025
** my_printf.c
** File description:
** None
*/

#include <stdarg.h>
#include "../includes/print.h"
#include "../includes/print_conv.h"

static void put_zero(int *char_total, int precision)
{
    for (; precision > 0; precision--)
        my_put_char('0', char_total);
}

static void display_nbr(my_lli_t nb, int *c_tt)
{
    char digit = '0';

    if (nb < 1) {
        my_put_char('0', c_tt);
        return;
    }
    if (nb >= 10)
        display_nbr(nb * 0.1, c_tt);
    digit = (nb % 10) + '0';
    my_put_char(digit, c_tt);
}

static void display_float(my_ld_t nb, int precision, int *c_tt, flag_t *Flag)
{
    int i = 0;

    if (nb < 0) {
        nb *= -1;
        my_put_char('-', c_tt);
    }
    for (; i < precision; i++) {
        if (i == 10)
            my_put_nbr_base(nb, "0123456789", c_tt, Flag);
        if (i > 10)
            my_put_char('0', c_tt);
        nb *= 10;
    }
    if (i <= 10)
        my_put_nbr_base(nb, "0123456789", c_tt, Flag);
    put_zero(c_tt, precision - i);
}

void put_float(my_ld_t nb, int *char_total, flag_t *Flag)
{
    if (nb < 0) {
        my_put_char('-', char_total);
        nb *= -1;
    }
    if (Flag[0].is_plus)
        my_put_char('+', char_total);
    if (nb == 0) {
        my_put_str("0.", char_total);
        return put_zero(char_total, *(Flag[0]).precision);
    }
    display_nbr(F2I(nb), char_total);
    nb -= F2I(nb);
    if (nb == 0) {
        if (*(Flag[0]).precision == 0 && Flag[0].is_hashtag)
            my_put_char('.', char_total);
        return;
    }
    if (*(Flag[0]).precision > 0 || Flag[0].is_hashtag)
        my_put_char('.', char_total);
    display_float(nb, *(Flag[0]).precision, char_total, Flag);
}

void conv_put_float(va_list list, int *char_total, flag_t *Flag)
{
    double nb = va_arg(list, double);

    if (is_inf_or_nan((my_ld_t)nb, char_total, 0))
        return;
    if (*(Flag[0]).precision == -1)
        *(Flag[0]).precision = 6;
    put_float((my_ld_t)nb, char_total, Flag);
}

void conv_put_float_maj(va_list list, int *char_total, flag_t *Flag)
{
    double nb = va_arg(list, double);

    if (is_inf_or_nan((my_ld_t)nb, char_total, 1))
        return;
    if (*(Flag[0]).precision == -1)
        *(Flag[0]).precision = 6;
    put_float((my_ld_t)nb, char_total, Flag);
}
