/*
** EPITECH PROJECT, 2025
** sources - my_strlowcase.c
** File description:
** <description>
*/

#include "../includes/str.h"

char *my_strlowcase(char *str)
{
    const int str_len = p_strlen(str);

    if (!str)
        return NULL;
    for (int idx = 0; idx < str_len; idx++)
        if ('A' <= str[idx] && str[idx] <= 'Z')
            str[idx] = (char)((int)str[idx] + 32);
    return str;
}
