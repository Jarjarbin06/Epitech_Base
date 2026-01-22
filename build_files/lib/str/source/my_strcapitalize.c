/*
** EPITECH PROJECT, 2025
** source - my_strcapitalize.c
** File description:
** <description>
*/

#include "../include/str.h"

char *my_strcapitalize(char *str)
{
    const int str_len = my_strlen(str);
    int up_next = 1;

    for (int idx = 0; idx < str_len; idx++) {
        if (up_next && ('a' <= str[idx] && str[idx] <= 'z'))
            str[idx] = str[idx] - 32;
        if (!up_next && ('A' <= str[idx] && str[idx] <= 'Z'))
            str[idx] = str[idx] + 32;
        up_next = 0;
        if (!is_alpha(str[idx]) && !is_num(str[idx]))
            up_next = 1;
    }
    return str;
}
