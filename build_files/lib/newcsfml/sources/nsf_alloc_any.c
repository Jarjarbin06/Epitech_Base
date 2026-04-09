/*
** EPITECH PROJECT, 2026
** EpitechBase - nsf_alloc_any.c
** File description:
** <description>
*/

#include <stdlib.h>

#include "../includes/newcsfml.h"

void *nsf_malloc_any(const nsf_uint_t size, nsf_game_t *game)
{
    void *alloc = malloc(size);

    if (!alloc)
        return NULL;
    if (game)
        game->allocations++;
    return alloc;
}

void *nsf_free_any(void *ptr, nsf_game_t *game)
{
    if (ptr) {
        free(ptr);
        if (game)
            game->allocations--;
    }
    return NULL;
}

int nsf_auto_free(const nsf_uint_t len, const free_t free_list[],
    nsf_game_t *game)
{
    int freed = 0;

    for (int idx = 0; idx < (int)len; idx++) {
        if (free_list[idx].condition) {
            free_list[idx].free_func(*(void **)free_list[idx].ptr);
            *(void **)free_list[idx].ptr = NULL;
            freed++;
        }
    }
    if (game)
        game->allocations -= freed;
    return freed;
}
