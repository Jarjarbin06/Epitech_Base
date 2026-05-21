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

#include "newcsfml/games/window.h"
#include "newcsfml/games/game.h"
#include "newcsfml/systems/utils.h"

int nsf_game_play_sound(const nsf_game_t *game,
    const char sound_name[])
{
    if (NSF_UNLIKELY(!game || !game->window || !sound_name))
        return nsf_utils_log_error(NSF_LOG_LVL_ERROR, NSF_GAME, __FUNCTION__,
            "pointer corrupted");
    nsf_window_play_sound(game->window, sound_name);
    return E_SUCCESS;
}

int nsf_game_pause_sound(const nsf_game_t *game,
    const char sound_name[])
{
    if (NSF_UNLIKELY(!game || !game->window || !sound_name))
        return nsf_utils_log_error(NSF_LOG_LVL_ERROR, NSF_GAME, __FUNCTION__,
            "pointer corrupted");
    nsf_window_pause_sound(game->window, sound_name);
    return E_SUCCESS;
}

int nsf_game_stop_sound(const nsf_game_t *game,
    const char sound_name[])
{
    if (NSF_UNLIKELY(!game || !game->window || !sound_name))
        return nsf_utils_log_error(NSF_LOG_LVL_ERROR, NSF_GAME, __FUNCTION__,
            "pointer corrupted");
    nsf_window_stop_sound(game->window, sound_name);
    return E_SUCCESS;
}

int nsf_game_all_sound_volume(const nsf_game_t *game,
    const float volume)
{
    if (NSF_UNLIKELY(!game || !game->window))
        return nsf_utils_log_error(NSF_LOG_LVL_ERROR, NSF_GAME, __FUNCTION__,
            "pointer corrupted");
    nsf_window_all_sound_volume(game->window, volume);
    return E_SUCCESS;
}

int nsf_game_stop_all_sound(const nsf_game_t *game)
{
    if (NSF_UNLIKELY(!game || !game->window))
        return nsf_utils_log_error(NSF_LOG_LVL_ERROR, NSF_GAME, __FUNCTION__,
            "pointer corrupted");
    nsf_window_stop_all_sound(game->window);
    return E_SUCCESS;
}
