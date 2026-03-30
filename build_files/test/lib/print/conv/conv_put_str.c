/*
** EPITECH PROJECT, 2025
** my_printf.c
** File description:
** None
*/

#include <stdarg.h>
#include <unistd.h>
#include "print.h"

void p_conv_put_str(va_list list, int *char_total, p_flag_t *Flag)
{
    const p_var_ptr_t pointer = va_arg(list, p_var_ptr_t);
    char *str;

    (void)Flag;
    if (pointer == NULL)
        return;
    if ((long)pointer < 1000)
        return;
    str = (char *) *pointer;
    for (int index = 0; str[index] != '\0'; index++)
        p_put_char(str[index], char_total);
}
