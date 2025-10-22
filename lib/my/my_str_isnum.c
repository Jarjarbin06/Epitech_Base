/*
** EPITECH PROJECT, 2025
** my_str_isalpha.c
** File description:
** None
*/

#include "my.h"

int is_num(char const c)
{
    if (('0' <= c && c <= '9'))
        return 1;
    return 0;
}

int my_str_isnum(char const *str)
{
    for (int idx = 0; str[idx] != '\0'; idx++)
        if (!is_num(str[idx]))
            return 0;
    return 1;
}
