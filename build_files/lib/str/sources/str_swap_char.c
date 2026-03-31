/*
** EPITECH PROJECT, 2025
** sources - str_swap_char.c
** File description:
** <description>
*/

#include "../includes/str.h"

void str_swap_char(char *ptr_a, char *ptr_b)
{
    char c = 0;

    if (!ptr_a || !ptr_b)
        return;
    c = *ptr_a;
    *ptr_a = *ptr_b;
    *ptr_b = c;
}
