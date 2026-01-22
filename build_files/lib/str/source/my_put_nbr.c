/*
** EPITECH PROJECT, 2025
** my_put_nbr.c
** File description:
** None
*/

#include <unistd.h>

#include "../include/str.h"

int my_put_nbr(const int nb)
{
    int c1 = nb;
    int c2 = 0;
    const char neg = '-';

    if (c1 < 0) {
        c1 *= -1;
        write(1, &neg, 1);
    }
    if (c1 >= 1) {
        c2 = (c1 % 10) + 48;
        c1 = c1 / 10;
        my_put_nbr(c1);
        write(1, &c2, 1);
    }
    return EXIT_SUCCESS;
}
