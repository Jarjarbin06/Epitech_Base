/*
** EPITECH PROJECT, 2025
** sources - my_revstr.c
** File description:
** <description>
*/

#include "../include/str.h"

char *my_revstr(char *str)
{
    int n = 0;
    const int len = my_strlen(str);

    if (!str)
        return NULL;
    for (int i = (len - 1); i > n; i--) {
        my_swap_char(&str[i], &str[n]);
        n = n + 1;
    }
    return (str);
}
