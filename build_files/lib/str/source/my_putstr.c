/*
** EPITECH PROJECT, 2025
** my_putstr.c
** File description:
** None
*/

#include <unistd.h>

#include "../include/str.h"

int my_putstr(const char *str)
{
    for (int idx = 0; str[idx] != '\0'; idx++)
        write(1, &str[idx], 1);
    return EXIT_SUCCESS;
}
