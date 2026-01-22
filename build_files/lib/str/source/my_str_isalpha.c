/*
** EPITECH PROJECT, 2025
** my_str_isalpha.c
** File description:
** None
*/

#include "../include/str.h"

bool is_alpha(const char c)
{
    if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'))
        return true;
    return false;
}

bool my_str_isalpha(const char *str)
{
    if (!str)
        return false;
    for (int idx = 0; str[idx] != '\0'; idx++)
        if (!is_alpha(str[idx]))
            return false;
    return true;
}
