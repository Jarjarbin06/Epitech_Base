/*
** EPITECH PROJECT, 2025
** my_is_prime.c
** File description:
** None
*/

#include "my.h"

int my_is_prime(int nb)
{
    if (nb < 0)
        nb = nb * -1;
    if (nb == 0 || nb == 1)
        return (0);
    for (int i = 2; i <= nb / 2; i++) {
        if (nb % i == 0)
            return (0);
    }
    return (1);
}
