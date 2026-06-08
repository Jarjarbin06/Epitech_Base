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

#include "newcsfml/games/window.h"
#include "newcsfml/games/game.h"
#include "newcsfml/systems/utils.h"

bool nsf_game_get_event(const nsf_game_t *game, nsf_event_t *event)
{
    if (NSF_UNLIKELY(!game || !game->window))
        return nsf_utils_log_false(NSF_LOG_LVL_ERROR, NSF_GAME, __FUNCTION__,
            "pointer corrupted");
    return nsf_window_get_event(game->window, event);
}

int nsf_game_display(const nsf_game_t *game)
{
    if (NSF_UNLIKELY(!game || !game->window))
        return nsf_utils_log_failure(NSF_LOG_LVL_ERROR, NSF_GAME, __FUNCTION__,
            "pointer corrupted");
    nsf_window_display(game->window);
    return E_SUCCESS;
}
