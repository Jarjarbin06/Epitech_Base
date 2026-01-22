/*
** EPITECH PROJECT, 2025
** source - my_str_isupper.c
** File description:
** <description>
*/

#include "../include/str.h"

bool is_upper(const char c)
{
    if (('A' <= c && c <= 'Z'))
        return true;
    return false;
}

bool my_str_isupper(const char *str)
{
    if (!str)
        return false;
    for (int idx = 0; str[idx] != '\0'; idx++)
        if (!is_upper(str[idx]))
            return false;
    return true;
}
