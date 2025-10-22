/*
** EPITECH PROJECT, 2025
** my_putstr.c
** File description:
** None
*/

#include "my.h"
#include <unistd.h>

int my_putstr(char const *str)
{
    int i;

    i = 0;
    while (str[i] != *"\0") {
        write(1, &str[i], 1);
        i = i + 1;
    }
    return EXIT_SUCCESS;
}
