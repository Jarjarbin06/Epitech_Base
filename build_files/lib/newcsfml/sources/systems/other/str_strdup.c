/*
** EPITECH PROJECT, 2025
** sources - str_strdup.c
** File description:
** <description>
*/

#include "newcsfml/systems/other.h"

str_t str_dup(const cstr_t src)
{
    const int len = str_len(src);
    str_t dest = NULL;

    if (!src)
        return NULL;
    dest = malloc_any(sizeof(char) * (len + 1));
    for (int idx = 0; idx < len; idx++)
        dest[idx] = src[idx];
    dest[len] = '\0';
    return dest;
}
