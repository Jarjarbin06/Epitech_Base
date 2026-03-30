/*
** EPITECH PROJECT, 2025
** my_printf.c
** File description:
** None
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>
#include "print.h"
#include "print_conv.h"

static p_ld_t set_to_float(p_ld_t nb)
{
    while ((int)nb / 10)
        nb /= 10;
    return nb;
}

static int digits_before_decimal(p_ld_t nb)
{
    int dbd = 0;

    if ((int)nb == 0)
        while ((int)(nb * 10) == 0) {
            nb *= 10;
            dbd--;
        }
    else
        while ((int)nb > 0) {
            nb /= 10;
            dbd++;
        }
    return dbd;
}

static int digits_after_decimal(p_ld_t nb, int precision)
{
    int dad = 0;

    for (int i = 1; i <= precision; i++) {
        nb -= (int)nb;
        nb *= 10;
        if ((int)nb % 10 != 0)
            dad = i;
    }
    return dad;
}

static void put_g(p_ld_t nb, int *char_total, p_flag_t *Flag, const bool maj)
{
    int prec = *(Flag[0].precision);
    int const dbd = digits_before_decimal(nb);

    if (dbd > prec || dbd <= -4) {
        *(Flag[0]).precision = digits_after_decimal(set_to_float(nb), prec);
        p_put_scientific(nb, char_total, Flag, maj);
    } else {
        *(Flag[0]).precision = (digits_after_decimal(nb, prec - dbd));
        if (p_is_inf_or_nan(nb, char_total, maj))
            return;
        p_put_float(nb, char_total, Flag);
    }
}

void p_conv_put_g(va_list list, int *char_total, p_flag_t *Flag)
{
    double nb = va_arg(list, double);

    if (*(Flag[0].precision) == -1)
        *(Flag[0].precision) = 6;
    put_g((p_ld_t)nb, char_total, Flag, 0);
}

void p_conv_put_g_maj(va_list list, int *char_total, p_flag_t *Flag)
{
    double nb = va_arg(list, double);

    if (*(Flag[0].precision) == -1)
        *(Flag[0].precision) = 6;
    put_g((p_ld_t)nb, char_total, Flag, 1);
}
