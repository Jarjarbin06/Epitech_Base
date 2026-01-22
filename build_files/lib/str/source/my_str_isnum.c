/*
** EPITECH PROJECT, 2025
** my_str_isalpha.c
** File description:
** None
*/

#include "../include/str.h"

bool is_num(const char c)
{
    if (('0' <= c && c <= '9'))
        return true;
    return false;
}

bool my_str_isnum(const char *str)
{
    if (!str)
        return false;
    for (int idx = 0; str[idx] != '\0'; idx++)
        if (!is_num(str[idx]))
            return false;
    return true;
}
