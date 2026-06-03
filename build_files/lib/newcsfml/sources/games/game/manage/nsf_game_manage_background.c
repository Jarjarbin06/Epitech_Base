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

#include "newcsfml/graphics/background.h"
#include "newcsfml/games/window.h"
#include "newcsfml/games/game.h"
#include "newcsfml/systems/utils.h"

void nsf_game_set_background(const nsf_game_t *game,
    nsf_background_t *background)
{
    if (NSF_UNLIKELY(!game || !game->window || !background))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_GAME, __FUNCTION__,
            "pointer corrupted");
    nsf_window_set_background(game->window, background);
}

const nsf_background_t *nsf_game_get_background(const nsf_game_t *game)
{
    if (NSF_UNLIKELY(!game || !game->window))
        return nsf_utils_log_null(NSF_LOG_LVL_ERROR, NSF_GAME, __FUNCTION__,
            "pointer corrupted");
    return nsf_window_get_background(game->window);
}
