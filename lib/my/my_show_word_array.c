/*
** EPITECH PROJECT, 2025
** my_show_word_array.c
** File description:
** None
*/

#include "my.h"

int my_show_word_array(char const **tab)
{
    int len = 0;

    for (; tab[len] != 0; len++);
    for (int idx = 0; idx < len; idx++) {
        my_putstr(tab[idx]);
        my_putchar('\n');
    }
    return 0;
}
