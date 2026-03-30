/*
** EPITECH PROJECT, 2026
** bsminishell - str_strndup.c
** File description:
** <description>
*/

#include <stdlib.h>

#include "str.h"

char *str_strndup(const char *src, const int n)
{
    int len = str_strlen(src);
    char *dest = NULL;

    len = ((n < len) ? (n) : (len));
    if (!src)
        return NULL;
    dest = (char *)malloc_any(sizeof(char) * (len + 1));
    for (int idx = 0; idx < len; idx++)
        dest[idx] = src[idx];
    dest[len] = '\0';
    return dest;
}
