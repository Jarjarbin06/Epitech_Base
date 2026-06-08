/*
** EPITECH PROJECT, 2025
** NCSFML - New C Simple Fast Multimedia Library
** File description:
** •
** NSFML is a lightweight wrapper over CSFML that simplifies usage
** while reducing low-level flexibility for easier game development.
** •
** Version: ncsfml-v0.2.9
** Author: Jarjarbin06
** Licence: GPL v3
** •
** This library is inspired by SFML/CSFML and is designed for
** educational and game-development purposes.
** •
** It provides higher-level abstractions over CSFML to reduce
** boilerplate code and enforce safer usage patterns.
** •
** WARNING:
** This is NOT the original SFML/CSFML library.
** It is a custom implementation layer built on top of CSFML.
*/

#include <stdlib.h>

#include "newcsfml/games/game.h"
#include "newcsfml/systems/other.h"
#include "newcsfml/systems/utils.h"

void *nsf_utils_malloc(const nsf_uint_t size, nsf_game_t *game)
{
    void *alloc = malloc(size);

    if (NSF_UNLIKELY(!alloc))
        return nsf_utils_log_null(NSF_LOG_LVL_ERROR, NSF_UTILS,
            __FUNCTION__, "pointer corrupted");
    if (game)
        game->allocations++;
    return alloc;
}

void *nsf_utils_free(void *ptr, nsf_game_t *game)
{
    if (NSF_LIKELY(!ptr))
        return nsf_utils_log_null(NSF_LOG_LVL_ERROR, NSF_UTILS,
            __FUNCTION__, "pointer corrupted");
    free(ptr);
    if (game)
        game->allocations--;
    return NULL;
}

static void do_free(const nsf_free_t free_list[],
    int *freed)
{
    if (NSF_UNLIKELY(free_list->ptr && free_list->free_func)) {
        nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_UTILS,
            __FUNCTION__, "pointer corrupted");
        return;
    }
    if (free_list->condition) {
        ((void_func_t)free_list->free_func)(
            free_list->ptr
        );
        (*freed)++;
    }
}

int nsf_utils_free_batch(const nsf_uint_t len, const nsf_free_t free_list[],
    nsf_game_t *game)
{
    int freed = 0;

    if (NSF_UNLIKELY(!free_list))
        return nsf_utils_log_zero(NSF_LOG_LVL_ERROR, NSF_UTILS,
            __FUNCTION__, "pointer corrupted");
    for (size_t idx = 0; idx < len; idx++)
        do_free(&free_list[idx], &freed);
    if (game)
        game->allocations -= freed;
    return freed;
}

void *nsf_utils_free_array(void **array, nsf_game_t *game)
{
    if (NSF_LIKELY(!array))
        return nsf_utils_log_null(NSF_LOG_LVL_ERROR, NSF_UTILS,
            __FUNCTION__, "pointer corrupted");
    for (size_t idx = 0; array[idx]; idx++) {
        nsf_utils_free(array[idx], game);
    }
    nsf_utils_free(array, game);
    return NULL;
}
