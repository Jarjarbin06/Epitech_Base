/*
** EPITECH PROJECT, 2025
** sources - my_strupcase.c
** File description:
** <description>
*/

#include "../includes/str.h"

char *my_strupcase(char *str)
{
    const int str_len = p_strlen(str);

    if (!str)
        return NULL;
    for (int idx = 0; idx < str_len; idx++)
        if ('a' <= str[idx] && str[idx] <= 'z')
            str[idx] = (char)((int)str[idx] - 32);
    return str;
}
