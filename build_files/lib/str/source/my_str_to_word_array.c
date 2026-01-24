/*
** EPITECH PROJECT, 2025
** source - my_str_to_word_array.c
** File description:
** <description>
*/

#include <stdlib.h>

#include "../include/str.h"

static int get_first_word_len(const char *str, int idx)
{
    if (!str)
        return -1;
    for (;str[idx] != '\0'; idx++)
        if (!is_alpha(str[idx]))
            return (idx);
    return idx;
}

static bool switch_alpha(const char *str, const int idx)
{
    if (!str)
        return false;
    return is_alpha(str[idx]);
}

static int get_word_count(const char *str)
{
    int is_word = 0;
    int word_count = 0;
    int idx_word = 0;

    if (!str)
        return -1;
    for (int idx = 0; idx < my_strlen(str); idx++) {
        if (is_alpha(str[idx]))
            is_word = switch_alpha(str, idx);
        idx_word = idx;
        for (; ((idx_word < my_strlen(str)) && is_word); idx_word++) {
            is_word = switch_alpha(str, idx);
            idx++;
        }
        word_count += 1;
    }
    return word_count;
}

static int malloc_word_size(const char *str, const int idx_diff)
{
    if (!str)
        return -1;
    return ((int)sizeof(char) * (get_first_word_len(str, idx_diff)));
}

static bool cmp_idx_len(const char *str, const int idx, const int idx_diff)
{
    if (!str)
        return false;
    return (idx < get_first_word_len(str, idx_diff));
}

static bool cmp_idxs_len(const char *str, const int idx, const int idx_diff) {
    if (!str)
        return false;
    return (idx + idx_diff < my_strlen(str));
}

static bool cmp_all(const char *str, const int idx, const int idx_diff)
{
    int is_true = true;

    if (!str)
        return false;
    if (!(cmp_idx_len(str, idx, idx_diff)))
        is_true = false;
    if (!(cmp_idxs_len(str, idx, idx_diff)))
        is_true = false;
    if (get_first_word_len(str, idx_diff) != 0)
        is_true = false;
    return (is_true);
}

char **my_str_to_word_array(const char *str)
{
    const int word_count = get_word_count(str);
    char **arr = malloc(sizeof(char *) * (word_count + 1));
    int idx_diff = 0;
    int idx = 0;
    int arr_idx = 0;

    for (; arr_idx < word_count; arr_idx++) {
        idx = 0;
        arr[arr_idx] = malloc(malloc_word_size(str, idx_diff));
        for (; cmp_all(str, idx, idx_diff); idx++)
            arr[arr_idx][idx] = str[idx + idx_diff];
        if (get_first_word_len(str, idx_diff) == idx)
            idx += 1;
        idx_diff += idx;
    }
    arr[arr_idx] = 0;
    return arr;
}
