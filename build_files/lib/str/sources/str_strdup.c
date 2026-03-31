/*
** EPITECH PROJECT, 2025
** sources - str_strdup.c
** File description:
** <description>
*/

#include <stdlib.h>

#include "../includes/str.h"

char *str_strdup(const char *src)
{
    const int len = str_strlen(src);
    char *dest = NULL;

    if (!src)
        return NULL;
    dest = (char *)malloc_any(sizeof(char) * (len + 1));
    for (int idx = 0; idx < len; idx++)
        dest[idx] = src[idx];
    dest[len] = '\0';
    return dest;
}
