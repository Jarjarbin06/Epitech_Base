/*
** EPITECH PROJECT, 2025
** my_str_to_word_array.c
** File description:
** None
*/

#include <stdlib.h>
#include "my.h"

static int get_first_word_len(char const *str, int idx)
{
    int i;

    i = idx;
    while (str[i] != '\0') {
        if (!is_alpha(str[i]))
            return (i);
        i = i + 1;
    }
    return (i);
}

static int switch_alpha(char const *str, int idx)
{
    return is_alpha(str[idx]);
}

static int get_word_count(char const *str)
{
    int is_word = 0;
    int word_count = 0;
    int idx_word = 0;

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

static int malloc_word_size(char const *str, int idx_diff)
{
    return (sizeof(char) * (get_first_word_len(str, idx_diff)));
}

static int cmp_idx_len(char const *str, int idx, int idx_diff)
{
    return (idx < get_first_word_len(str, idx_diff));
}

static int cmp_idxs_len(char const *str, int idx, int idx_diff)
{
    return (idx + idx_diff < my_strlen(str));
}

static int cmp_len(char const *str, int idx_diff)
{
    return (get_first_word_len(str, idx_diff) != 0);
}

static int cmp_all(char const *str, int idx, int idx_diff)
{
    int is_true = 1;

    if (!(cmp_idx_len(str, idx, idx_diff)))
        is_true = 0;
    if (!(cmp_idxs_len(str, idx, idx_diff)))
        is_true = 0;
    if (!cmp_len(str, idx_diff))
        is_true = 0;
    return (is_true);
}

char **my_str_to_word_array(char const *str)
{
    int word_count = get_word_count(str);
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
