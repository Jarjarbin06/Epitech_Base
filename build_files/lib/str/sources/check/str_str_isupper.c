/*
** EPITECH PROJECT, 2025
** sources - str_str_isupper.c
** File description:
** <description>
*/

#include "../../includes/str.h"

bool str_c_is_upper(char c)
{
    if (('A' <= c && c <= 'Z'))
        return true;
    return false;
}

bool str_is_upper(str_t str)
{
    if (!str)
        return false;
    for (int idx = 0; str[idx] != '\0'; idx++)
        if (!str_c_is_upper(str[idx]))
            return false;
    return true;
}
