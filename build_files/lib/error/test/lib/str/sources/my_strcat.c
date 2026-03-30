/*
** EPITECH PROJECT, 2025
** sources - my_strcat.c
** File description:
** <description>
*/

#include <stdlib.h>

#include "../includes/str.h"

char *my_strcat(char *src_1, const char *src_2)
{
    const int src_1_len = p_strlen(src_1);
    const int src_2_len = p_strlen(src_2);
    char *dest = NULL;

    if (!src_1 || !src_2)
        return NULL;
    dest = (char *)malloc_any(src_1_len + src_2_len + 1);
    if (!dest)
        return NULL;
    for (int idx = 0; idx < src_1_len; idx++)
        dest[idx] = src_1[idx];
    for (int idx = 0; idx < src_2_len; idx++)
        dest[src_1_len + idx] = src_2[idx];
    dest[src_1_len + src_2_len] = '\0';
    return dest;
}
