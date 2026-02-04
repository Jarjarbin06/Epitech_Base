/*
** EPITECH PROJECT, 2026
** EpitechBase - alloc_any.c
** File description:
** <description>
*/

#include <stdlib.h>

#include "../../include/newcsfml.h"

void *malloc_any(const int size)
{
    void *alloc = malloc(size);

    if(!alloc)
        return NULL;
    return alloc;
}

void free_any(void *ptr)
{
    if (!ptr)
        return;
    free(ptr);
}

void auto_free(const int len, free_t free_list[])
{
    for (int idx = 0; idx < len; idx++) {
        if (free_list[idx].condition)
            free_any(free_list[idx].ptr);
    }
}
