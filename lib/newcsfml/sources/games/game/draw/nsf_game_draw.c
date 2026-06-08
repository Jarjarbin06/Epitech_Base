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

#include "newcsfml/games/window.h"
#include "newcsfml/games/window_settings.h"
#include "newcsfml/games/game.h"
#include "newcsfml/systems/clock.h"
#include "newcsfml/systems/utils.h"

void nsf_game_fill(const nsf_game_t *game, const nsf_color_t color[])
{
    if (NSF_UNLIKELY(!game || !color))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_GAME, __FUNCTION__,
            "pointer corrupted");
    nsf_window_fill(game->window, color);
}

void nsf_game_draw(nsf_game_t *game)
{
    if (NSF_UNLIKELY(!game || !game->window))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_GAME, __FUNCTION__,
            "pointer corrupted");
    if (NSF_LIKELY(game->real_fps.clock)) {
        game->real_fps.draw_count++;
        if (nsf_clock_is_new_loop(game->real_fps.clock, 1.0f)) {
            game->real_fps.fps = (nsf_uint_t)((float)game->real_fps.draw_count /
                game->real_fps.clock->accumulator);
            game->real_fps.draw_count = 0;
            nsf_clock_set_new_loop(game->real_fps.clock, 1.0f);
        }
    }
    nsf_window_draw(game->window);
}
