/*
** EPITECH PROJECT, 2025
** sources - str_putstr.c
** File description:
** <description>
*/

#include <unistd.h>

#include "../../includes/str.h"

int str_put_str(const cstr_t string)
{
    if (!string)
        return EXIT_ERROR;
    return ((write(1, string, str_len(string)) != str_len(string)) ?
        (EXIT_ERROR) : (EXIT_SUCCESS));
}
