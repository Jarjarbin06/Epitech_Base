/*
** EPITECH PROJECT, 2025
** sources - my_str_isnum.c
** File description:
** <description>
*/

#include "str.h"

bool p_is_num(const char c)
{
    if (('0' <= c && c <= '9'))
        return true;
    return false;
}

bool str_str_isnum(const char *str)
{
    if (!str)
        return false;
    for (int idx = 0; str[idx] != '\0'; idx++)
        if (!p_is_num(str[idx]))
            return false;
    return true;
}
