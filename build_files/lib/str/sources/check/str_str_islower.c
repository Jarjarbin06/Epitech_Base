/*
** EPITECH PROJECT, 2025
** sources - str_str_islower.c
** File description:
** <description>
*/

#include "../../includes/str.h"

bool str_c_is_lower(char c)
{
    if (('a' <= c && c <= 'z'))
        return true;
    return false;
}

bool str_is_lower(str_t str)
{
    if (!str)
        return false;
    for (int idx = 0; str[idx] != '\0'; idx++)
        if (!str_c_is_lower(str[idx]))
            return false;
    return true;
}
