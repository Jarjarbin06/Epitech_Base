/*
** EPITECH PROJECT, 2025
** sources - str_str_islower.c
** File description:
** <description>
*/

#include "../../includes/str.h"

bool str_c_is_lower(cc_t c)
{
    if (('a' <= c && c <= 'z'))
        return true;
    return false;
}

bool str_is_lower(const cstr_t string)
{
    if (!string)
        return false;
    for (int idx = 0; string[idx] != '\0'; idx++)
        if (!str_c_is_lower(string[idx]))
            return false;
    return true;
}
