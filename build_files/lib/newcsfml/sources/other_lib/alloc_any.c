/*
** EPITECH PROJECT, 2026
** EpitechBase - alloc_any.c
** File description:
** <description>
*/

#include <stdlib.h>

#include "../../includes/newcsfml.h"

void *malloc_any(const unsigned size)
{
    void *alloc = malloc(size);

    if (!alloc)
        return NULL;
    return alloc;
}

void *free_any(void *ptr)
{
    if (ptr)
        free(ptr);
    return NULL;
}

int auto_free(const unsigned len, free_t free_list[])
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

void *free_array(void **array)
{
    if (array)
        for (int idx = 0; array[idx]; idx++)
            free_any(array[idx]);
    return free_any(array);
}
