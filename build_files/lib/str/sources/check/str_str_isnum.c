/*
** EPITECH PROJECT, 2025
** sources - str_str_isnum.c
** File description:
** <description>
*/

#include "../../includes/str.h"

bool p_is_num(cc_t c)
{
    if (('0' <= c && c <= '9'))
        return true;
    return false;
}

bool str_is_num(const cstr_t str)
{
    if (!str)
        return false;
    for (int idx = 0; str[idx] != '\0'; idx++)
        if (!str_c_is_num(str[idx]))
            return false;
    return true;
}
