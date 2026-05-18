/*
** EPITECH PROJECT, 2025
** sub_includes - file_typedef.h
** File description:
** <description>
*/

#include "../includes/flag.h"

flags_t *flag_create(const size_t size)
{
    flags_t *flags = malloc_any(sizeof(flags_t));
    flag_t *flag_list = malloc_any(sizeof(flag_t) * size);

    if (!flags || !flag_list)
        return NULL;
    *flags = (flags_t){
        .flags = flag_list,
        .loaded = 0,
        .size = 0,
        .max_size = size
    };
    return flags;
}

int flag_destroy(flags_t **flags)
{
    if (!flags || !*flags)
        return E_ERROR;
    for (size_t idx = 0; idx < (*flags)->size; idx++) {
        free_any((*flags)->flags[idx].name);
        free_any((*flags)->flags[idx].advanced);
        free_any((*flags)->flags[idx].value);
    }
    free_any((*flags)->flags);
    *flags = free_any(*flags);
    return E_SUCCESS;
}
