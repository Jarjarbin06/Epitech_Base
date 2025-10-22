/*
** EPITECH PROJECT, 2025
** my_strcmp.c
** File description:
** None
*/

#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int s1_len = my_strlen(s1);
    int s2_len = my_strlen(s2);

    if (s1_len < s2_len)
        return 1;
    if (s1_len > s2_len)
        return -1;
    if (n > s1_len)
        n = s1_len;
    for (int idx = 0; idx < n; idx++)
        if (s1[idx] != s2[idx])
            return (1);
    return (0);
}
