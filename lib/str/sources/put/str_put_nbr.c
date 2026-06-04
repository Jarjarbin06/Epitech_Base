/*
** EPITECH PROJECT, 2025
** sources - str_put_nbr.c
** File description:
** <description>
*/

#include <unistd.h>

#include "../../includes/str.h"

static void do_put_nbr(const int nbr)
{
    int c1 = nbr;
    int c2 = 0;

    if (c1 < 0) {
        c1 *= -1;
        str_put_char('-');
    }
    if (c1 > 0) {
        c2 = (c1 % 10) + '0';
        c1 = c1 / 10;
        do_put_nbr(c1);
        str_put_char((char)c2);
    }
}

void str_put_nbr(const int nbr)
{
    if (nbr == 0)
        write(1, "0", 1);
    else
        do_put_nbr(nbr);
}
