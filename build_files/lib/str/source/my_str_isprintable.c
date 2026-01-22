/*
** EPITECH PROJECT, 2025
** source - my_str_isprintable.c
** File description:
** <description>
*/

#include "../include/str.h"

bool is_printable(const char c)
{
    if ((' ' <= c && c <= '~'))
        return true;
    return false;
}

bool my_str_isprintable(const char *str)
{
    if (!str)
        return false;
    for (int idx = 0; str[idx] != '\0'; idx++)
        if (!is_printable(str[idx]))
            return false;
    return true;
}
