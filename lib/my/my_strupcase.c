/*
** EPITECH PROJECT, 2025
** my_strupcase.c
** File description:
** None
*/

#include "my.h"

char *my_strupcase(char *str)
{
    int str_len = my_strlen(str);

    for (int idx = 0; idx < str_len; idx++)
        str[idx] = str[idx] - 32;
    return str;
}
