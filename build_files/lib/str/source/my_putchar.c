/*
** EPITECH PROJECT, 2025
** sources - my_putchar.c
** File description:
** <description>
*/

#include <unistd.h>

#include "../include/str.h"

void my_putchar(const char c)
{
    write(1, &c, 1);
}
