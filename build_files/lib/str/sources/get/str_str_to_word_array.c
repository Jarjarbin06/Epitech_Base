/*
** EPITECH PROJECT, 2026
** bsminishell - str_to_word_array.c
** File description:
** <description>
*/

#include "../../includes/str.h"

static unsigned int get_word_amount(str_t str, char separator)
{
    unsigned int word_amount = 1;

    if (str_len(str) == 0)
        return (0);
    for (int idx = 0; str[idx] != '\0'; idx++)
        if (str[idx] == separator)
            word_amount++;
    return (word_amount);
}

static int get_len_word(str_t str, int idx, char separator)
{
    int len = 0;

    for (; str[idx] != '\0' && str[idx] != separator; idx++)
        len++;
    return (len);
}

static int goto_next_word(str_t str, int idx, char separator)
{
    if (idx == 0 && str[idx] != ' ')
        return (idx);
    for (; str[idx] != '\0' && str[idx] != separator; idx++);
    for (; str[idx] != '\0' && str[idx] == separator; idx++);
    return (idx);
}

str_t *str_to_word_array(str_t str, char separator)
{
    const unsigned int word_amount = get_word_amount(str, separator);
    str_t *ret = malloc_any(sizeof(str_t ) * (word_amount + 1));
    int ret_idx = 0;

    if (!str || !ret || word_amount == 0)
        return ((auto_free(1, (free_t[]){{ret, &ret, free_any}})) ?
            (NULL) : ((void *)0));
    for (int idx = 0; idx < str_len(str); idx++) {
        idx = goto_next_word(str, idx, separator);
        ret[ret_idx] = str_ndup(&str[idx],
            get_len_word(str, idx, separator));
        if (!ret[ret_idx]) {
            free_array((void **)ret);
            return (NULL);
        }
        ret_idx++;
    }
    ret[word_amount] = NULL;
    return (ret);
}
