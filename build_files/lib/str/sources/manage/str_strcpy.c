/*
** EPITECH PROJECT, 2025
** sources - str_strcpy.c
** File description:
** <description>
*/

#include <stdlib.h>

#include "../../includes/str.h"

str_t str_cpy(str_t dest, const cstr_t src)
{
    const int len = str_len(src);

    if (!dest || !src) {
        if (dest)
            free(dest);
        return NULL;
    }
    for (int idx = 0; idx < len; idx++)
        dest[idx] = src[idx];
    dest[len] = '\0';
    return (dest);
}
