/*
** EPITECH PROJECT, 2025
** my_strlowcase.c
** File description:
** None
*/

#include "my.h"

char *my_strlowcase(char *str)
{
    int str_len = my_strlen(str);

    for (int idx = 0; idx < str_len; idx++)
        if ('A' <= str[idx] && str[idx] <= 'Z')
            str[idx] = str[idx] + 32;
    return str;
}
