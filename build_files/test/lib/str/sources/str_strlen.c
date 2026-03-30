/*
** EPITECH PROJECT, 2025
** sources - str_strlen.c
** File description:
** <description>
*/

#include "str.h"

int p_strlen(const char *str)
{
    int idx = 0;

    if (!str)
        return idx;
    for (; str[idx] != '\0'; idx++);
    return (idx);
}
