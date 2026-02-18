/*
** EPITECH PROJECT, 2025
** my_printf.c
** File description:
** None
*/

#include <stdarg.h>
#include <unistd.h>
#include "../includes/print.h"

void conv_len_to_var(va_list list, int *char_total, flag_t *Flag)
{
    const var_ptr_t pointer = va_arg(list, var_ptr_t);
    int *var = va_arg(list, int *);

    if (pointer == NULL)
        return;
    if ((long)pointer != 8)
        return;
    var = (int *) *pointer;
    *var = *char_total;
}
