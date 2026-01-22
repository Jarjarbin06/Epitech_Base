/*
** EPITECH PROJECT, 2025
** my_strcmp.c
** File description:
** None
*/

#include "../include/str.h"

int my_strcmp(const char *str1, const char *str2)
{
    const int str1_len = my_strlen(str1);
    const int str2_len = my_strlen(str2);

    if (!str1 || !str2)
        return 1;
    if (str1_len < str2_len)
        return -1;
    if (str1_len > str2_len)
        return 1;
    for (int idx = 0; idx < str1_len; idx++)
        if (str1[idx] != str2[idx])
            return (1);
    return (0);
}
