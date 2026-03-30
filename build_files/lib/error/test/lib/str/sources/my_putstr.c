/*
** EPITECH PROJECT, 2025
** sources - my_putstr.c
** File description:
** <description>
*/

#include <unistd.h>

#include "../includes/str.h"

int my_putstr(const char *str)
{
    if (!str)
        return EXIT_FAILURE;
    return ((write(1, str, p_strlen(str)) != p_strlen(str)) ?
        (EXIT_FAILURE) : (EXIT_SUCCESS));
}
