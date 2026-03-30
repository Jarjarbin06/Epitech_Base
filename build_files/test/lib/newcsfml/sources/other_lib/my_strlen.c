/*
** EPITECH PROJECT, 2025
** sources - my_strlen.c
** File description:
** <description>
*/

#include "newcsfml.h"

int p_strlen(const char *str)
{
    int idx = 0;

    if (!str)
        return idx;
    for (; str[idx] != '\0'; idx++);
    return (idx);
}
