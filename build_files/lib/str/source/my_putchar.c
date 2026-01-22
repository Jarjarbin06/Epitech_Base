/*
** EPITECH PROJECT, 2025
** my_putchar.c
** File description:
** None
*/

#include <unistd.h>

#include "../include/str.h"

void my_putchar(const char c)
{
    write(1, &c, 1);
}
