/*
** EPITECH PROJECT, 2025
** sources - str_strlen.c
** File description:
** <description>
*/

#include "../../includes/str.h"

size_t str_len(const cstr_t string)
{
    size_t idx = 0;

    if (!string)
        return idx;
    for (; string[idx] != '\0'; idx++);
    return idx;
}
