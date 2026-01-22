/*
** EPITECH PROJECT, 2025
** source - my_strupcase.c
** File description:
** <description>
*/

#include "../include/str.h"

char *my_strupcase(char *str)
{
    const int str_len = my_strlen(str);

    if (!str)
        return NULL;
    for (int idx = 0; idx < str_len; idx++)
        str[idx] = (char)((int)str[idx] - 32);
    return str;
}
