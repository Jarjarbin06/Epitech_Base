/*
** EPITECH PROJECT, 2025
** my_strcpy.c
** File description:
** None
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    int len = my_strlen(src);

    for (int idx = 0; idx < len; idx++)
        dest[idx] = src[idx];
    return (dest);
}
