/*
** EPITECH PROJECT, 2025
** mini_printf.h
** File description:
** None
*/

#ifndef PRINTF_MY_CONV_H
    #define PRINTF_MY_CONV_H
    #include <stdarg.h>
    #include "print_flag.h"
    #define F2I(x) (x >= 0.5 ? (my_lli_t)(x) : (my_lli_t)(x - 1))
    #define MIN(nb1, nb2) ((nb1) >= (nb2) ? (nb2) : (nb1))
    #define MAX(nb1, nb2) ((nb1) >= (nb2) ? (nb1) : (nb2))

void display_conv(char conv, va_list list, int *c_tt, flag_t *Flag);

void conv_err(va_list list, int *char_total, flag_t *Flag);

void conv_len_to_var(va_list list, int *char_total, flag_t *Flag);

void conv_put_char(va_list list, int *char_total, flag_t *Flag);

void put_float(my_ld_t nb, int *char_total, flag_t *Flag);
void conv_put_float(va_list list, int *char_total, flag_t *Flag);
void conv_put_float_maj(va_list list, int *char_total, flag_t *Flag);

void conv_put_g(va_list list, int *char_total, flag_t *Flag);
void conv_put_g_maj(va_list list, int *char_total, flag_t *Flag);

void conv_put_line(va_list list, int *char_total, flag_t *Flag);

void conv_put_modulo(va_list list, int *char_total, flag_t *Flag);

void my_put_nbr_base(my_lli_t nb, char const *base, int *c_tt, flag_t *Flag);
void conv_to_dec(va_list list, int *char_total, flag_t *Flag);
void conv_to_dec_u(va_list list, int *char_total, flag_t *Flag);

void conv_to_bin(va_list list, int *char_total, flag_t *Flag);
void conv_to_oct(va_list list, int *char_total, flag_t *Flag);
void conv_to_hex(va_list list, int *char_total, flag_t *Flag);
void conv_to_hex_maj(va_list list, int *char_total, flag_t *Flag);

void conv_put_pointer(va_list list, int *char_total, flag_t *Flag);

void put_scientific(my_ld_t nb, int *char_total, flag_t *Flag, int maj);
void conv_put_scientific(va_list list, int *char_total, flag_t *Flag);
void conv_put_scientific_maj(va_list list, int *char_total, flag_t *Flag);

void conv_put_str(va_list list, int *char_total, flag_t *Flag);

void conv_stderr(va_list list, int *char_total, flag_t *Flag);

#endif
