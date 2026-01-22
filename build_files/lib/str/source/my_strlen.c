/*
** EPITECH PROJECT, 2025
** my_strlen.c
** File description:
** None
*/

#include "../include/str.h"

int my_strlen(const char *str)
{
    int idx = 0;

    if (!str)
        return idx;
    for (; str[idx] != '\0'; idx++);
    return (idx);
}
