/*
** EPITECH PROJECT, 2025
** source - my_strdup.c
** File description:
** <description>
*/

#include <stdlib.h>

#include "../include/str.h"

char *my_strdup(const char *src)
{
    int idx = 0;
    char *dest = NULL;

    if (!src)
        return NULL;
    for (; src[idx] != '\0'; idx++);
    dest = malloc(idx + 1);
    for (int n = 0; n < idx; n++)
        dest[n] = src[n];
    dest[idx] = '\0';
    return dest;
}
