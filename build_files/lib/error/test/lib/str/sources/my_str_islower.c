/*
** EPITECH PROJECT, 2025
** sources - my_str_islower.c
** File description:
** <description>
*/

#include "../includes/str.h"

bool is_lower(const char c)
{
    if (('a' <= c && c <= 'z'))
        return true;
    return false;
}

bool my_str_islower(const char *str)
{
    if (!str)
        return false;
    for (int idx = 0; str[idx] != '\0'; idx++)
        if (!is_lower(str[idx]))
            return false;
    return true;
}
