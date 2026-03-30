/*
** EPITECH PROJECT, 2025
** sources - my_str_isupper.c
** File description:
** <description>
*/

#include "str.h"

bool str_is_upper(const char c)
{
    if (('A' <= c && c <= 'Z'))
        return true;
    return false;
}

bool str_str_isupper(const char *str)
{
    if (!str)
        return false;
    for (int idx = 0; str[idx] != '\0'; idx++)
        if (!str_is_upper(str[idx]))
            return false;
    return true;
}
