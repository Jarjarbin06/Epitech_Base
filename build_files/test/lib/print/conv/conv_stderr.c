/*
** EPITECH PROJECT, 2025
** my_printf.c
** File description:
** None
*/

#include <stdarg.h>
#include "print.h"

void p_conv_stderr(va_list list, int *char_total, p_flag_t *Flag)
{
    (void)list;
    (void)Flag;
    p_put_str("Success", char_total);
}
