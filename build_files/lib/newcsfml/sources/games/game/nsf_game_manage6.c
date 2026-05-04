/*
** EPITECH PROJECT, 2025
** NCSFML - New C Simple Fast Multimedia Library
** File description:
** •
** NSFML is a lightweight wrapper over CSFML that simplifies usage
** while reducing low-level flexibility for easier game development.
** •
** Version: ncsfml-v0.2.2
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

#include "newcsfml/games/window.h"
#include "newcsfml/games/game.h"
#include "newcsfml/systems/clock.h"
#include "newcsfml/systems/utils.h"

int nsf_game_update(const nsf_game_t *game)
{
    if (NSF_UNLIKELY(!game))
        return EXIT_ERROR;
    nsf_window_update_settings(nsf_game_get_window(game));
    if (game->clock)
        nsf_clock_update(game->clock);
    return EXIT_SUCCESS;
}
