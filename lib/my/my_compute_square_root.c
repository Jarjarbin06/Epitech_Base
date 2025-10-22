/*
** EPITECH PROJECT, 2025
** my_compute_square_root.c
** File description:
** None
*/

#include "my.h"

int my_compute_square_root(int nb)
{
    if (nb == 0 || nb == 1)
        return (nb);
    for (int i = 2; i <= nb / 2; i++) {
        if (nb == i * i)
            return (i);
    }
    return (0);
}
