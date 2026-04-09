/*
** EPITECH PROJECT, 2025
** sources - str_strlen.c
** File description:
** <description>
*/

#include "../../includes/str.h"

int str_len(str_t str)
{
    int idx = 0;

    if (!str)
        return idx;
    for (; str[idx] != '\0'; idx++);
    return idx;
}
