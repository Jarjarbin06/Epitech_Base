/*
** EPITECH PROJECT, 2025
** my_find_prime_sup.c
** File description:
** None
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    int n = nb;

    if (nb < 0)
        return (2);
    while (1) {
        if (my_is_prime(n))
            return (n);
        n = n + 1;
    }
}
