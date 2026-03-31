/*
** EPITECH PROJECT, 2025
** conv_put_nbr_base.c
** File description:
** None
*/

#include <stdarg.h>
#include "../includes/print.h"

static void put_zero(int *char_total, int precision)
{
    for (; precision > 0; precision--) {
        p_put_char('0', char_total);
        *char_total += 1;
    }
}

static void my_put_nbr(p_lli_t nb, char const *base, int *c_tt)
{
    p_lli_t c = nb;
    int base_length = p_strlen(base);

    if (c >= 1) {
        my_put_nbr(c / base_length, base, c_tt);
        p_put_char(base[c % base_length], c_tt);
    }
}

void p_put_nbr_base(p_lli_t nb, char const *base, int *c_tt, p_flag_t *Flag)
{
    p_lli_t new_nb = nb;
    int precision = *(Flag[0].precision);
    int len = 0;

    for (; new_nb != 0; len++)
        new_nb *= 0.1;
    put_zero(c_tt, precision - len);
    my_put_nbr(nb, base, c_tt);
}

void p_conv_to_bin(va_list list, int *char_total, p_flag_t *Flag)
{
    p_lli_t nb = va_arg(list, p_lli_t);
    char const bin[] = "01";

    if (*(Flag[0]).precision == -1)
        *(Flag[0]).precision = 0;
    if (Flag[0].is_hashtag)
        p_put_str("0b", char_total);
    if (nb == 0) {
        p_put_char('0', char_total);
        return;
    }
    p_put_nbr_base(nb, bin, char_total, Flag);
}

void p_conv_to_oct(va_list list, int *char_total, p_flag_t *Flag)
{
    p_lli_t nb = va_arg(list, p_lli_t);
    char const bin[] = "01234567";

    if (*(Flag[0]).precision == -1)
        *(Flag[0]).precision = 0;
    if (Flag[0].is_hashtag)
        p_put_char('0', char_total);
    if (nb == 0) {
        p_put_char('0', char_total);
        return;
    }
    p_put_nbr_base(nb, bin, char_total, Flag);
}

void p_conv_to_hex(va_list list, int *char_total, p_flag_t *Flag)
{
    p_lli_t nb = va_arg(list, p_lli_t);
    char const bin[] = "0123456789abcdef";

    if (*(Flag[0]).precision == -1)
        *(Flag[0]).precision = 0;
    if (Flag[0].is_hashtag)
        p_put_str("0x", char_total);
    if (nb == 0) {
        p_put_char('0', char_total);
        return;
    }
    p_put_nbr_base(nb, bin, char_total, Flag);
}

void p_conv_to_hex_maj(va_list list, int *char_total, p_flag_t *Flag)
{
    p_lli_t nb = va_arg(list, p_lli_t);
    char const bin[] = "0123456789ABCDEF";

    if (*(Flag[0]).precision == -1)
        *(Flag[0]).precision = 0;
    if (Flag[0].is_hashtag)
        p_put_str("0x", char_total);
    if (nb == 0) {
        p_put_char('0', char_total);
        return;
    }
    p_put_nbr_base(nb, bin, char_total, Flag);
}
