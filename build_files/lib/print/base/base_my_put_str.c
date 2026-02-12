/*
** EPITECH PROJECT, 2025
** my_printf.c
** File description:
** None
*/

#include "../includes/print.h"

void my_put_str(const char *str, int *char_total)
{
    for (int idx = 0; str[idx] != '\0'; idx++)
        my_put_char(str[idx], char_total);
}
