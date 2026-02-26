/*
** EPITECH PROJECT, 2025
** my_printf.c
** File description:
** None
*/

#include <stdarg.h>
#include "../includes/print.h"

void conv_stderr(va_list list, int *char_total, flag_t *Flag)
{
    (void)list;
    (void)Flag;
    my_put_str("Success", char_total);
}
