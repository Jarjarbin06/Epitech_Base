/*
** EPITECH PROJECT, 2025
** sources - str_putchar.c
** File description:
** <description>
*/

#include <unistd.h>

#include "../../includes/str.h"

int str_put_char(cc_t c)
{
    return ((write(1, &c, 1) != 1) ?
        (E_ERROR) : (E_SUCCESS));
}
