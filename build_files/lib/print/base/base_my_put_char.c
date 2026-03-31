/*
** EPITECH PROJECT, 2025
** my_printf.c
** File description:
** None
*/

#include <unistd.h>
#include "../includes/print.h"

void p_put_char(const char c, int *char_total)
{
    write(1, &c, 1);
    *char_total += 1;
}
