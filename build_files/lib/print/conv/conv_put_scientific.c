/*
** EPITECH PROJECT, 2025
** my_printf.c
** File description:
** None
*/

#include <stdarg.h>
#include "../includes/print.h"
#include "../includes/print_conv.h"

static void put_e(int maj, int *char_total)
{
    if (maj)
        my_put_char('E', char_total);
    else
        my_put_char('e', char_total);
}

static void put_scientific_pos(my_ld_t nb, int *c_tt, flag_t *Flag, int maj)
{
    int e_count = 0;

    while (nb > 10) {
        nb *= 0.1;
        e_count++;
    }
    put_float(nb, c_tt, Flag);
    put_e(maj, c_tt);
    if (e_count == 0) {
        my_put_char('0', c_tt);
        return;
    }
    my_put_char('+', c_tt);
    if (e_count < 10)
        my_put_char('0', c_tt);
    *(Flag[0]).precision = 0;
    my_put_nbr_base(e_count, "0123456789", c_tt, Flag);
}

static void put_scientific_neg(my_ld_t nb, int *c_tt, flag_t *Flag, int maj)
{
    int e_count = 0;

    while (nb < 1) {
        nb *= 10;
        e_count--;
    }
    put_float(nb, c_tt, Flag);
    put_e(maj, c_tt);
    if (e_count == 0) {
        my_put_char('0', c_tt);
        return;
    }
    e_count *= -1;
    my_put_char('-', c_tt);
    if (e_count < 10)
        my_put_char('0', c_tt);
    *(Flag[0]).precision = 0;
    my_put_nbr_base(e_count, "0123456789", c_tt, Flag);
}

void put_scientific(my_ld_t nb, int *c_tt, flag_t *Flag, int maj)
{
    if (is_inf_or_nan(nb, c_tt, maj))
        return;
    if (nb == 0) {
        my_put_char('0', c_tt);
        return;
    }
    if (nb < 0) {
        my_put_char('-', c_tt);
        nb *= -1;
    }
    if (nb >= 1)
        put_scientific_pos(nb, c_tt, Flag, maj);
    if (nb < 1)
        put_scientific_neg(nb, c_tt, Flag, maj);
}

void conv_put_scientific(va_list list, int *char_total, flag_t *Flag)
{
    double nb = va_arg(list, double);

    if (*(Flag[0]).precision == -1)
        *(Flag[0]).precision = 6;
    put_scientific((my_ld_t)nb, char_total, Flag, 0);
}

void conv_put_scientific_maj(va_list list, int *char_total, flag_t *Flag)
{
    double nb = va_arg(list, double);

    if (*(Flag[0]).precision == -1)
        *(Flag[0]).precision = 6;
    put_scientific((my_ld_t)nb, char_total, Flag, 1);
}
