/*
** EPITECH PROJECT, 2025
** sources - str_revstr.c
** File description:
** <description>
*/

#include "../includes/str.h"

char *str_revstr(char *str)
{
    int n = 0;
    const int len = str_strlen(str);

    if (!str)
        return NULL;
    for (int i = (len - 1); i > n; i--) {
        str_swap_char(&str[i], &str[n]);
        n = n + 1;
    }
    return (str);
}
