/*
** EPITECH PROJECT, 2025
** sources - str_strcmp.c
** File description:
** <description>
*/

#include "../../includes/str.h"

int str_cmp(str_t str1, str_t str2)
{
    const int str1_len = str_len(str1);
    const int str2_len = str_len(str2);

    if (!str1 || !str2)
        return 1;
    if (str1_len < str2_len)
        return -1;
    if (str1_len > str2_len)
        return 1;
    for (int idx = 0; idx < str1_len; idx++)
        if (str1[idx] != str2[idx])
            return 1;
    return 0;
}
