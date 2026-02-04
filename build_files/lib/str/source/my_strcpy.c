/*
** EPITECH PROJECT, 2025
** sources - my_strcpy.c
** File description:
** <description>
*/

#include <stdlib.h>

#include "../include/str.h"

char *my_strcpy(char *dest, const char *src)
{
    const int len = my_strlen(src);

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
