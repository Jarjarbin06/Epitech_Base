/*
** EPITECH PROJECT, 2025
** my_str_isalpha.c
** File description:
** None
*/

#include "my.h"

int is_alpha(char const c)
{
    if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'))
        return 1;
    return 0;
}

int my_str_isalpha(char const *str)
{
    for (int idx = 0; str[idx] != '\0'; idx++)
        if (!is_alpha(str[idx]))
            return 0;
    return 1;
}
