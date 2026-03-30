/*
** EPITECH PROJECT, 2025
** sources - my_str_isalpha.c
** File description:
** <description>
*/

#include "str.h"

bool str_is_alpha(const char c)
{
    if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'))
        return true;
    return false;
}

bool str_str_isalpha(const char *str)
{
    if (!str)
        return false;
    for (int idx = 0; str[idx] != '\0'; idx++)
        if (!str_is_alpha(str[idx]))
            return false;
    return true;
}
