/*
** EPITECH PROJECT, 2025
** sub_includes - file_typedef.h
** File description:
** <description>
*/

#include "../includes/flag.h"

int flag_add(flags_t *flags, const flag_set_t flag_set[])
{
    if (!flags || !flag_set || flags->size >= flags->max_size)
        return E_ERROR;
    flags->flags[flags->size] = (flag_t){
        .name = str_dup(flag_set->name),
        .simple = flag_set->simple,
        .advanced = str_dup(flag_set->advanced),
        .active = false,
        .need_value = flag_set->need_value,
        .value = str_dup(flag_set->base_value),
        .is_loaded = false
    };
    flags->size++;
    return E_SUCCESS;
}

int flag_add_batch(flags_t *flags, const size_t len,
    const flag_set_t flag_set[])
{
    if (!flags || !flag_set)
        return E_ERROR;
    for (size_t idx = 0; idx < len; idx++)
        if (flag_add(flags, &flag_set[idx]))
            return E_ERROR;
    return E_SUCCESS;
}
