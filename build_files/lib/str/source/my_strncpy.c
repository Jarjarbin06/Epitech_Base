/*
** EPITECH PROJECT, 2025
** my_strncpy.c
** File description:
** None
*/

#include "../include/str.h"

char *my_strncpy(char *dest, const char *src, int n)
{
    const int len = my_strlen(src);

    if (!dest || !src)
        return NULL;
    if (n > len)
        n = len;
    for (int idx = 0; idx < n; idx++)
        dest[idx] = src[idx];
    return (dest);
}
