/*
** EPITECH PROJECT, 2025
** my_printf.c
** File description:
** None
*/

#include <stdarg.h>
#include "../includes/print.h"

void len_mod_err(va_list list, int *char_total, const flag_t *Flag)
{
    (void)list;
    (void)char_total;
    (void)Flag;
    my_put_str("[err]", char_total);
}
