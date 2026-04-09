/*
** EPITECH PROJECT, 2025
** sources - str_revstr.c
** File description:
** <description>
*/

#include "../../includes/str.h"

str_t str_reverse(str_t string)
{
    int n = 0;
    const int len = str_len(string);

    if (!string)
        return NULL;
    for (int i = (len - 1); i > n; i--) {
        str_c_swap(&string[i], &string[n]);
        n = n + 1;
    }
    return (string);
}
