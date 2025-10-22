/*
** EPITECH PROJECT, 2025
** my_strncpy.c
** File description:
** None
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int len = my_strlen(src);

    if (n > len)
        n = len;
    for (int idx = 0; idx < n; idx++)
        dest[idx] = src[idx];
    return (dest);
}
