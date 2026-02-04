/*
** EPITECH PROJECT, 2025
** sources - my_put_nbr.c
** File description:
** <description>
*/

#include <unistd.h>

#include "../include/str.h"

static void do_put_nbr(const int nbr)
{
    int c1 = nbr;
    int c2 = 0;
    const char neg = '-';

    if (c1 < 0) {
        c1 *= -1;
        write(1, &neg, 1);
    }
    if (c1 > 0) {
        c2 = (c1 % 10) + 48;
        c1 = c1 / 10;
        do_put_nbr(c1);
        write(1, &c2, 1);
    }
}

void my_put_nbr(const int nbr)
{
    if (nbr == 0)
        write(1, "0", 1);
    else
        do_put_nbr(nbr);
}
