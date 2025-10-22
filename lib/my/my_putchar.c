/*
** EPITECH PROJECT, 2025
** my_putchar.c
** File description:
** None
*/

#include "my.h"
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
