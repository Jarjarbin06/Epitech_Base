/*
** EPITECH PROJECT, 2025
** sub_includes - file_typedef.h
** File description:
** <description>
*/

#include "../includes/flag.h"

static int set_flag(flags_t *flags, const size_t idx, const char *flag,
    const char *value)
{
    flag_t *current_flag = NULL;

    if (!flags || !flags->flags || !flag)
        return E_ERROR;
    current_flag = &flags->flags[idx];
    if (!current_flag)
        return E_ERROR;
    current_flag->active = true;
    if (current_flag->need_value) {
        if (!value)
            return E_ERROR;
        free_any(current_flag->value);
        current_flag->value = str_dup(value);
    }
    if (!current_flag->is_loaded)
        flags->loaded++;
    current_flag->is_loaded = true;
    return E_SUCCESS;
}

static int fill_flags(flags_t *flags, const char *flag, const char *value)
{
    flag_t *current_flag = {};

    if (!flags || !flags->flags || !flag)
        return E_ERROR;
    for (size_t idx = 0; idx < flags->size; idx++) {
        current_flag = &flags->flags[idx];
        if (!current_flag)
            return E_ERROR;
        if ((current_flag->simple &&
                str_len(flag) == 1 && current_flag->simple == flag[0]) ||
            (current_flag->advanced &&
                str_len(flag) > 1 && !str_cmp(current_flag->advanced, flag)))
            return set_flag(flags, idx, flag, value);
    }
    return E_ERROR;
}

static const char *get_flag(const char *flag)
{
    if (!flag)
        return NULL;
    if (str_len(flag) && flag[0] == '-')
        flag = &flag[1];
    if (str_len(flag) && flag[0] == '-')
        flag = &flag[1];
    return flag;
}

int flag_load(flags_t *flags, const int argc, const char *const *argv)
{
    const char *value = NULL;
    const char *flag = NULL;

    if (!flags || !argv)
        return E_ERROR;
    for (size_t idx = 1; idx < (size_t)argc; idx++) {
        flag = get_flag(argv[idx]);
        if (!flag)
            return E_ERROR;
        if ((idx + 1) < (size_t)argc &&
            (str_len(argv[idx]) && argv[idx + 1][0] != '-')) {
            value = argv[idx + 1];
            idx++;
        }
        if (fill_flags(flags, flag, value))
            return E_ERROR;
        flag = NULL;
        value = NULL;
    }
    return E_SUCCESS;
}
