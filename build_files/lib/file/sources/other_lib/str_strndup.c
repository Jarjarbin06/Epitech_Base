/*
** EPITECH PROJECT, 2026
** bsminishell - str_strndup.c
** File description:
** <description>
*/

#include "../../includes/file.h"

str_t str_ndup(const cstr_t src, const int n)
{
    int len = str_len(src);
    str_t dest = NULL;

    len = ((n < len) ? (n) : (len));
    if (!src)
        return NULL;
    dest = malloc_any(sizeof(char) * (len + 1));
    for (int idx = 0; idx < len; idx++)
        dest[idx] = src[idx];
    dest[len] = '\0';
    return dest;
}
