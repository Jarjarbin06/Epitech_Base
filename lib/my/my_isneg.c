/*
** EPITECH PROJECT, 2025
** my_isneg.c
** File description:
** test
*/

#include <unistd.h>
#include "my.h"

int my_isneg(int n)
{
    const int char_N = 78;
    const int char_P = 80;

    if (n < 0) {
        write(1, &char_N, 1);
    } else {
        write(1, &char_P, 1);
    }
    write(1, "\n", 1);
    return (0);
}
