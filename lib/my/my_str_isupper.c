/*
** EPITECH PROJECT, 2025
** my_str_isalpha.c
** File description:
** None
*/

#include "my.h"

int is_upper(char const c)
{
    if (('A' <= c && c <= 'Z'))
        return 1;
    return 0;
}

int my_str_isupper(char const *str)
{
    for (int idx = 0; str[idx] != '\0'; idx++)
        if (!is_upper(str[idx]))
            return 0;
    return 1;
}
