/*
** EPITECH PROJECT, 2026
** EpitechBase - alloc_any.c
** File description:
** <description>
*/

#include <stdlib.h>

#include "../includes/utils.h"

void *utils_malloc(const unsigned size)
{
    void *alloc = malloc(size);

    if (!alloc)
        return NULL;
    return alloc;
}

void *utils_free(void *ptr)
{
    if (ptr)
        free(ptr);
    return NULL;
}

int utils_free_batch(const unsigned len, free_t free_list[])
{
    int freed = 0;
    void **ptr = NULL;

    for (int idx = 0; idx < (int)len; idx++)
        if (free_list[idx].condition) {
            ptr = (void **)free_list[idx].ptr;
            free_list[idx].free_func(*ptr);
            *ptr = NULL;
            freed++;
        }
    return freed;
}

void *utils_free_array(void **array)
{
    if (array)
        for (int idx = 0; array[idx]; idx++)
            utils_free(array[idx]);
    utils_free(array);
    return NULL;
}
