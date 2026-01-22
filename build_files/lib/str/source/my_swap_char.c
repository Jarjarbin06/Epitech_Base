/*
** EPITECH PROJECT, 2025
** source - my_swap_char.c
** File description:
** <description>
*/

#include "../include/str.h"

void my_swap_char(char *ptr_a, char *ptr_b)
{
    const char c = *ptr_a;

    if (!ptr_a || !ptr_b)
        return;
    *ptr_a = *ptr_b;
    *ptr_b = c;
}
