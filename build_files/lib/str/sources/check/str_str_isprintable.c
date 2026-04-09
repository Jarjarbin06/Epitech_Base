/*
** EPITECH PROJECT, 2025
** sources - str_str_isprintable.c
** File description:
** <description>
*/

#include "../../includes/str.h"

bool str_c_is_printable(cc_t c)
{
    if ((' ' <= c && c <= '~'))
        return true;
    return false;
}

bool str_is_printable(const cstr_t str)
{
    if (!str)
        return false;
    for (int idx = 0; str[idx] != '\0'; idx++)
        if (!str_c_is_printable(str[idx]))
            return false;
    return true;
}
