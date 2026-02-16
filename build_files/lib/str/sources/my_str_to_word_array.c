/*
** EPITECH PROJECT, 2026
** bsminishell - str_to_word_array.c
** File description:
** <description>
*/

#include "../includes/str.h"

static unsigned int get_word_amount(const char *str)
{
    unsigned int word_amount = 1;

    if (my_strlen(str) == 0)
        return (0);
    for (int idx = 0; str[idx] != '\0'; idx++)
        if (str[idx] == ' ')
            word_amount++;
    return (word_amount);
}

static int get_len_word(const char *str, int idx)
{
    int len = 0;
    for (; str[idx] != '\0' && str[idx] != ' '; idx++, len++);
    return (len);
}

static int goto_next_word(const char *str, int idx)
{
    if (idx == 0 && str[idx] != ' ')
        return (idx);
    for (; str[idx] != '\0' && str[idx] != ' '; idx++);
    for (; str[idx] != '\0' && str[idx] == ' '; idx++);
    return (idx);
}

char **my_str_to_word_array(const char *str)
{
    const unsigned int word_amount = get_word_amount(str);
    char **ret = malloc_any(sizeof(char *) * (word_amount + 1));
    int ret_idx = 0;

    if (!ret || word_amount == 0)
        return ((auto_free(1, (free_t[]){{ret, &ret, free_any}})) ?
            (NULL) : (NULL));
    for (int idx = 0; idx < my_strlen(str); idx++) {
        idx = goto_next_word(str, idx);
        ret[ret_idx] = my_strndup(&str[idx], get_len_word(str, idx));
        if (!ret[ret_idx]) {
            free_array((void **)ret);
            return (NULL);
        }
        ret_idx++;
    }
    ret[word_amount] = NULL;
    return (ret);
}
