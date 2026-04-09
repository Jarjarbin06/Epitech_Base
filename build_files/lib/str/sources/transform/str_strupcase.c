/*
** EPITECH PROJECT, 2025
** sources - str_strupcase.c
** File description:
** <description>
*/

#include "../../includes/str.h"

str_t str_upcase(str_t string)
{
    const int string_len = str_len(string);
    const int diff_upper_lower = 'a' - 'A';

    if (!string)
        return NULL;
    for (int idx = 0; idx < string_len; idx++)
        if (str_c_is_lower(string[idx]))
            string[idx] = (char)((int)string[idx] - diff_upper_lower);
    return string;
}
