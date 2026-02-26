/*
** EPITECH PROJECT, 2025
** my_printf.c
** File description:
** None
*/

#include <stdarg.h>
#include <unistd.h>
#include "../includes/print.h"

void conv_put_str(va_list list, int *char_total, flag_t *Flag)
{
    const var_ptr_t pointer = va_arg(list, var_ptr_t);
    char *str;

    (void)Flag;
    if (pointer == NULL)
        return;
    if ((long)pointer < 1000)
        return;
    str = (char *) *pointer;
    for (int index = 0; str[index] != '\0'; index++)
        my_put_char(str[index], char_total);
}
