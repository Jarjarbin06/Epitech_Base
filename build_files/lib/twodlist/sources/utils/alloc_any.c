/*
** EPITECH PROJECT, 2026
** EpitechBase - alloc_any.c
** File description:
** <description>
*/

#include <stdlib.h>

#include "../../includes/twodlist.h"

void *malloc_any(const unsigned size)
{
    void *alloc = malloc(size);

    if(!alloc)
        return NULL;
    return alloc;
}

void *free_any(void *ptr)
{
    if (ptr)
        free(ptr);
    return NULL;
}

bool auto_free(const unsigned len, free_t free_list[])
{
    bool free_done = false;

    for (int idx = 0; idx < (int)len; idx++)
        if (free_list[idx].condition) {
            free_list[idx].free_func(*(void **)free_list[idx].ptr);
            *(void **)free_list[idx].ptr = NULL;
            free_done = true;
        }
    return free_done;
}

void free_array(void **array)
{
    if (!array)
        return;
    for (int idx = 0; array[idx]; idx++)
        auto_free(1, (free_t[]){
            {array[idx], &array[idx], free_any}
        });
    auto_free(1, (free_t[]){
        {array, &array, free_any}
    });
}
