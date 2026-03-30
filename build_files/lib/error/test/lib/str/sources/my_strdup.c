/*
** EPITECH PROJECT, 2025
** sources - my_strdup.c
** File description:
** <description>
*/

#include <stdlib.h>

#include "../includes/str.h"

char *my_strdup(const char *src)
{
    const int len = p_strlen(src);
    char *dest = NULL;

    if (!src)
        return NULL;
    dest = (char *)malloc_any(sizeof(char) * (len + 1));
    for (int idx = 0; idx < len; idx++)
        dest[idx] = src[idx];
    dest[len] = '\0';
    return dest;
}
