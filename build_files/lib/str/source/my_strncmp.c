/*
** EPITECH PROJECT, 2025
** my_strcmp.c
** File description:
** None
*/

#include "../include/str.h"

int my_strncmp(const char *str1, char const *str2, int n)
{
    const int s1_len = my_strlen(str1);
    const int s2_len = my_strlen(str2);

    if (!str1 || !str2)
        return (0);
    if (s1_len < s2_len)
        return 1;
    if (s1_len > s2_len)
        return -1;
    if (n > s1_len)
        n = s1_len;
    for (int idx = 0; idx < n; idx++)
        if (str1[idx] != str2[idx])
            return (1);
    return (0);
}
