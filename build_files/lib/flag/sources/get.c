/*
** EPITECH PROJECT, 2025
** sub_includes - file_typedef.h
** File description:
** <description>
*/

#include "../includes/flag.h"

const flag_t *flag_get(flags_t *flags, const char *flag)
{
    const flag_t *current_flag = NULL;

    if (!flags || !flag || !str_len(flag))
        return false;
    for (size_t idx = 0; idx < flags->size; idx++) {
        current_flag = &flags->flags[idx];
        if (!current_flag)
            return NULL;
        if (str_len(flag) == 1 && flag[0] == current_flag->simple)
            return current_flag;
        if (!str_cmp(flag, current_flag->advanced))
            return current_flag;
    }
    return false;
}

bool flag_get_active(flags_t *flags, const char *flag)
{
    const flag_t *current_flag = NULL;

    if (!flags || !flag || !str_len(flag))
        return false;
    for (size_t idx = 0; idx < flags->size; idx++) {
        current_flag = &flags->flags[idx];
        if (!current_flag)
            return false;
        if (str_len(flag) == 1 && flag[0] == current_flag->simple)
            return current_flag->active;
        if (!str_cmp(flag, current_flag->advanced))
            return current_flag->active;
    }
    return false;
}

const char *flag_get_value(flags_t *flags, const char *flag)
{
    const flag_t *current_flag = NULL;

    if (!flags || !flag || !str_len(flag))
        return NULL;
    for (size_t idx = 0; idx < flags->size; idx++) {
        current_flag = &flags->flags[idx];
        if (!current_flag)
            return NULL;
        if (str_len(flag) == 1 && flag[0] == current_flag->simple)
            return current_flag->value;
        if (!str_cmp(flag, current_flag->advanced))
            return current_flag->value;
    }
    return NULL;
}
