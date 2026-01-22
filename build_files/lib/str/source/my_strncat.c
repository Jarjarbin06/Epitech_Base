/*
** EPITECH PROJECT, 2025
** source - my_strncat.c
** File description:
** <description>
*/

#include "../include/str.h"

char *my_strncat(char *dest, const char *src, int n)
{
    const int dest_len = my_strlen(dest);
    const int src_len = my_strlen(src);

    if (!dest || !src)
        return NULL;
    if (n > src_len)
        n = src_len;
    for (int idx = 0; idx < n; idx++)
        dest[dest_len + idx] = src[idx];
    return dest;
}
