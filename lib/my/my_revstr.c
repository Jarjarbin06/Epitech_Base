/*
** EPITECH PROJECT, 2025
** my_revstr.c
** File description:
** None
*/

#include "my.h"

char *my_revstr(char *str)
{
    int n = 0;
    int l = my_strlen(str);

    for (int i = (l - 1); i > n; i--) {
        my_swap_char(&str[i], &str[n]);
        n = n + 1;
    }
    return (str);
}
