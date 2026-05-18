/*
** EPITECH PROJECT, 2025
** sources - str_strlen.c
** File description:
** <description>
*/

#include "../../includes/flag.h"

int str_len(const cstr_t string)
{
    int idx = 0;

    if (!string)
        return idx;
    for (; string[idx] != '\0'; idx++);
    return idx;
}
