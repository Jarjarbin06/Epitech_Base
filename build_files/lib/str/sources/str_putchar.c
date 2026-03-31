/*
** EPITECH PROJECT, 2025
** sources - str_putchar.c
** File description:
** <description>
*/

#include <unistd.h>

#include "../includes/str.h"

int str_putchar(const char c)
{
    return ((write(1, &c, 1) != 1) ?
        (EXIT_FAILURE) : (EXIT_SUCCESS));
}
