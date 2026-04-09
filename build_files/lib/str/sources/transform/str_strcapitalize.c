/*
** EPITECH PROJECT, 2025
** sources - str_strcapitalize.c
** File description:
** <description>
*/

#include "../../includes/str.h"

str_t str_capitalize(str_t string)
{
    const int string_len = str_len(string);
    int up_next = 1;
    const int diff_upper_lower = 'a' - 'A';

    if (!string)
        return NULL;
    for (int idx = 0; idx < string_len; idx++) {
        if (up_next && str_c_is_lower(string[idx]))
            string[idx] = (char)((int)string[idx] - diff_upper_lower);
        if (!up_next && str_c_is_upper(string[idx]))
            string[idx] = (char)((int)string[idx] + diff_upper_lower);
        up_next = 0;
        if (!str_c_is_alpha(string[idx]) && !str_c_is_num(string[idx]))
            up_next = 1;
    }
    return string;
}
