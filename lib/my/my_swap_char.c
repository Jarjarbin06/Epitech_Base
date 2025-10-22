/*
** EPITECH PROJECT, 2025
** my_swap.c
** File description:
** None
*/

#include "my.h"

void my_swap_char(char *ptr_a, char *ptr_b)
{
    char c = *ptr_a;

    *ptr_a = *ptr_b;
    *ptr_b = c;
}
