/*
** EPITECH PROJECT, 2025
** NCSFML - New C Simple Fast Multimedia Library
** File description:
** •
** NSFML is a lightweight wrapper over CSFML that simplifies usage
** while reducing low-level flexibility for easier game development.
** •
** Version: ncsfml-v0.2.7
** Author: Jarjarbin06
** License: GPL v3
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

#include <SFML/System/Time.h>
#include <SFML/System/Sleep.h>

#include "newcsfml/graphics/background.h"
#include "newcsfml/games/window.h"
#include "newcsfml/systems/clock.h"
#include "newcsfml/games/game.h"
#include "newcsfml/games/window_settings.h"
#include "newcsfml/systems/utils.h"

void nsf_game_set_clock(nsf_game_t *game, nsf_clock_t *clock)
{
    if (NSF_UNLIKELY(!game || !clock))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_GAME, __FUNCTION__,
            "pointer corrupted");
    game->clock = clock;
}

const nsf_clock_t *nsf_game_get_clock(const nsf_game_t *game)
{
    if (NSF_UNLIKELY(!game))
        return nsf_utils_log_null(NSF_LOG_LVL_ERROR, NSF_GAME, __FUNCTION__,
            "pointer corrupted");
    return game->clock;
}

bool nsf_game_update_clock(nsf_game_t *game)
{
    float seconds = 0.0f;

    if (NSF_UNLIKELY(!game || !game->clock || !game->window ||
        !game->window->settings)) {
        nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_GAME, __FUNCTION__,
            "pointer corrupted");
        return true;
    }
    seconds = 1.0f / game->window->settings->fps;
    nsf_clock_update(game->clock);
    if (nsf_clock_is_new_loop(game->clock, seconds)) {
        nsf_clock_set_new_loop(game->clock, seconds);
        return true;
    }
    return false;
}

void nsf_game_wait_new_loop(nsf_game_t *game)
{
    if (NSF_UNLIKELY(!game || !game->clock || !game->window ||
        !game->window->settings))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_GAME, __FUNCTION__,
            "pointer corrupted");
    while (!nsf_game_update_clock(game))
        sfSleep(sfMilliseconds(1));
}
