/*
** EPITECH PROJECT, 2025
** NCSFML - New C Simple Fast Multimedia Library
** File description:
** •
** NSFML is a lightweight wrapper over CSFML that simplifies usage
** while reducing low-level flexibility for easier game development.
** •
** Version: ncsfml-v0.2.10
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

#include <SFML/System/Clock.h>

#include "newcsfml/games/game.h"
#include "newcsfml/systems/utils.h"
#include "newcsfml/systems/other.h"
#include "newcsfml/systems/clock.h"

nsf_clock_t *nsf_clock_create(const char name[], nsf_game_t *game)
{
    nsf_clock_t *new_clock = malloc_any(sizeof(nsf_clock_t));
    sfClock *sf_clock = sfClock_create();
    const nsf_cstr_t name_str = str_dup(name);

    if (NSF_UNLIKELY(!new_clock || !sf_clock || !name_str))
        return nsf_utils_log_null(NSF_LOG_LVL_ERROR, NSF_CLOCK,
            __FUNCTION__, "alloc failed");
    new_clock->clock = sf_clock;
    new_clock->name = name_str;
    new_clock->last = 0.0f;
    new_clock->delta = 0.0f;
    new_clock->accumulator = 0.0f;
    if (game)
        game->allocations += 3;
    return new_clock;
}

int nsf_clock_destroy(nsf_clock_t **clock, nsf_game_t *game)
{
    if (NSF_UNLIKELY(!clock || !*clock))
        return nsf_utils_log_failure(NSF_LOG_LVL_ERROR, NSF_CLOCK,
            __FUNCTION__, "pointer corrupted");
    if (NSF_LIKELY((*clock)->clock))
        sfClock_destroy((*clock)->clock);
    if (NSF_LIKELY((*clock)->name))
        free_any((nsf_str_t)(*clock)->name);
    *clock = free_any(*clock);
    if (game)
        game->allocations -= 3;
    return E_SUCCESS;
}
