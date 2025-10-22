/*
** EPITECH PROJECT, 2025
** my_swap.c
** File description:
** None
*/

#include "my.h"

void my_swap(int *ptr_a, int *ptr_b)
{
    int c = *ptr_a;

    *ptr_a = *ptr_b;
    *ptr_b = c;
}
