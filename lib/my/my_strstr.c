/*
** EPITECH PROJECT, 2025
** my_strstr.c
** File description:
** None
*/

#include "my.h"

char *my_strstr(char *str, char const *to_find)
{
    int str_len = my_strlen(str);
    int to_find_len = my_strlen(to_find);
    int first = 0;
    int count_found = 0;
    int found = 0;

    for (int idx = 0; idx < str_len; idx++) {
        if (count_found == to_find_len)
            return (&str[first]);
        if (found && str[idx] == to_find[count_found])
            count_found = count_found + 1;
        if (!found && str[idx] == to_find[count_found])
            found = 0;
        if (!found && str[idx] == to_find[count_found]) {
            first = idx;
            found = 1;
            count_found = count_found + 1;
        }
    }
    return (&str[first]);
}
