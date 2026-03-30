/*
** EPITECH PROJECT, 2025
** my_printf.c
** File description:
** None
*/

#include "print.h"

void p_put_str(const char *str, int *char_total)
{
    for (int idx = 0; str[idx] != '\0'; idx++)
        p_put_char(str[idx], char_total);
}
