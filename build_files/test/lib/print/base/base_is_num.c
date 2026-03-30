/*
** EPITECH PROJECT, 2025
** my_printf.c
** File description:
** None
*/

#include <stdarg.h>
#include "print.h"

bool p_is_num(char const c)
{
    return (bool)('0' <= c && c <= '9');
}
