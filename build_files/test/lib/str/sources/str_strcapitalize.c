/*
** EPITECH PROJECT, 2025
** sources - str_strcapitalize.c
** File description:
** <description>
*/

#include "str.h"

char *str_strcapitalize(char *str)
{
    const int str_len = str_strlen(str);
    int up_next = 1;

    if (!str)
        return NULL;
    for (int idx = 0; idx < str_len; idx++) {
        if (up_next && ('a' <= str[idx] && str[idx] <= 'z'))
            str[idx] = str[idx] - 32;
        if (!up_next && ('A' <= str[idx] && str[idx] <= 'Z'))
            str[idx] = str[idx] + 32;
        up_next = 0;
        if (!str_is_alpha(str[idx]) && !str_is_num(str[idx]))
            up_next = 1;
    }
    return str;
}
