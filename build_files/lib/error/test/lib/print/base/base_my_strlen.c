/*
** EPITECH PROJECT, 2025
** my_printf.c
** File description:
** None
*/

#include "../includes/print.h"

int p_strlen(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return (i);
}
