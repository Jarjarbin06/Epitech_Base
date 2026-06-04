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
#include "newcsfml/systems/utils.h"
#include "newcsfml/games/game.h"

void nsf_game_add_screen(nsf_game_t *game, const nsf_cstr_t screen_name)
{
    if (NSF_UNLIKELY(!game || !screen_name))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_WINDOW, __FUNCTION__,
            "pointer corrupted");
    nsf_window_add_screen(game->window, screen_name);
}

int nsf_game_set_screen(nsf_game_t *game, const nsf_cstr_t screen_name)
{
    if (NSF_UNLIKELY(!game))
        return nsf_utils_log_error(NSF_LOG_LVL_ERROR, NSF_WINDOW, __FUNCTION__,
            "pointer corrupted");
    return nsf_window_set_screen(game->window, screen_name);
}
