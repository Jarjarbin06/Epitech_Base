/*
** EPITECH PROJECT, 2025
** my_strsup.c
** File description:
** None
*/

#include <stdlib.h>
#include <stddef.h>
#include "my.h"

char *my_strdup(char const *src)
{
    int i = 0;
    char *dest = NULL;

    for (; src[i] != '\0'; i++);
    dest = malloc(i + 1);
    for (int n = 0; n < i; n++)
        dest[n] = src[n];
    dest[i] = '\0';
    return dest;
}
