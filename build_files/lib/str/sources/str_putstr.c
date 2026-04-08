/*
** EPITECH PROJECT, 2025
** sources - str_putstr.c
** File description:
** <description>
*/

#include <unistd.h>

#include "../includes/str.h"

int str_putstr(const char *str)
{
    if (!str)
        return EXIT_ERROR;
    return ((write(1, str, str_strlen(str)) != str_strlen(str)) ?
        (EXIT_ERROR) : (EXIT_SUCCESS));
}
