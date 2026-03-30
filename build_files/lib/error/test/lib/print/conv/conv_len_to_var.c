/*
** EPITECH PROJECT, 2025
** my_printf.c
** File description:
** None
*/

#include <stdarg.h>
#include <unistd.h>
#include "../includes/print.h"

void p_conv_len_to_var(va_list list, int *char_total, p_flag_t *Flag)
{
    const p_var_ptr_t pointer = va_arg(list, p_var_ptr_t);
    int *var = va_arg(list, int *);

    (void)Flag;
    if (pointer == NULL)
        return;
    if ((long)pointer != 8)
        return;
    var = (int *) *pointer;
    *var = *char_total;
}
