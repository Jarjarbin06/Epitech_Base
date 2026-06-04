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

static int fill_flags(flags_t *flags, const char *flag[2], const char *value)
{
    const flag_t *current = {};

    if (!flags || !flags->flags || (!flag[0] && !flag[1]))
        return E_ERROR;
    for (size_t idx = 0; idx < flags->size; idx++) {
        current = &flags->flags[idx];
        if (!current)
            return E_ERROR;
        if (current->simple && str_len(flag[0]) == 1 &&
                current->simple == flag[0][0])
            return set_flag(flags, idx, flag[0], value);
        if (current->advanced && str_len(flag[1]) > 1 &&
                !str_cmp(current->advanced, flag[1]))
            return set_flag(flags, idx, flag[1], value);
    }
    return E_ERROR;
}

static const char *get_flag(const char *flag)
{
    if (!flag)
        return NULL;
    if (str_len(flag) && flag[0] == '-')
        return &flag[1];
    return NULL;
}

static bool set_vars(const char **value, const char *flag[2],
    const char *const *argv, const size_t idx)
{
    flag[0] = get_flag(argv[idx]);
    flag[1] = get_flag(flag[0]);
    if (argv[idx + 1] && (str_len(argv[idx] + 1) && argv[idx + 1][0] != '-')) {
        *value = argv[idx + 1];
        return true;
    }
    return false;
}

static void reset_vars(const char **value, const char *flag[2])
{
    if (!flag || !value)
        return;
    flag[0] = NULL;
    flag[1] = NULL;
    *value = NULL;
}

int flag_load(flags_t *flags, const int argc, const char *const *argv)
{
    const char *value = NULL;
    const char *flag[2] = {NULL, NULL};

    if (!flags || !argv)
        return E_ERROR;
    for (size_t idx = 1; idx < (size_t)argc; idx++) {
        if (set_vars(&value, flag, argv, idx))
            idx++;
        if (!flag[0] && !flag[1])
            return E_ERROR;
        if (fill_flags(flags, flag, value))
            return E_ERROR;
        reset_vars(&value, flag);
    }
    return E_SUCCESS;
}
