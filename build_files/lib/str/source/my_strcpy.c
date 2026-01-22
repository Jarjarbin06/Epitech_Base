/*
** EPITECH PROJECT, 2025
** my_strcpy.c
** File description:
** None
*/

#include "../include/str.h"

char *my_strcpy(char *dest, const char *src)
{
    const int len = my_strlen(src);

    if (!dest || !src)
        return NULL;
    for (int idx = 0; idx < len; idx++)
        dest[idx] = src[idx];
    return (dest);
}
