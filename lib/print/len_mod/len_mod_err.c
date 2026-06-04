/*
** EPITECH PROJECT, 2025
** my_printf.c
** File description:
** None
*/

#include <stdarg.h>
#include "../includes/print.h"

void p_len_mod_err(va_list list, int *char_total, const p_flag_t *Flag)
{
    (void)list;
    (void)char_total;
    (void)Flag;
    p_put_str("[err]", char_total);
}
