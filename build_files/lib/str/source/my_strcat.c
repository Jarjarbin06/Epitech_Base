/*
** EPITECH PROJECT, 2025
** my_strcat.c
** File description:
** None
*/

#include "../include/str.h"

char *my_strcat(char *dest, const char *src)
{
    const int dest_len = my_strlen(dest);
    const int src_len = my_strlen(src);

    if (!dest || !src)
        return NULL;
    for (int idx = 0; idx < src_len; idx++)
        dest[dest_len + idx] = src[idx];
    return dest;
}
