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
        p_put_char('E', char_total);
    else
        p_put_char('e', char_total);
}

static void put_scientific_pos(p_ld_t nb, int *c_tt, p_flag_t *Flag, int maj)
{
    int e_count = 0;

    while (nb > 10) {
        nb *= 0.1;
        e_count++;
    }
    p_put_float(nb, c_tt, Flag);
    put_e(maj, c_tt);
    if (e_count == 0) {
        p_put_char('0', c_tt);
        return;
    }
    p_put_char('+', c_tt);
    if (e_count < 10)
        p_put_char('0', c_tt);
    *(Flag[0]).precision = 0;
    p_put_nbr_base(e_count, "0123456789", c_tt, Flag);
}

static void put_scientific_neg(p_ld_t nb, int *c_tt, p_flag_t *Flag, int maj)
{
    int e_count = 0;

    while (nb < 1) {
        nb *= 10;
        e_count--;
    }
    p_put_float(nb, c_tt, Flag);
    put_e(maj, c_tt);
    if (e_count == 0) {
        p_put_char('0', c_tt);
        return;
    }
    e_count *= -1;
    p_put_char('-', c_tt);
    if (e_count < 10)
        p_put_char('0', c_tt);
    *(Flag[0]).precision = 0;
    p_put_nbr_base(e_count, "0123456789", c_tt, Flag);
}

void p_put_scientific(p_ld_t nb, int *c_tt, p_flag_t *Flag, int maj)
{
    if (p_is_inf_or_nan(nb, c_tt, maj))
        return;
    if (nb == 0) {
        p_put_char('0', c_tt);
        return;
    }
    if (nb < 0) {
        p_put_char('-', c_tt);
        nb *= -1;
    }
    if (nb >= 1)
        put_scientific_pos(nb, c_tt, Flag, maj);
    if (nb < 1)
        put_scientific_neg(nb, c_tt, Flag, maj);
}

void p_conv_put_scientific(va_list list, int *char_total, p_flag_t *Flag)
{
    double nb = va_arg(list, double);

    if (*(Flag[0]).precision == -1)
        *(Flag[0]).precision = 6;
    p_put_scientific((p_ld_t)nb, char_total, Flag, 0);
}

void p_conv_put_scientific_maj(va_list list, int *char_total, p_flag_t *Flag)
{
    double nb = va_arg(list, double);

    if (*(Flag[0]).precision == -1)
        *(Flag[0]).precision = 6;
    p_put_scientific((p_ld_t)nb, char_total, Flag, 1);
}
