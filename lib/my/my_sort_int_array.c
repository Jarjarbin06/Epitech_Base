/*
** EPITECH PROJECT, 2025
** my_showstr.c
** File description:
** None
*/

#include "my.h"

static int get_biggest(int *tab, int last_idx)
{
    int idx_max = 0;

    for (int idx = 0; idx < last_idx; idx++)
        if (tab[idx] > tab[idx_max])
            idx_max = idx;
    return idx_max;
}

void my_sort_int_array(int *tab, int size)
{
    for (int idx = (size - 1); idx >= 0; idx--)
        my_swap(&tab[get_biggest(tab, (idx + 1))], &tab[idx]);
}
