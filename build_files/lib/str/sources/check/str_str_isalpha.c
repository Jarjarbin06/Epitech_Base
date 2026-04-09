/*
** EPITECH PROJECT, 2025
** sources - str_str_isalpha.c
** File description:
** <description>
*/

#include "../../includes/str.h"

bool str_c_is_alpha(char c)
{
    if (str_c_is_lower(c) || str_c_is_upper(c))
        return true;
    return false;
}

bool str_is_alpha(str_t str)
{
    if (!str)
        return false;
    for (int idx = 0; str[idx] != '\0'; idx++)
        if (!str_c_is_alpha(str[idx]))
            return false;
    return true;
}
