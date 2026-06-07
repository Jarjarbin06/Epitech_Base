/*
** EPITECH PROJECT, 2025
** NCSFML - New C Simple Fast Multimedia Library
** File description:
** •
** NSFML is a lightweight wrapper over CSFML that simplifies usage
** while reducing low-level flexibility for easier game development.
** •
** Version: ncsfml-v0.2.8
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

#include "newcsfml/games/game.h"
#include "newcsfml/systems/watcher.h"
#include "newcsfml/systems/other.h"
#include "newcsfml/systems/utils.h"

nsf_watcher_t *nsf_watcher_create(void *ptr, const nsf_watcher_type_t type,
    nsf_game_t *game)
{
    nsf_watcher_t *new_watcher = malloc_any(sizeof(nsf_watcher_t));

    if (NSF_UNLIKELY(!new_watcher))
        return nsf_utils_log_null(NSF_LOG_LVL_ERROR, NSF_WATCHER,
            __FUNCTION__, "alloc failed");
    new_watcher->ptr = ptr;
    new_watcher->type = type;
    if (game)
        game->allocations++;
    return new_watcher;
}

int nsf_watcher_destroy(nsf_watcher_t **watcher, nsf_game_t *game)
{
    if (NSF_UNLIKELY(!watcher || !*watcher))
        return nsf_utils_log_failure(NSF_LOG_LVL_ERROR, NSF_WATCHER,
            __FUNCTION__, "pointer corrupted");
    *watcher = free_any(*watcher);
    if (game)
        game->allocations--;
    return E_SUCCESS;
}
