/*
** EPITECH PROJECT, 2025
** my_strncat.c
** File description:
** None
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int n)
{
    int dest_len = my_strlen(dest);
    int src_len = my_strlen(src);
    int idx = 0;

    if (n > src_len)
        n = src_len;
    for (; idx < n; idx++)
        dest[dest_len + idx] = src[idx];
    return dest;
}
