/*
** EPITECH PROJECT, 2025
** my_str_isalpha.c
** File description:
** None
*/

#include "my.h"

int is_lower(char const c)
{
    if (('a' <= c && c <= 'z'))
        return 1;
    return 0;
}

int my_str_islower(char const *str)
{
    for (int idx = 0; str[idx] != '\0'; idx++)
        if (!is_lower(str[idx]))
            return 0;
    return 1;
}
