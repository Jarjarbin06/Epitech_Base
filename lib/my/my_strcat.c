/*
** EPITECH PROJECT, 2025
** my_strcat.c
** File description:
** None
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int dest_len = my_strlen(dest);
    int src_len = my_strlen(src);
    int idx = 0;

    for (; idx < src_len; idx++)
        dest[dest_len + idx] = src[idx];
    return dest;
}
