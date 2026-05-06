/*
** EPITECH PROJECT, 2026
** bsminishell - str_to_word_array.c
** File description:
** <description>
*/

#include "../../includes/str.h"

static unsigned int get_word_amount(const cstr_t string, cc_t separator)
{
    unsigned int word_amount = 1;

    if (str_len(string) == 0)
        return (0);
    for (int idx = 0; string[idx] != '\0'; idx++)
        if (string[idx] == separator)
            word_amount++;
    return (word_amount);
}

static int get_len_word(const cstr_t string, size_t idx, cc_t separator)
{
    int len = 0;

    for (; string[idx] != '\0' && string[idx] != separator; idx++)
        len++;
    return (len);
}

static size_t goto_next_word(const cstr_t string, size_t idx, cc_t separator)
{
    if (idx == 0 && string[idx] != ' ')
        return (idx);
    for (; string[idx] != '\0' && string[idx] != separator; idx++);
    for (; string[idx] != '\0' && string[idx] == separator; idx++);
    return (idx);
}

str_t *str_split(const cstr_t string, cc_t separator)
{
    const unsigned int word_amount = get_word_amount(string, separator);
    str_t *ret = malloc_any(sizeof(str_t ) * (word_amount + 1));
    size_t ret_idx = 0;

    if (!string || !ret || word_amount == 0)
        return ((auto_free(1, (free_t[]){{ret, &ret, free_any}})) ?
            (NULL) : ((void *)0));
    for (size_t idx = 0; idx < str_len(string); idx++) {
        idx = goto_next_word(string, idx, separator);
        ret[ret_idx] = str_ndup(&string[idx],
            get_len_word(string, idx, separator));
        if (!ret[ret_idx]) {
            free_array((void **)ret);
            return (NULL);
        }
        ret_idx++;
    }
    ret[word_amount] = NULL;
    return (ret);
}
